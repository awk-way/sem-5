#include <stdio.h>
#define MAX 20

struct process {
    char name[10];
    int at, bt, st, wt, tat, ct, remaining;
};

void sortByArrival(struct process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct process p[MAX];
    int n, startTime;
    float awt = 0, atat = 0;

    printf("\nEnter the starting time: ");
    scanf("%d", &startTime);

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter process name, arrival time and burst time: ");
        scanf("%s%d%d", p[i].name, &p[i].at, &p[i].bt);
        p[i].remaining = p[i].bt;
    }

    sortByArrival(p, n);

    int completed = 0, currentTime = startTime, prev = -1;
    int ganttProcess[MAX * 50], ganttTime[MAX * 50], index = 0;

    while (completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && p[i].remaining > 0) {
                if (p[i].remaining < min_bt) {
                    min_bt = p[i].remaining;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            if (prev != idx) {
                ganttProcess[index] = idx;
                ganttTime[index] = currentTime;
                index++;
                p[idx].st = (p[idx].bt == p[idx].remaining) ? currentTime : p[idx].st;
            }

            p[idx].remaining--;
            currentTime++;
            if (p[idx].remaining == 0) {
                p[idx].ct = currentTime;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                awt += p[idx].wt;
                atat += p[idx].tat;
                completed++;
            }
            prev = idx;
        } else {
            if (prev != -2) {
                ganttProcess[index] = -2; 
                ganttTime[index] = currentTime;
                index++;
            }
            currentTime++;
            prev = -2;
        }
    }

    ganttTime[index] = currentTime;
    printf("\nGantt Chart:\n");
    for (int i = 0; i < index; i++) printf("-------");
    printf("-\n|");

    for (int i = 0; i < index; i++) {
        if (ganttProcess[i] == -2)
            printf("      |");
        else
            printf("  %s  |", p[ganttProcess[i]].name);
    }
    printf("\n");
    for (int i = 0; i < index; i++) printf("-------");
    printf("-\n");

    for (int i = 0; i <= index; i++) {
        printf("%-7d", ganttTime[i]);
    }

    printf("\n\n%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
           "Process", "AT", "BT", "ST", "CT", "TAT", "WT");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-10d %-10d %-10d %-10d %-10d %-10d\n",
               p[i].name, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);

    return 0;
}