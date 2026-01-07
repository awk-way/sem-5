#include <stdio.h>

int main() {
    int pages[50], frames[10], n, f, i, j, k, flag, fault = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++)
        frames[i] = -1;

    j = 0;
    for(i = 0; i < n; i++) {
        flag = 0;
        for(k = 0; k < f; k++) {
            if(frames[k] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            frames[j] = pages[i];
            j = (j + 1) % f;
            fault++;
        }
        printf("\n");
        for(k = 0; k < f; k++)
            printf("%d ", frames[k]);
    }

    printf("\n\nTotal Page Faults = %d\n", fault);
    return 0;
}