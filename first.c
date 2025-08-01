#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int x=fork();
    printf("%d\n",getpid());
    printf("%d\n",getppid());
    return 0;
}