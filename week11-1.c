#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter number of inputs: ");
    scanf("%d",&n);
    int *nums=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int disk,head;
    printf("Enter Head position: ");
    scanf("%d",&head);
    printf("Enter size of Disk: ");
    scanf("%d",&disk);
    int result=0;
    printf("\nSeek Sequence:\n");
    for(int i=0;i<n;i++){
        printf("%d-> ",nums[i]);
        result+=abs(head-nums[i]);
        head=nums[i];
    }
    printf("\nSeek Count=%d\n",result);
    return 0;
}
