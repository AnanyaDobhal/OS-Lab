// 4. Write a program to implement Orphan and Zombie Process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void orphan_demo()
{
    int pid = fork();
    if (pid > 0)
    {
        // PARENT PROCESS
        printf("[ORPHAN DEMO] Parent Process (PID: %d) exiting...!!!\n", getpid());
        exit(0);
    }
    else if (pid == 0)
    {
        sleep(5);
        // CHILD PROCESS
        printf("[ORPHAN DEMO] CHILD PROCESS (PID: %d, New Parent PID: %d\n)", getpid(), getppid());
    }
    else
    {
        perror("Failed..!!");
        exit(1);
    }
}
void zombie_demo()
{
    int pid = fork();
    if (pid > 0)
    {
        printf("[ZOMBIE DEMO] Parent Process (PID: %d) sleeping..!!\n", getpid());
        sleep(20);
        printf("[ZOMBIE DEMO] Parent process exiting..!!\n");
    }
    else if (pid == 0)
    {
        printf("[ZOMBIE PROCESS] Child process (PID: %d) exiting..!!\n", getpid());
        exit(0);
    }
    else
    {
        // CHILD TERMINATES IMMEDIATELY
        perror("FAILED..!!");
        exit(1);
    }
}
int main()
{
    int choice;
    printf("PROCESS DEMO PROGRAM\n");
    printf("1. ORPHAN PROCESS\n");
    printf("2. ZOMBIE PROCESS\n");
    printf("Enter CHoice: ");
    scanf("%d", &choice);
    if (choice == 1)
        orphan_demo();
    else if (choice == 2)
        zombie_demo();
    else
        printf("INVALID CHOICE\n");
    return 0;
}