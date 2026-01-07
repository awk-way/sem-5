#include <stdio.h>
#include <string.h>
#define MAX 50
int partitions[MAX], processes[MAX], blockProcesses[MAX][MAX], count[MAX];

int main() {
    int m, processSize, processNumber = 0;
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter block sizes (KB): ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &partitions[i]);
        count[i] = 0; 
    }
    printf("\n--- Best Fit Allocation ---\n");
    while (1) {
        printf("\nEnter process size (KB) (-1 to stop): ");
        scanf("%d", &processSize);
        if (processSize == -1) {
            printf("\nStopping allocation.\n");
            break;
        }
        processes[processNumber] = processSize;
        int bestIdx = -1;;
        for (int j = 0; j < m; j++) {
            if (partitions[j] >= processSize) {
                if (bestIdx == -1 || partitions[j] < partitions[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            blockProcesses[bestIdx][count[bestIdx]++] = processNumber;
            partitions[bestIdx] -= processSize;
            for (int b = 0; b < m; b++) {
                for (int k = 0; k < count[b]; k++) {
                    int p = blockProcesses[b][k];
                    printf("Process %d (%d KB) allocated to Block with size %d\t Available Space in Block: %d\n",p + 1, processes[p], partitions[b] + processes[p], partitions[b]);
                }
            }
        } else {
            printf("Process %d (%d KB) not allocated\n", processNumber + 1, processSize);
        }
        processNumber++;
    }
    return 0;
}