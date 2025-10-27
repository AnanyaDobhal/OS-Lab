#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<stdlib.h>

int main()
{
    int p,m;
    printf("Enter number of free blocks available : ");
    scanf("%d",&m);
    int *memory = (int*)malloc(m*sizeof(int));
    printf("Enter SIZE OF each free blocks : ");
    for(int i=0;i<m;i++){
        scanf("%d",&memory[i]);
    }

    printf("Enter number of processes : ");
    scanf("%d",&p);
    int *process = (int*)malloc(p*sizeof(int));
    printf("Enter size of processes : ");
    for(int i=0;i<p;i++){
        scanf("%d",&process[i]);
    }
    bool *allocated = (bool*)malloc(m*sizeof(bool));
    for(int i=0;i<m;i++) allocated[i] = false;
    int *result = (int*)malloc(p*sizeof(int));
    for(int i=0;i<m;i++) result[i] = -1;

    for(int i=0;i<p;i++)
    {
        int pro = process[i];
        for(int j=0;j<m;j++){
            if(memory[j]>pro && allocated[j] == false){
                allocated[j] = true;
                result[i] = j+1;
                break;
            }
        }
    }
    for(int i=0;i<p;i++){
        printf("%d : %d\n",process[i], result[i]);
    }
}