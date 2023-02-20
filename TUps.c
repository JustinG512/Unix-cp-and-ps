/* Justin Gallagher, 25JAN2022
Project 1: The /proc Filesystem
Due Feb 16 by 1pm Points 10 Submitting a file upload Available Jan 25 at 6pm - Apr 27 at 11:59pm 3 months
CIS 3207, Section 004 //Spring 2022 //Instructor: Professor Gene Kwatny


 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <TUps.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char *argv[]) {


    int opt;
    char *cPid;

    bool printp = false; // Print PID Default: OFF
    bool prints = false; // Print state Default: OFF
    bool printU = true; // Print userTime Default: ON
    bool printS = false; // Print systemTimeConsumed Default: OFF
    bool printv = false; // Print virtualMemoryConsumed Default: OFF
    bool printc = true; // Print cmdline Default: ON
    bool printAUP = true; // Print All user PID Default: ON

    /*The switch case below will turn on and off the flags needed to processed the requested output by the user*/
    while ((opt = getopt(argc, argv, ":p:sUSvc")) != -1) {

        switch (opt) {

            case 'p':
                /*Display process information only for the process whose number is pid. If this option is not present,
                 * then display information for all processes of the current user (and only of the current user).*/
                cPid = strdup(optarg);

                printp = true;
                printAUP = false;
                break;
            case ':':
                printf("-p option needs argument following (pid)\n");
                printAUP = false;
                exit(EXIT_FAILURE);
            case 's':
                /*Display the single-character state information about the process.*/
                prints = true;
                printAUP = false;
                break;
            case 'U':
                /*DO NOT Display the amount of user time consumed by this process.*/
                printU = false;
                printAUP = false;
                break;
            case 'S':
                /*Display the amount of system time consumed so far by this process.*/
                printS = true;
                printAUP = false;
                break;
            case 'v':
                /*Display the amount of virtual memory currently used (in pages) by this program.*/
                printv = true;
                printAUP = false;
                break;
            case 'c':
                /*DO NOT Display the command-line that started this program.*/
                printc = false;
                printAUP = false;
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                printAUP = false;
                break;
            default:
                printAUP = false;
                printf("error: pid not found or incorrect use of program\n"
                       "\n"
                       "Usage:\n"
                       " TUps [#] [options]\n"
                       "\n"
                       " Try 'TUps'\n"
                       "  or 'TUps -p ####(pid)'\n"
                       "  or 'TUps -p ####(pid) -s -U -S -v -c\n");
                exit(EXIT_FAILURE);

        }
    }

    // optind is for the extra arguments which are not parsed
    for (; optind < argc; optind++) {
        printf("extra arguments unknown: %s\n", argv[optind]);
        exit(EXIT_FAILURE);
    }

    /*The below IF statements will pass the cPid that has been enetered by the user into a series of functions.  These
     * will print out a line of text depending on what the user has enetered and what the program is expected to output.
     * There are two main cases with multiple cub-cases.  If the user has entered a found PID, or if the user has not
     * entered any PID.*/
    if (printAUP == true) {
        printAllPidInfo();
        exit(EXIT_SUCCESS);
    }

    if (printp == true) {
        parseStatFile(cPid); // Print the The process ID.
    }
    if (prints == true) {
        parseStatFileState(cPid); // Print the process state.
    }
    if (printU == true) {
        parseStatFileUsertime(cPid); // Print the time in user mode.
    }
    if (printS == true) {
        parseStatFileSystemtime(cPid); // Print time in kernel mode.
    }
    if (printv == true) {
        parseStatFileVMused(cPid); //. Print the total program size
    }
    if (printc == true) {
        parseCMDLINEproc(cPid); // Print the complete command line for the process
    }

    printf("\n");

    return 0;


}