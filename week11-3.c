#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int main(){
    int n;
    printf("Enter number of inputs: ");
    scanf("%d",&n);
    int *nums=(int*)malloc((n+2)*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int disk,head;
    printf("Enter size of Disk: ");
    scanf("%d",&disk);
    printf("Enter Head position: ");
    scanf("%d",&head);
    int dir=(nums[0]<head)?1:0; //1=left 0=right
    nums[n]=0;
    nums[n+1]=disk-1;
    n+=2;
    qsort(nums,n,sizeof(int),cmp);
    int pos=0;
    while(pos<n && nums[pos]<head) pos++;
    int result=0,cur=head;
    printf("\nSeek Sequence:\n");
    if(dir==0){
        for(int i=pos;i<n;i++){
            printf("%d-> ",nums[i]);
            result+=abs(cur-nums[i]);
            cur=nums[i];
        }
        result+=abs(disk-1-0);
        cur=0;
        for(int i=0;i<pos;i++){
            printf("%d-> ",nums[i]);
            result+=abs(cur-nums[i]);
            cur=nums[i];
        }
    }else{
        for(int i=pos-1;i>=0;i--){
            printf("%d-> ",nums[i]);
            result+=abs(cur-nums[i]);
            cur=nums[i];
        }
        result+=abs(cur-0)+abs(disk-1-0);
        cur=disk-1;
        for(int i=n-2;i>=pos;i--){
            printf("%d-> ",nums[i]);
            result+=abs(cur-nums[i]);
            cur=nums[i];
        }
    }
    printf("\nSeek Count=%d\n",result);
    free(nums);
    return 0;}
