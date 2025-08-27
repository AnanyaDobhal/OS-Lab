#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int x=fork();
    if(x==0) {
        printf("child is created with id %d\n",getpid());
    }
    else if( x < 0) {
        printf("child not created");
    }
    else {
        printf("parent created with ID: %d\n",getppid());
    }

    return 0;
}
