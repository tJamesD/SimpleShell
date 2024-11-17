#ifndef vSSH_H
#define vSSH_H

#include <string>
#include <vector>
using namespace std;

/**
 * Header for vSSH
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

/**
 * Shell Loop
 *
 * Starts the shell loop.
 * @post shell has been executed.
 */
void shellLoop();

/**
 * Space Parser
 *
 * Separates given parameter at each space, storing
 * each string in a vector.
 *
 * @post command has been separated by spaces.
 * @param cmd The line to parse
 * @return A vector of strings that were parsed
 */
vector<string> parseSpaces(string cmd);

/**
 * Vector to C-Array Converter
 *
 * Converts a given vector into a cstyle array
 *
 * @post c-style array returned.
 * @param size Size of the vector
 * @param parsePathVector Vector to be converted
 * @return char** An array of pointers to c-strings
 */
char **vecToCArr(int size, vector<string> parsePathVector);

#endif
