#include <stdio.h>

int main() {
    int pages[50], frames[10], n, f, i, j, k, fault = 0, counter = 0, time[10], pos, min;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }
    for(i = 0; i < n; i++) {
        int page = pages[i], flag = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == page) {
                flag = 1;
                time[j] = ++counter;
                break;
            }
        }
        if(flag == 0) {
            pos = 0;
            min = time[0];
            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }
            frames[pos] = page;
            time[pos] = ++counter;
            fault++;
        }
        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }
    printf("\n\nTotal Page Faults = %d\n", fault);
    return 0;
}