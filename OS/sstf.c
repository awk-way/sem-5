#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main() {
    int n, i, j, totalHeadMovement = 0, requests[MAX], visited[MAX] = {0}, head, currentHead, seekSequence[MAX + 1], seqIndex = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter Request Queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    printf("Enter Current Head Position: ");
    scanf("%d", &head);
    printf("\n--- SSTF Disk Scheduling Algorithm ---\n");
    printf("--------------------------------------------------\n");
    printf("From\t\tTo\t\tDistance\n");
    printf("--------------------------------------------------\n");
    currentHead = head;
    seekSequence[seqIndex++] = head;

    for (i = 0; i < n; i++) {
        int minDistance = 9999, nextIdx = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(currentHead - requests[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextIdx = j;
                }
            }
        }
        if (nextIdx != -1) {
            printf("%d\t\t%d\t\t%d\n", currentHead, requests[nextIdx], minDistance);
            totalHeadMovement += minDistance;
            currentHead = requests[nextIdx];
            visited[nextIdx] = 1;
            seekSequence[seqIndex++] = currentHead; 
        }
    }
    printf("--------------------------------------------------\n");
    printf("\nSeek Sequence: ");
    for (i = 0; i < seqIndex; i++) {
        printf("%d", seekSequence[i]);
        if (i < seqIndex - 1)
            printf(" -> ");
    }
    printf("\nTotal Number of Head Movements: %d\n", totalHeadMovement);
    return 0;
}