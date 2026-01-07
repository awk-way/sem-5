#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main() {
    int n, i, j, temp, requests[MAX], seekSequence[MAX + 1], head, h, prevHead, direction, totalHeadMovement = 0, count = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter Request Queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    printf("Enter Current Head Position: ");
    scanf("%d", &head);
    h = head;
    printf("Enter Previous Head Position: ");
    scanf("%d", &prevHead);

    direction = (head > prevHead) ? 1 : 0; 
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    int pos = 0;
    for (i = 0; i < n; i++) {
        if (head < requests[i]) {
            pos = i;
            break;
        }
    }
    
    printf("\n--- C-LOOK Disk Scheduling Algorithm ---\n");
    printf("\n--------------------------------------------------\n");
    printf("From\t\tTo\t\tDistance\n");
    printf("--------------------------------------------------\n");
    if (direction == 1) {  
        for (i = pos; i < n; i++) {
            printf("%d\t\t%d\t\t%d\n", head, requests[i], abs(head - requests[i]));
            totalHeadMovement += abs(head - requests[i]);
            head = requests[i];
            seekSequence[count++] = head;
        }
        if (pos > 0) {
            printf("%d\t\t%d\t\t%d\n", head, requests[0], abs(head - requests[0]));
            totalHeadMovement += abs(head - requests[0]);
            head = requests[0];
            seekSequence[count++] = head;
        }
        for (i = 1; i < pos; i++) {
            printf("%d\t\t%d\t\t%d\n", head, requests[i], abs(head - requests[i]));
            totalHeadMovement += abs(head - requests[i]);
            head = requests[i];
            seekSequence[count++] = head;
        }
    } else {  
        for (i = pos - 1; i >= 0; i--) {
            printf("%d\t\t%d\t\t%d\n", head, requests[i], abs(head - requests[i]));
            totalHeadMovement += abs(head - requests[i]);
            head = requests[i];
            seekSequence[count++] = head;
        }
        if (pos < n) {
            printf("%d\t\t%d\t\t%d\n", head, requests[n - 1], abs(head - requests[n - 1]));
            totalHeadMovement += abs(head - requests[n - 1]);
            head = requests[n - 1];
            seekSequence[count++] = head;
        }
        for (i = n - 2; i >= pos; i--) {
            printf("%d\t\t%d\t\t%d\n", head, requests[i], abs(head - requests[i]));
            totalHeadMovement += abs(head - requests[i]);
            head = requests[i];
            seekSequence[count++] = head;
        }
    }
    printf("--------------------------------------------------\n");
    printf("\nSeek Sequence: %d -> ", h);
    for (i = 0; i < count; i++) {
        printf("%d", seekSequence[i]);
        if (i != count - 1)
            printf(" -> ");
    }
    printf("\nTotal Number of Head Movements: %d\n", totalHeadMovement);
    return 0;
}
