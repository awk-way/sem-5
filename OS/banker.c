#include <stdio.h>
#define MAX 20   
void printMatrix(int mat[MAX][MAX], int rows, int cols, const char *name) {
    int i, j;
    printf("\n%s matrix:\n", name);
    printf("     ");
    for (j = 0; j < cols; j++)
        printf("R%d  ", j);
    printf("\n----------------------\n");
    for (i = 0; i < rows; i++) {
        printf("P%d | ", i);
        for (j = 0; j < cols; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

void printAvailable(int avail[MAX], int m) {
    int j;
    printf("\nAvailable resources:\n");
    for (j = 0; j < m; j++)
        printf("R%d: %d ", j, avail[j]);
    printf("\n");
}

int safetyAlgo(int alloc[MAX][MAX], int need[MAX][MAX], int avail[MAX], int n, int m) {
    int work[MAX], finish[MAX] = {0}, safeSeq[MAX], i, j, k, count = 0;
    for (j = 0; j < m; j++)
        work[j] = avail[j];
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == m) {
                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nSystem is NOT in a safe state.\n");
            return 0;
        }
    }
    printf("\nSystem is in a SAFE state.\nSafe sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    return 1;
}

void requestResources(int alloc[MAX][MAX], int max[MAX][MAX], int need[MAX][MAX], int avail[MAX], int n, int m){
    while (1) {
        char choice;
        int p, req[MAX], i, j;
        printf("\nDo you want to make an immediate request? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
            break;
        printf("Enter process number (0-%d): ", n - 1);
        scanf("%d", &p);
        if (p < 0 || p >= n) {
            printf("Invalid process number.\n");
            continue;
        }
        printf("Enter request for each resource type: ");
        for (j = 0; j < m; j++)
            scanf("%d", &req[j]);

        for (j = 0; j < m; j++) {
            if (req[j] > need[p][j]) {
                printf("P%d is asking more than declared need.\n", p);
                printf("Process must wait.\n");
                goto show_state;
            }
        }
        for (j = 0; j < m; j++) {
            if (req[j] > avail[j]) {
                printf("Resources not available. P%d must wait.\n", p);
                goto show_state;
            }
        }
        int allZero = 1;
        for (j = 0; j < m; j++)
            if ((avail[j] - req[j]) != 0)
                allZero = 0;
        if (allZero) {
            printf("\nRequest violates Banker's Algorithm!\n");
            printf("Process must wait.\n");
            goto show_state;
        }
        int oldAvail[MAX], oldAlloc[MAX][MAX], oldNeed[MAX][MAX];
        for (j = 0; j < m; j++)
            oldAvail[j] = avail[j];
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                oldAlloc[i][j] = alloc[i][j];
                oldNeed[i][j] = need[i][j];
            }
        for (j = 0; j < m; j++) {
            avail[j] -= req[j];
            alloc[p][j] += req[j];
            need[p][j] -= req[j];
        }

        if (safetyAlgo(alloc, need, avail, n, m))
            printf("Request granted.\n");
        else {
            printf("Request cannot be granted (unsafe state).\n");
            for (j = 0; j < m; j++)
                avail[j] = oldAvail[j];
            for (i = 0; i < n; i++)
                for (j = 0; j < m; j++) {
                    alloc[i][j] = oldAlloc[i][j];
                    need[i][j] = oldNeed[i][j];
                }
        }
show_state:
        printMatrix(alloc, n, m, "Allocation");
        printMatrix(need, n, m, "Need");
        printAvailable(avail, m);
    }
}

int main() {
    int n, m;
    int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX], avail[MAX];
    int i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);
    printf("\nEnter Allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    printf("\nEnter Max matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("\nEnter Available resources:\n");
    for (j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printMatrix(alloc, n, m, "Allocation");
    printMatrix(max, n, m, "Max");
    printMatrix(need, n, m, "Need");
    printAvailable(avail, m);

    printf("\nInitial safety check:\n");
    safetyAlgo(alloc, need, avail, n, m);
    requestResources(alloc, max, need, avail, n, m);
    return 0;
}
