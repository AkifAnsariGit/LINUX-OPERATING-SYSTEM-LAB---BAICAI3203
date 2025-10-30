#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void findTimes(struct Process p[], int n) {
    int total_wait = 0, total_tat = 0;
    p[0].waiting_time = 0;

    for (int i = 1; i < n; i++)
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;

    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_wait += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    printf("\nPID\tAT\tBT\tWT\tTAT");
    for (int i = 0; i < n; i++)
        printf("\nP%d\t%d\t%d\t%d\t%d", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);

    printf("\nAverage Waiting Time = %.2f", (float)total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n1, n2;

    printf("Enter number of processes in Queue 1 (High Priority): ");
    scanf("%d", &n1);
    struct Process q1[n1];

    printf("\nEnter details for Queue 1 processes:\n");
    for (int i = 0; i < n1; i++) {
        q1[i].pid = i + 1;
        printf("Arrival Time for P%d: ", i + 1);
        scanf("%d", &q1[i].arrival_time);
        printf("Burst Time for P%d: ", i + 1);
        scanf("%d", &q1[i].burst_time);
    }

    printf("\nEnter number of processes in Queue 2 (Low Priority): ");
    scanf("%d", &n2);
    struct Process q2[n2];

    printf("\nEnter details for Queue 2 processes:\n");
    for (int i = 0; i < n2; i++) {
        q2[i].pid = i + 1;
        printf("Arrival Time for P%d: ", i + 1);
        scanf("%d", &q2[i].arrival_time);
        printf("Burst Time for P%d: ", i + 1);
        scanf("%d", &q2[i].burst_time);
    }

    printf("\n--- Queue 1 (High Priority) Scheduling (FCFS) ---\n");
    findTimes(q1, n1);

    printf("\n--- Queue 2 (Low Priority) Scheduling (FCFS) ---\n");
    findTimes(q2, n2);

    printf("\nExecution Order: All Queue 1 processes -> then Queue 2 processes.\n");
    return 0;
}
