#include<stdio.h>
#include<unistd.h>

int find(int pages[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (pages[i] == key)
            return 1;
    return 0;
}

void fifo(int n,int nreq, int pages[])
{
     int memory[n];
    int front = 0,count=0,pagef =0;
    for(int i=0;i<n;i++)
    {
        memory[i] = -1;
    }

    for(int i=0;i<nreq;i++)
    {
        int page = pages[i];

        if(!find(memory,count,page))
        {
            memory[front] = page;
            front = (front+1) %n;
            if(count<n)
            {
                count++;
            }
            pagef++;
            printf("page %d caused a page fault. memory: ",page);
        }
        else{
            printf("page %d already in memory. memory: ",page);
        }
        for(int j=0;j<count;j++)
        {
            printf("%d ",memory[j]);
        }
        printf("\n");
    }
    printf("Total number of page faults: %d\n", pagef);
}

void lru(int n,int nreq, int pages[])
{
    int memory[n];
    int indx[n];
    int count = 0,pagef=0;
    for(int i=0;i<n;i++)
    {
        memory[i] = -1;   
        indx[i] = -1;
    }
    for(int i=0;i<nreq;i++)
    {
        int page = pages[i];
        if(!find(memory,count,page))
        {
            pagef++;
            if(count<n)
            {
                indx[count] = i;
                memory[count] = page;
                count++;
            }
            else{
                int mini = 0;
                for(int k=1;k<n;k++)
                {
                    if(indx[k]<indx[mini]){
                        mini = k;
                    }
                }
                memory[mini] = page;
                indx[mini] = i;
            }
        }
        else{
            for(int k=0;k<count;k++)
            {
                if(memory[k] == page){
                    indx[k] = i;
                    break;
                }
            }
        }
        for(int j=0;j<count;j++)
        {
            printf("%d ",memory[j]);
        }
        printf("\n");
    }
    printf("Total number of page faults: %d\n", pagef);
}

int main()
{
    int n;
    printf("Enter number of frames available :");
    scanf("%d",&n);
    int nreq;
    printf("Enter number of requests :");
    scanf("%d",&nreq);
    int pages[nreq];
    printf("Enter page numbers: ");
    for(int i=0;i<nreq;i++)
    {
       scanf("%d",&pages[i]);
    }
    //fifo(n,nreq,pages);
    lru(n,nreq,pages);
}