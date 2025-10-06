#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Resources
{
    int A,B,C;
}Resource;


int main()
{
    int p;
    int ta,tb,tc;
    int ava=0,avb=0,avc=0;
    printf("Enter total process:\n");
    scanf("%d",&p);
    Resource MaxNeed[p],allocated[p],remaining[p],available[p];
    bool iscompleted[p];
    printf("Enter maximum Requirement: \n");
    for(int i=0;i<p;i++)
    {
        iscompleted[i] = false;
        scanf("%d %d %d",&MaxNeed[i].A, &MaxNeed[i].B, &MaxNeed[i].C);
    }

    printf("Enter allocated matrix: \n");
    for(int i=0;i<p;i++)
    {
        scanf("%d %d %d",&allocated[i].A, &allocated[i].B, &allocated[i].C);
        ava += allocated[i].A;
        avb += allocated[i].B;
        avc += allocated[i].C;
    }

    printf("Total Resource: ");
    scanf("%d %d %d", &ta,&tb,&tc);

    for(int i=0;i<p;i++)
    {
        remaining[i].A = MaxNeed[i].A - allocated[i].A;
        remaining[i].B = MaxNeed[i].B - allocated[i].B;
        remaining[i].C = MaxNeed[i].C - allocated[i].C;
    }

    ava = ta-ava;
    avb = tb-avb;
    avc = tc-avc;
    int gantt[p];
    int ind = 0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(remaining[j].A <= ava && remaining[j].B <= avb && remaining[j].C <= avc && iscompleted[j] == 0)
            {
                ava = ava + allocated[j].A;
                avb = avb + allocated[j].B;
                avc = avc + allocated[j].C;
                iscompleted[j] = true;
                gantt[ind] = j;
                ind++;
                available[j].A = ava;
                available[j].B = avb;
                available[j].C = avc;
            }
        }
    }
    if(ind == p)
    {
         printf("Request can be fulfilled\nSafe Sequence: ");
        for(int i=0;i<p;i++)
        {
            printf("p%d ",gantt[i]);
        }
        for (int i = 0; i < p; i++)
        {
            printf("P%d\t%d %d %d\t\t%d %d %d\t\t%d %d %d\t%d %d %d\n", i, allocated[i].A, allocated[i].B, allocated[i].C, MaxNeed[i].A, MaxNeed[i].B, MaxNeed[i].C, remaining[i].A, remaining[i].B, remaining[i].C, available[i].A, available[i].B, available[i].C);
        }
    }
    else {
        printf("Request cannot be fulfilled (Deadlock possible)\n");
    }
    return 0;
}