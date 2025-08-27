#include<stdio.h> 
#include<stdbool.h> 
#include<limits.h> 

typedef struct process_struct 
{ 
 int pid; 
 int at; 
 int bt; 
 int ct,wt,tat,rt,start_time; 
} Process; 

int main()
{int n;
    scanf("%d",n);
    Process p[n];
    bool iscompleted[n];
    for(int i=0;i<n;i++)
    {
        iscompleted[i] = false;
    }
    bool isfirst = false;
    int curtime = 0, comp = 0;
    int sum_tat=0,sum_wt=0,sum_rt=0,total_idle_time=0,prev=0,length_cycle; 
    float cpu_utilization; 
    int max_completion_time,min_arrival_time; 
    for(int i=0; i<n; i++) 
    { 
        p[i].pid = i ;
        printf("\nEnter Process %d Arrival Time: ",i); 
        scanf("%d",&p[i].at);  
        printf("\nEnter Process %d Burst Time: ",i); 
        scanf("%d",&p[i].bt);
    } 
    while(comp!=n) 
    {
        
    }
}