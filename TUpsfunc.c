#include <stdio.h>
#include <stdlib.h>
#include <TUps.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>


/*The function below will take the PID entered by the user and parse the stat file and return the first value
 * which is listed as the PID*/
void parseStatFile(char* inPid) {

    char filename[1000];
    sprintf(filename, "/proc/%s/stat", inPid);
    FILE *pidStatFile = fopen(filename, "r");
    if (pidStatFile == NULL) {
        perror("error: pid not found or incorrect use of program\n"
               "\n"
               "Usage:\n"
               " TUps [#] [options]\n"
               "\n"
               " Try 'TUps'\n"
               "  or 'TUps -p ####(pid)'\n"
               "  or 'TUps -p ####(pid) -s -U -S -v -c");
        exit(EXIT_FAILURE);
    }


    int procPID, ppid, pgrp, session, tty_nr, tpgid, flags, minflt, cminflt, majflt, cmjflt, utime, stime, cutime,
            cstime, priority, nice, num_threads, itrealvalue, starttime, vsize, rss, rsslim, startcode, endcode, startstack,
            kstkesp, kstkeip, signal, blocked, sigignore, sigcatch, wchan, nswap, cnswap, exit_signal, processor, rt_priority,
            policy, delayacct_blkio_ticks, guest_time, cquest_time, start_data, end_data, start_brk, arg_start, arg_end,
            env_start, env_end, exit_code;
    char comm[1000], state;

    fscanf(pidStatFile,
           "%d (%[^)]%*[)] %c %d %d %d %d %d %d %d "
           "%d %d %d %d %d %d %d %d %d %d "
           "%d %d %d %d %d %d %d %d %d %d "
           "%d %d %d %d %d %d %d %d %d %d "
           "%d %d %d %d %d %d %d %d %d %d "
           "%d %d ", &procPID, comm, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt,
           &cminflt, &majflt, &cmjflt, &utime, &stime, &cutime, &cstime, &priority, &nice, &num_threads,
           &itrealvalue, &starttime, &vsize, &rss, &rsslim, &startcode, &endcode, &startstack, &kstkesp, &kstkeip,
           &signal, &blocked, &sigignore, &sigcatch, &wchan, &nswap, &cnswap, &exit_signal, &processor, &rt_priority,
           &policy, &delayacct_blkio_ticks, &guest_time, &cquest_time, &start_data, &end_data, &start_brk, &arg_start,
           &arg_end, &env_start, &env_end, &exit_code);
    printf("PID:%-6d ", procPID);

    fclose(pidStatFile);

}

/*The function below will take the PID entered by the user and parse the statm file and return the first value
 * which is listed as the vm size*/
void parseStatFileVMused(char* inPid) {

    char filename[1000];
    sprintf(filename, "/proc/%s/statm", inPid);
    FILE *pidStatFile = fopen(filename, "r");
    // The below has been commented out since it is not needed.  The -p function will determine if this is valid or not
//    if (pidStatFile == NULL) {
//
//        printf("PID Files not found");
//
//        exit(EXIT_FAILURE);
//    }

    int size;
    int resident;
    int shared;
    char text[30];
    int lib;
    int data;
    int dt;

    fscanf(pidStatFile, "%d %d %d %c %d %d %d ", &size, &resident, &shared, text, &lib, &data, &dt);
    printf("VmSize:%d ", size);

    fclose(pidStatFile);

}

/*The function below will take the PID entered by the user and parse the stat file and return the system time*/
void parseStatFileSystemtime(char* inPid) {

    char filename[1000];
    sprintf(filename, "/proc/%s/stat", inPid);
    FILE *pidStatFile = fopen(filename, "r");
//    if (pidStatFile == NULL) {
//
//        printf("PID Files not found");
//
//        exit(EXIT_FAILURE);
//    }

    int procPID, ppid, pgrp, session, tty_nr, tpgid, flags, minflt, cminflt, majflt, cmjflt, utime, stime, cutime,
            cstime, priority, nice, num_threads, itrealvalue, starttime, vsize, rss, rsslim, startcode, endcode, startstack,
            kstkesp, kstkeip, signal, blocked, sigignore, sigcatch, wchan, nswap, cnswap, exit_signal, processor, rt_priority,
            policy, delayacct_blkio_ticks, guest_time, cquest_time, start_data, end_data, start_brk, arg_start, arg_end,
            env_start, env_end, exit_code;
    char comm[1000], state;

    fscanf(pidStatFile, "%d (%[^)]%*[)] %c %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d ", &procPID, comm, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt,
           &cminflt, &majflt, &cmjflt, &utime, &stime, &cutime, &cstime, &priority, &nice, &num_threads,
           &itrealvalue, &starttime, &vsize, &rss, &rsslim, &startcode, &endcode, &startstack, &kstkesp, &kstkeip,
           &signal, &blocked, &sigignore, &sigcatch, &wchan, &nswap, &cnswap, &exit_signal, &processor, &rt_priority,
           &policy, &delayacct_blkio_ticks, &guest_time, &cquest_time, &start_data, &end_data, &start_brk, &arg_start,
           &arg_end, &env_start, &env_end, &exit_code);
    printf("sTime=%d ", stime);

    fclose(pidStatFile);


}

/*The function below will take the PID entered by the user and parse the stat file and return the user time*/
void parseStatFileUsertime(char* inPid) {

    char filename[1000];
    sprintf(filename, "/proc/%s/stat", inPid);
    FILE *pidStatFile = fopen(filename, "r");
//    if (pidStatFile == NULL) {
//
//        printf("PID Files not found");
//
//        exit(EXIT_FAILURE);
//    }

    int procPID, ppid, pgrp, session, tty_nr, tpgid, flags, minflt, cminflt, majflt, cmjflt, utime, stime, cutime,
            cstime, priority, nice, num_threads, itrealvalue, starttime, vsize, rss, rsslim, startcode, endcode, startstack,
            kstkesp, kstkeip, signal, blocked, sigignore, sigcatch, wchan, nswap, cnswap, exit_signal, processor, rt_priority,
            policy, delayacct_blkio_ticks, guest_time, cquest_time, start_data, end_data, start_brk, arg_start, arg_end,
            env_start, env_end, exit_code;
    char comm[1000], state;

    fscanf(pidStatFile, "%d (%[^)]%*[)] %c %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d ", &procPID, comm, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt,
           &cminflt, &majflt, &cmjflt, &utime, &stime, &cutime, &cstime, &priority, &nice, &num_threads,
           &itrealvalue, &starttime, &vsize, &rss, &rsslim, &startcode, &endcode, &startstack, &kstkesp, &kstkeip,
           &signal, &blocked, &sigignore, &sigcatch, &wchan, &nswap, &cnswap, &exit_signal, &processor, &rt_priority,
           &policy, &delayacct_blkio_ticks, &guest_time, &cquest_time, &start_data, &end_data, &start_brk, &arg_start,
           &arg_end, &env_start, &env_end, &exit_code);
    printf("uTime=%-5d ", utime);

    fclose(pidStatFile);

}

/*The function below will take the PID entered by the user and parse the stat file and return the state*/
void parseStatFileState(char* inPid) {

    char filename[1000];
    sprintf(filename, "/proc/%s/stat", inPid);
    FILE *pidStatFile = fopen(filename, "r");
//    if (pidStatFile == NULL) {
//
//        printf("PID Files not found");
//
//        exit(EXIT_FAILURE);
//    }

    int procPID, ppid, pgrp, session, tty_nr, tpgid, flags, minflt, cminflt, majflt, cmjflt, utime, stime, cutime,
    cstime, priority, nice, num_threads, itrealvalue, starttime, vsize, rss, rsslim, startcode, endcode, startstack,
    kstkesp, kstkeip, signal, blocked, sigignore, sigcatch, wchan, nswap, cnswap, exit_signal, processor, rt_priority,
    policy, delayacct_blkio_ticks, guest_time, cquest_time, start_data, end_data, start_brk, arg_start, arg_end,
    env_start, env_end, exit_code;
    char comm[1000], state;



    fscanf(pidStatFile, "%d (%[^)]%*[)] %c %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d %d %d %d %d %d %d %d %d "
                        "%d %d ", &procPID, comm, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt,
           &cminflt, &majflt, &cmjflt, &utime, &stime, &cutime, &cstime, &priority, &nice, &num_threads,
           &itrealvalue, &starttime, &vsize, &rss, &rsslim, &startcode, &endcode, &startstack, &kstkesp, &kstkeip,
           &signal, &blocked, &sigignore, &sigcatch, &wchan, &nswap, &cnswap, &exit_signal, &processor, &rt_priority,
           &policy, &delayacct_blkio_ticks, &guest_time, &cquest_time, &start_data, &end_data, &start_brk, &arg_start,
           &arg_end, &env_start, &env_end, &exit_code);
    printf("State:%c ", state);

    fclose(pidStatFile);

}

/*The function below will take the PID entered by the user and parse the cmdline file and return the complete cmdline*/
void parseCMDLINEproc(char* inPid) {

    char path[1000];
    sprintf(path, "/proc/%s/cmdline", inPid);

    FILE *cmdline = fopen(path, "rb");
    char *arg = 0;
    size_t size = 0;
    printf("[");
    while (getdelim(&arg, &size, 0, cmdline) != -1) { //WIll run until it matches delim char
        printf("%.100s ", arg);
    }
    printf("]");
    free(arg);
    fclose(cmdline);

}

/*If no -p flag is set, the function below will return the default values of the user available processes.*/
void printAllPidInfo() {

    DIR *proc = opendir("/proc");
    struct dirent *dir;

    if (proc == NULL) {
        perror("opendir(/proc)");

    }

    while ((dir = readdir(proc))) {
        if (!isdigit(*dir->d_name)){

        }

        print_status(dir->d_name);
    }

    closedir(proc);

}

void print_status(char* inPid) {
    char path[40], line[100];
    FILE *statusf;
    long int procUid;


    snprintf(path, 40, "/proc/%s/status", inPid);

    statusf = fopen(path, "r");
    if (!statusf)
        return;

    while (fgets(line, 100, statusf)) {
        if (strncmp(line, "Uid:", 4) != 0)
            continue;


        sscanf(line, "Uid:\t%lu\t", &procUid);


        if (procUid == 1000) {

            parseStatFile(inPid);
            parseStatFileUsertime(inPid);
            parseCMDLINEproc(inPid);
            printf("\n");

        }


    }

    fclose(statusf);

}