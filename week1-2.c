#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int x = fork();
    if(x<0){
        printf("Failed to create Process\n");
        return 1;
    }
    else if(x == 0){    //child Process
        printf("This is child Process....\n");
        printf("Child Process ID: %d\n",getpid());
        printf("Parent Process ID: %d\n",getppid());
    }
    else{   //parent Process
        printf("This is Parent Process....\n");
        printf("Parent Process ID: %d\n",getppid());
        printf("Child Process ID: %d\n",getpid());
    }
    return 0;
}