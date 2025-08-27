#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process_struct {
    int pid;
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int wt;   // Waiting Time
    int tat;  // Turn Around Time
    int rt;   // Response Time
    int start_time;
    int remaining_bt;
} ps[100];

int findmax(int a, int b) {
    return a > b ? a : b;
}

int findmin(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    bool is_completed[100] = {false};
    int current_time = 0;
    int completed = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    int sum_tat = 0, sum_wt = 0, sum_rt = 0, total_idle_time = 0, prev = 0, length_cycle;
    float cpu_utilization;
    int max_completion_time, min_arrival_time;

    // Input Arrival Times
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d Arrival Time: ", i);
        scanf("%d", &ps[i].at);
        ps[i].pid = i;
    }

    // Input Burst Times
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d Burst Time: ", i);
        scanf("%d", &ps[i].bt);
        ps[i].remaining_bt = ps[i].bt;
    }

    // Scheduling loop
    while (completed != n) {
        int min_index = -1;
        int minimum = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (ps[i].at <= current_time && is_completed[i] == false) {
                if (ps[i].remaining_bt < minimum && ps[i].remaining_bt > 0) {
                    minimum = ps[i].remaining_bt;
                    min_index = i;
                }
                if (ps[i].remaining_bt == minimum) {
                    if (ps[i].at < ps[min_index].at) {
                        minimum = ps[i].remaining_bt;
                        min_index = i;
                    }
                }
            }
        }

        if (min_index == -1) {
            current_time++;
        } else {
            if (ps[min_index].remaining_bt == ps[min_index].bt) {
                ps[min_index].start_time = current_time;
                ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;
                total_idle_time += (completed == 0) ? 0 : (ps[min_index].start_time - prev);
            }

            ps[min_index].remaining_bt--;
            current_time++;
            prev = current_time;

            if (ps[min_index].remaining_bt == 0) {
                ps[min_index].ct = current_time;
                ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
                ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;

                sum_tat += ps[min_index].tat;
                sum_wt += ps[min_index].wt;
                sum_rt += ps[min_index].rt;

                completed++;
                is_completed[min_index] = true;
            }
        }
    }

    // Calculate Length of Process completion cycle
    max_completion_time = INT_MIN;
    min_arrival_time = INT_MAX;
    for (int i = 0; i < n; i++) {
        max_completion_time = findmax(max_completion_time, ps[i].ct);
        min_arrival_time = findmin(min_arrival_time, ps[i].at);
    }
    length_cycle = max_completion_time - min_arrival_time;

    // Output
    printf("\nProcess No.\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
               ps[i].pid, ps[i].at, ps[i].bt,
               ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    }

    cpu_utilization = (float)(length_cycle - total_idle_time) / length_cycle;

    printf("\nAverage Turn Around Time = %.2f", (float)sum_tat / n);
    printf("\nAverage Waiting Time     = %.2f", (float)sum_wt / n);
    printf("\nAverage Response Time    = %.2f", (float)sum_rt / n);
    printf("\nThroughput               = %.2f", n / (float)length_cycle);
    printf("\nCPU Utilization(%%)       = %.2f\n", cpu_utilization * 100);

    return 0;
}
