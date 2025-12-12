#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main(){
    int n,disk,head;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    int *req=(int *)malloc((n+2)*sizeof(int));
    printf("Enter requests: ");
    for(int i=0;i<n;i++){
        scanf("%d", &req[i]);
    }
    printf("Enter disk size: ");
    scanf("%d", &disk);
    printf("Enter head position: ");
    scanf("%d", &head);
    int dir=(req[0]<head)?1:0; // 1 = left, 0 = right
    req[n]=0;
    req[n+1]=disk-1;
    n+=2;
    qsort(req, n, sizeof(int), cmp);
    int pos=0;
    while(pos<n && req[pos]<head){
        pos++;
    }
    int seek=0,cur=head;
    printf("\nSeek Sequence:\n");
    if(dir==0){
        for(int i=pos;i<n;i++){
            printf("%d-> ",req[i]);
            seek+=abs(cur-req[i]);
            cur=req[i];
        }
        for(int i=pos-1;i>=0;i--){
            printf("%d-> ",req[i]);
            seek+=abs(cur-req[i]);
            cur=req[i];
        }
    }
    else{
        for(int i=pos-1;i>=0;i--){
            printf("%d-> ",req[i]);
            seek+=abs(cur-req[i]);
            cur=req[i];
        }
        for(int i=pos;i<n;i++){
            printf("%d-> ",req[i]);
            seek+=abs(cur-req[i]);
            cur=req[i];
        }
    }
    printf("\nTotal Seek Count=%d\n", seek);
    return 0;
};