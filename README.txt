/**
* vSSH.cpp - Executable for the very simple shell
* program.
*
* @author Tim Davey
* @email daveytj206@potsdam.edu
* @date 10/24/2024
* @course CIS 310
* @due 10/30/2024
* @assignment pVSSH-a
*/

Problem: Utilize the exec() and fork() methods to create
a very simple shell program capable of executing commands 
from a given path, or searching a 'PATHS' directory.

Directory:
.
├── gradle
│   └── wrapper
│       ├── gradle-wrapper.jar
│       └── gradle-wrapper.properties
├── gradlew
├── gradlew.bat
├── README.txt
├── settings.gradle
└── vSSH
    ├── build
    │   ├── exe
    │   │   ├── main
    │   │   │   └── debug
    │   │   │       └── linux
    │   │   │           └── x86-64
    │   │   │               └── vSSH
    │   │   └── test
    │   │       └── linux
    │   │           └── x86-64
    │   │               └── vSSHTest
    │   ├── install
    │   │   ├── main
    │   │   │   └── debug
    │   │   │       └── linux
    │   │   │           └── x86-64
    │   │   │               ├── lib
    │   │   │               │   └── vSSH
    │   │   │               └── vSSH
    │   │   └── test
    │   │       └── linux
    │   │           └── x86-64
    │   │               ├── lib
    │   │               │   └── vSSHTest
    │   │               └── vSSHTest
    │   ├── obj
    │   │   ├── for-test
    │   │   │   └── main
    │   │   │       └── debug
    │   │   │           └── linux
    │   │   │               └── x86-64
    │   │   │                   └── vSSH.o
    │   │   ├── main
    │   │   │   └── debug
    │   │   │       └── linux
    │   │   │           └── x86-64
    │   │   │               └── 2vz75e8kek9zi53agdjepoedy
    │   │   │                   └── vSSH.o
    │   │   └── test
    │   │       └── linux
    │   │           └── x86-64
    │   │               └── b7kmhi9hyu1ccrdglzj5nalk5
    │   │                   └── vSSH_test.o
    │   ├── test-results
    │   │   └── test
    │   │       └── linux
    │   │           └── x86-64
    │   └── tmp
    │       ├── compileDebugLinuxX86-64Cpp
    │       │   ├── options.txt
    │       │   └── output.txt
    │       ├── compileTestLinuxX86-64Cpp
    │       │   ├── options.txt
    │       │   └── output.txt
    │       ├── linkDebugLinuxX86-64
    │       │   ├── options.txt
    │       │   └── output.txt
    │       └── linkTestLinuxX86-64
    │           ├── options.txt
    │           └── output.txt
    ├── build.gradle
    └── src
        ├── main
        │   ├── cpp
        │   │   └── vSSH.cpp
        │   └── headers
        │       └── vSSH.h
        └── test
            └── cpp
                └── vSSH_test.cpp

53 directories, 27 files

Compilation:
    gradle build

Run:
    Note: this program can only be run on Linux based operating systems.
    Note II: Path will vary based on operating system, it is recommended to paste the path 
    from your terminal window, instead of the example below.
    
    vSSH/build/exe/main/debug/linux/x86-64/vSSH

Testing:

Feature: Shell exits correctly
    Test: /home/csuser/src/pvSSH-a>>>exit
    Expected: csuser@os-server:~/src/pvSSH-a$ 
    Result: csuser@os-server:~/src/pvSSH-a$ 
Feature: Shell executes absolute path
    Test: /usr/bin/ls -l
    Expected: 
        total 36
        drwxrwxr-x 3 davey davey 4096 Oct 28 17:00 gradle
        -rw-rw-r-- 1 davey davey 8639 Oct 28  2024 gradlew
        -rw-rw-r-- 1 davey davey 2868 Oct 28  2024 gradlew.bat
        -rw-rw-r-- 1 davey davey 7118 Oct 28  2024 README.txt
        -rw-rw-r-- 1 davey davey  359 Oct 28  2024 settings.gradle
        drwxrwxr-x 4 davey davey 4096 Oct 28 20:04 vSSH
    Result:
        total 36
        drwxrwxr-x 3 davey davey 4096 Oct 28 17:00 gradle
        -rw-rw-r-- 1 davey davey 8639 Oct 28  2024 gradlew
        -rw-rw-r-- 1 davey davey 2868 Oct 28  2024 gradlew.bat
        -rw-rw-r-- 1 davey davey 7118 Oct 28  2024 README.txt
        -rw-rw-r-- 1 davey davey  359 Oct 28  2024 settings.gradle
        drwxrwxr-x 4 davey davey 4096 Oct 28 20:04 vSSH
Feature: Shell executes relative path
    Test: /home/davey/pvSSH-a>>>../../../usr/bin/ls
    Expected: 
        gradle	gradlew  gradlew.bat  README.txt  settings.gradle  vSSH
    Result:
        gradle	gradlew  gradlew.bat  README.txt  settings.gradle  vSSH
Feature: Shell handles multiple arguments passed
    Note: This output can never be exact since I'm calling grep on this file.
    Test: grep -i word /home/csuser/src/pvSSH-a/README.txt
    Expected: word
    Result: word
Feature: Shell can search 'PATHS' directory
    Test: which ls
    Expected: /usr/bin/ls
    Result: /usr/bin/ls
Feature: Shell can execute multiple different programs sequentially
    Test: 
        grep -i word /home/csuser/src/pvSSH-a/README.txt
        which ls
        ls -l
    Expected:
        Expected: word
        Result: word 
        /usr/bin/ls
        drwxrwx--- 1 root vboxsf 4096 Oct 25 16:30 gradle
        -rwxrwx--- 1 root vboxsf 8639 Oct 25 16:30 gradlew
        -rwxrwx--- 1 root vboxsf 2868 Oct 25 16:30 gradlew.bat
        -rwxrwx--- 1 root v        Expected: word
        Result: word 
        /usr/bin/ls
        drwxrwx--- 1 root vboxsf 4096 Oct 25 16:30 gradle
        -rwxrwx--- 1 root vboxsf 8639 Oct 25 16:30 gradlew
        -rwxrwx--- 1 root vboxsf 2868 Oct 25 16:30 gradlew.bat
        -rwxrwx--- 1 root vboxsf 4832 Oct 28 17:10 README.txt
        -rwxrwx--- 1 root vboxsf  359 Oct 25 16:30 settings.gradle
        drwxrwx--- 1 root vboxsf 4096 Oct 28 16:55 vSSHboxsf 4832 Oct 28 17:10 README.txt
        -rwxrwx--- 1 root vboxsf  359 Oct 25 16:30 settings.gradle
        drwxrwx--- 1 root vboxsf 4096 Oct 28 16:55 vSSH
    Result: 
        Expected: word
        Result: word 
        /usr/bin/ls
        drwxrwx--- 1 root vboxsf 4096 Oct 25 16:30 gradle
        -rwxrwx--- 1 root vboxsf 8639 Oct 25 16:30 gradlew
        -rwxrwx--- 1 root vboxsf 2868 Oct 25 16:30 gradlew.bat
        -rwxrwx--- 1 root vboxsf 4832 Oct 28 17:10 README.txt
        -rwxrwx--- 1 root vboxsf  359 Oct 25 16:30 settings.gradle
        drwxrwx--- 1 root vboxsf 4096 Oct 28 16:55 vSSH

Feature: Outputs Return Code on bad arguments
    Test: /home/csuser/src/pvSSH-a>>>ls also not a good call
    Expected: 
        ls: cannot access 'also': No such file or directory
        ls: cannot access 'not': No such file or directory
        ls: cannot access 'a': No such file or directory
        ls: cannot access 'good': No such file or directory
        ls: cannot access 'call': No such file or directory
        Return Code: 2
    Result:
        ls: cannot access 'also': No such file or directory
        ls: cannot access 'not': No such file or directory
        ls: cannot access 'a': No such file or directory
        ls: cannot access 'good': No such file or directory
        ls: cannot access 'call': No such file or directory
        Return Code: 2

Feature: Shell handles commands that don't exist   
    Test: /home/davey/pvSSH-a>>>ks

    Expected: 
        Command: ks not found!
        Return Code: 1
    
    Output:
        Command: ks not found!
        Return Code: 1