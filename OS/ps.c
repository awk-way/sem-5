#include <stdio.h> 
#define MAX 20 

struct process { 
    char name[10]; 
    int at, bt, st, wt, tat, ct, pr; 
    int completed;
}; 

void sortByTime(struct process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].st > p[j + 1].st) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() { 
    struct process p[MAX]; 
    int n, startTime, currentTime, cc = 0;
    float awt = 0, atat = 0; 
    
    printf("\nEnter the starting time: ");
    scanf("%d", &startTime);
    
    printf("\nEnter number of processes: "); 
    scanf("%d", &n); 
    
    for (int i = 0; i < n; i++) { 
        printf("\nEnter process name, arrival time, burst time and priority: "); 
        scanf("%s%d%d%d", p[i].name, &p[i].at, &p[i].bt, &p[i].pr); 
        p[i].completed = 0;
    } 

    currentTime = startTime;
    while (cc < n) {
        int pj = -1, highp = 9999;
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= currentTime && p[i].pr < highp) {
                highp = p[i].pr;
                pj = i;
            }
        }
        
        if (pj == -1) {
            int na = 9999;
            for (int i = 0; i < n; i++) {
                if (!p[i].completed && p[i].at < na) {
                    na = p[i].at;
                }
            }
            currentTime = na;
        } else {
            p[pj].st = currentTime;
            currentTime += p[pj].bt;
            p[pj].ct = currentTime;
            p[pj].tat = p[pj].ct - p[pj].at;
            p[pj].wt = p[pj].tat - p[pj].bt;
            p[pj].completed = 1;
            cc++;
            
            awt += p[pj].wt;
            atat += p[pj].tat;
        }
    }

    sortByTime(p, n);

    printf("\nGantt Chart:\n"); 
    int totalBlocks = n;
    if (p[0].st > startTime) totalBlocks++;
    for (int i = 1; i < n; i++) {
        if (p[i].st > p[i-1].ct) totalBlocks++; 
    }
    
    for (int i = 0; i < totalBlocks; i++) { 
        printf("-------"); 
    } 
    printf("-\n|"); 

    currentTime = startTime;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].st) {
            printf("     |"); 
            currentTime = p[i].st;
        }
        printf("  %s  |", p[i].name);
        currentTime = p[i].ct;
    }
    
    printf("\n"); 
    for (int i = 0; i < totalBlocks; i++) { 
        printf("-------"); 
    } 
    
    printf("-\n%d", startTime); 
    currentTime = startTime;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].st) {
            printf("    %2d", p[i].st);
            currentTime = p[i].st;
        }
        printf("     %2d", p[i].ct);
        currentTime = p[i].ct;
    }
     
    printf("\n\n%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Process", "AT", "BT", "Priority", "ST", "CT", "TAT", "WT"); 
    for (int i = 0; i < n; i++) { 
        printf("%-10s %-10d %-10d %-10d %-10d %-10d %-10d %-10d\n", p[i].name, p[i].at, p[i].bt, p[i].pr, p[i].st, p[i].ct, p[i].tat, p[i].wt); 
    } 
    
    printf("\nAverage Waiting Time = %.2f", awt / n); 
    printf("\nAverage Turnaround Time = %.2f\n", atat / n); 
    
    return 0; 
}