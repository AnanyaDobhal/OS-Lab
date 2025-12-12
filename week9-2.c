#include <stdio.h>
#include <string.h>
struct file{
    char name[10];
    int start,len,blocks[50],link[50];
};
int main(){
    int n,i,j;
    struct file f[10];
    char search[10];
    printf("Enter number of files: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter file %d name: ",i+1);
        scanf("%s",f[i].name);
        printf("Enter starting block of file %d: ",i+1);
        scanf("%d",&f[i].start);
        printf("Enter no of blocks in file %d: ",i+1);
        scanf("%d",&f[i].len);
        printf("Enter block numbers of file %d: ",i+1);
        for(j=0;j<f[i].len;j++){
            scanf("%d",&f[i].blocks[j]);
            if(j>0) f[i].link[j-1]=f[i].blocks[j];
        }
        f[i].link[f[i].len-1]=-1;
    }
    printf("Enter file name to be searched: ");
    scanf("%s",search);
    for(i=0;i<n;i++){
        if(strcmp(f[i].name,search)==0){
            printf("File Name\tStart block\tNo. of blocks\tBlocks occupied (linked)\n");
            printf("%s\t\t%d\t\t%d\t\t",f[i].name,f[i].start,f[i].len);
            for(j=0;j<f[i].len;j++){printf("%d->",f[i].blocks[j]);}
            printf("NULL\n");
            return 0;
        }
    }
    printf("File not found\n");
    return 0;
}
