#include <stdio.h>
#include <string.h>
#define MAX 20

struct process {
    char name[10];
    int at, bt, rt, st, wt, tat, ct, completed;
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
    int n, tq, startTime;
    float awt = 0, atat = 0;

    printf("\nEnter the starting time: ");
    scanf("%d", &startTime);
    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter process name, arrival time and burst time: ");
        scanf("%s%d%d", p[i].name, &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].completed = 0;
    }

    printf("\nEnter the Time Quantum: ");
    scanf("%d", &tq);

    sortByArrival(p, n);

    int currentTime = startTime, completed = 0, queue[MAX], front = 0, rear = 0, visited[MAX] = {0};
    int ganttProcess[MAX * 50], ganttTime[MAX * 50], index = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].at <= currentTime && !visited[i]) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {
        if (front == rear) {
            int nextArrival = 1e9, idx = -1;
            for (int i = 0; i < n; i++) {
                if (!p[i].completed && p[i].at < nextArrival) {
                    nextArrival = p[i].at;
                    idx = i;
                }
            }
            ganttProcess[index] = -2;
            ganttTime[index] = currentTime;
            index++;
            currentTime = nextArrival;
            continue;
        }

        int idx = queue[front++]; 
        ganttProcess[index] = idx;
        ganttTime[index] = currentTime;
        index++;

        if (p[idx].rt == p[idx].bt) {
            if (currentTime < p[idx].at)
                currentTime = p[idx].at;
            p[idx].st = currentTime;
        }

        if (p[idx].rt > tq) {
            currentTime += tq;
            p[idx].rt -= tq;
        } else {
            currentTime += p[idx].rt;
            p[idx].rt = 0;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            awt += p[idx].wt;
            atat += p[idx].tat;
            p[idx].completed = 1;
            completed++;
        }

        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (p[idx].rt > 0) {
            queue[rear++] = idx;
        }
    }

    ganttTime[index] = currentTime;
    printf("\nGantt Chart:\n");
    for (int i = 0; i < index; i++) printf("-------");
    printf("-\n|");

    for (int i = 0; i < index; i++) {
        if (ganttProcess[i] == -2)
            printf("  IDLE |");
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