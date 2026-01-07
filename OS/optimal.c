#include <stdio.h>

int main() {
    int pages[50], frames[10], n, f, i, j, k, pos, flag, fault = 0, future[10];
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;
    for(i = 0; i < n; i++) {
        flag = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    flag = 2;
                    break;
                }
            }
            if(flag != 2) {
                for(j = 0; j < f; j++) {
                    future[j] = -1;
                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            future[j] = k;
                            break;
                        }
                    }
                }
                int max = -1;
                for(j = 0; j < f; j++) {
                    if(future[j] == -1) {
                        pos = j;
                        break;
                    }
                    if(future[j] > max) {
                        max = future[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            fault++;
        }
        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", fault);
    return 0;
}