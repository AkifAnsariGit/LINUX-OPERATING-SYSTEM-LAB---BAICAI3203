#include <stdio.h>

struct Process {
    int id, at, bt, prio, ct, tat, wt, done;
};

int main() {
    int n, time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter AT, BT, Priority of P%d: ", p[i].id);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].prio);
        p[i].done = 0;
    }

    int completed = 0;
    while (completed < n) {
        int idx = -1, minPrio = 999;
        for (int i = 0; i < n; i++)
            if (p[i].done == 0 && p[i].at <= time && p[i].prio < minPrio) {
                minPrio = p[i].prio;
                idx = i;
            }

        if (idx != -1) {
            p[idx].ct = time + p[idx].bt;
            p[idx].done = 1;
            time += p[idx].bt;
            completed++;
        } else
            time++;
    }

    float totalTAT = 0, totalWT = 0;
    printf("PId\tAT\tBT\tPrio\tCT\tTAT\tWT");
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d", p[i].id, p[i].at, p[i].bt, p[i].prio, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Avg TAT = %.2f, Avg WT = %.2f", totalTAT / n, totalWT / n);
    return 0;
}
