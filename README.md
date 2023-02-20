# Project_1_sp22_29794

### Installation

Installation is not needed for this program to run.  Please run application directly from the folder.

```
>./TUcp (-options)
```

### Usage/Design

```c
>'-p PID(####)' -- Display process information only for the process whose number is pid. If this option is not present, 
then display information for all processes of the current user (and only of the current user).

>'-s' -- Display the single-character state information about the process.

>'-S' -- Display the amount of system time consumed so far by this process.

>'-U' -- Hide the amount of user time consumed by this process.

>'-c' -- Hide the command-line that started this program.

>'-v' -- Display the amount of virtual memory currently used (in pages) by this program.
```

### Examples

```c
>Input: ./TUps -p 1234 -s -S -v
>Output: PID:1234  State:S uTime=4     sTime=3 VmSize:2685 [theCompleteCommandLineForTheProcess]

>Input: ./TUps
>Output: (List of all currently running user processes)

>Input: ./TUps -p 1234 -U -c
>Output: PID:1234
```

### Test Plan
For this assignment, I decided to use bool flags to display the different output.  This way, I would be
able to let the user decide what order they would like to enter the options in.  For the majority of the
program functionality, I wanted to use to be able to put one of the options
> ./TUps (or.) ./TUps - p 1234

The option flags included -s -U -S, which is information that can be foudn in the stat file, -v, which is 
information that can be found in the statm file, and the default value of -c which can be found in the 
cmdline file. The nature of the program will print the uTime and cmdline fields by default and accept the 
other flags based off the input by the user.  Since the output will always be in this order 
(-p -s -U -S -v -c), the user will be able to turn off or on any of the options and the print format will 
be the same. 

After the values were compared to each one of the requested fields, the testing was completed by attempting
to enter multiple and different values and flags that would either pass or fail the requirements of the program 
itself.  Each function could be tested individually this way with each return value from the function itself. 

### License
For more information, contact Justin M. Gallagher (tup29794@temple.edu)