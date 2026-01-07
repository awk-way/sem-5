#include <stdio.h> 
#define MAX 20 

struct process { 
    char name[10]; 
    int at, bt, st, wt, tat, ct; 
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
    } 
    
    sortByArrival(p, n); 
    
    int currentTime = startTime; 
    for (int i = 0; i < n; i++) { 
        if (currentTime < p[i].at) 
            currentTime = p[i].at; 
        
        p[i].st = currentTime;
        currentTime += p[i].bt; 
        p[i].ct = currentTime; 
        p[i].tat = p[i].ct - p[i].at; 
        p[i].wt = p[i].tat - p[i].bt; 
        
        awt += p[i].wt; 
        atat += p[i].tat; 
    } 
    
    printf("\nGantt Chart:\n"); 
    int totalBlocks = n;
    
    if (startTime < p[0].at) totalBlocks++;
    for (int i = 1; i < n; i++) {
        if (p[i].st > p[i-1].ct) totalBlocks++; 
    }
    
    for (int i = 0; i < totalBlocks; i++) { 
        printf("-------"); 
    } 
    printf("-\n|"); 

    currentTime = startTime;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            printf("     |"); 
            currentTime = p[i].at;
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
        if (currentTime < p[i].at) {
            printf("    %2d", p[i].at);
            currentTime = p[i].at;
        }
        printf("     %2d", p[i].ct);
        currentTime = p[i].ct;
    }
     
    printf("\n\n%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Process", "AT", "BT", "ST", "CT", "TAT", "WT"); 
    for (int i = 0; i < n; i++) { 
        printf("%-10s %-10d %-10d %-10d %-10d %-10d %-10d\n", p[i].name, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt); 
    } 
    
    printf("\nAverage Waiting Time = %.2f", awt / n); 
    printf("\nAverage Turnaround Time = %.2f\n", atat / n); 
    
    return 0; 
}