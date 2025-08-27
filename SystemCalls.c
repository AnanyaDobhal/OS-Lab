#include<stdio.h>               //Provides functions for standard input and output (e.g., printf, scanf, perror).
#include<stdlib.h>              //Provides general-purpose functions for memory allocation, process control, conversions, etc. eg.exit(int status)
#include<unistd.h>              //Declares many UNIX system calls like fork(), read(), write(), close(), execl(), and pipe()   .
#include<fcntl.h>               //Contains constants and declarations for file control system calls like open() and fcntl().
#include<sys/wait.h>            //Declares macros and functions for process waiting. In our program:wait(NULL) → makes the parent process wait until the child finishes execution.


