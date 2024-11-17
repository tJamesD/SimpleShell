#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include <vector>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include "vSSH.h"
using namespace std;

/**
 * Main for vSSH
 *
 * Program that acts as a very simple shell.
 *
 * @author Tim Davey
 * @email daveytj206@potsdam.edu
 * @date 10/24/2024
 * @course CIS 310
 * @due 10/30/2024
 * @assignment pVSSH-a
 */
int main()
{
    shellLoop();
    return 0;
}

/**
 * Shell Loop
 */
void shellLoop()
{
    string cmdLine = "";

    while (cmdLine.compare("exit") != 0)
    {
        // Prompt
        filesystem::path currentPath = filesystem::current_path();
        cout << currentPath.string() << ">>>";

        getline(cin, cmdLine);

        if (cmdLine.compare("exit") == 0)
        {
            return;
        }

        vector<string> parsedPath = parseSpaces(cmdLine);

        // Construct C array
        int pathPartsSize = parsedPath.size();
        char **parsePathArr = vecToCArr(pathPartsSize, parsedPath);

        string cmd = parsePathArr[0];
        bool absPath = (cmd.find("/") != string::npos);

        //'PATHS' Vector
        vector<string> pathVec = {".", "/usr/local/bin", "/usr/bin", "/bin"};

        // Run the command
        pid_t pid = fork();
        bool found;
        if (pid == 0)
        {
            if (!absPath)
            {
                int value;
                for (const string &dir : pathVec)
                {
                    string fullPath = dir + "/" + cmd;

                    // Check for existance of command
                    if (access(fullPath.c_str(), F_OK) == -1)
                    {
                        found = false;
                        continue;
                    }

                    found = true;
                    value = execv(fullPath.c_str(), parsePathArr);

                    if (value == -1)
                    {
                        for (int i = 0; parsePathArr[i] != nullptr; ++i)
                        {
                            delete[] parsePathArr[i];
                        }
                        delete[] parsePathArr;
                        exit(EXIT_FAILURE);
                    }
                }
                if (value == -1 || !found)
                {
                    for (int i = 0; parsePathArr[i] != nullptr; ++i)
                    {
                        delete[] parsePathArr[i];
                    }
                    delete[] parsePathArr;

                    if (!found)
                    {
                        cout << "Command: " << cmd << " not found!" << endl;
                    }

                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                int value = execv(cmd.c_str(), parsePathArr);
                if (value == -1)
                {
                    for (int i = 0; parsePathArr[i] != nullptr; ++i)
                    {
                        delete[] parsePathArr[i];
                    }
                    delete[] parsePathArr;
                    exit(EXIT_FAILURE);
                }
            }
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);

            for (int i = 0; parsePathArr[i] != nullptr; ++i)
            {
                delete[] parsePathArr[i];
            }
            delete[] parsePathArr;

            if (WIFEXITED(status))
            {
                int returnCode = WEXITSTATUS(status);
                if (returnCode != 0)
                {
                    cout << "Return Code: " << returnCode << endl;
                }
            }
        }
    }
}
/**
 * Parse Spaces
 */
vector<string> parseSpaces(string cmd)
{
    stringstream stringStream(cmd);
    vector<string> pathParts;
    string pathPart;

    while (getline(stringStream, pathPart, ' '))
    {
        pathParts.push_back(pathPart);
    }

    return pathParts;
}

/**
 * Vector to C Array
 */
char **vecToCArr(int size, vector<string> parsePathVector)
{
    char **parsePathArr = new char *[size + 1];

    for (int i = 0; i < size; i++)
    {
        parsePathArr[i] = new char[parsePathVector[i].size() + 1];
        strcpy(parsePathArr[i], parsePathVector[i].c_str());
    }

    parsePathArr[size] = nullptr;
    return parsePathArr;
}
