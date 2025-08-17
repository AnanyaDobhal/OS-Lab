#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int at;     // Arrival Time
    int bt;     // Burst Time
    int ct;     // Completion Time
    float tat;  // Turn Around Time
    float wt;   // Waiting Time
    int rt;     // Response Time
    int st;     // Start Time
};

int compare(const void *p1, const void *p2) {
    int a = ((struct Process *)p1)->at;
    int b = ((struct Process *)p2)->at;

    if (a < b)
        return -1;
    else
        return 1;
}

int main() {
    int n;
    float swt = 0, stat = 0;
    float cu = 0, throughput = 0;
    float awt = 0, atat = 0;
    int sbt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("\nFor Process %d\n", i + 1);
        p[i].pid = i + 1;

        printf("Enter the value of AT and BT: ");
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    qsort((void *)p, n, sizeof(struct Process), compare);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            p[i].ct = p[i].at + p[i].bt;
            p[i].st = p[i].at;
        } else if (p[i - 1].ct <= p[i].at) {
            p[i].ct = p[i].at + p[i].bt;
            p[i].st = p[i].at;
        } else {
            p[i].st = p[i - 1].ct;
            p[i].ct = p[i - 1].ct + p[i].bt;
        }

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        p[i].rt = p[i].wt;

        sbt += p[i].bt;
        swt += p[i].wt;
        stat += p[i].tat;
    }

    awt = swt / n;
    atat = stat / n;

    float max = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].ct > max) {
            max = p[i].ct;
        }
    }

    cu = ((float)sbt / max) * 100;   // CPU utilization
    throughput = (float)n / max;

    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].st,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    printf("\nSum of Turn Around Time: %.2f\nAverage of Turn Around Time: %.2f\n", stat, atat);
    printf("Sum of Waiting Time: %.2f\nAverage of Waiting Time: %.2f\n", swt, awt);
    printf("CPU utilization is: %.2f%%\nThroughput: %.2f\n", cu, throughput);

    return 0;
}
