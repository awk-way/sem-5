#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty, *buffer, SIZE, in = 0, out = 0;

void wait(int *s) {
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void display_buffer() {
    int i;
    printf("\n\t\t\t   ");
    for (i = 0; i < SIZE; i++) {
        printf("%d    ", i);
    }
    printf("\n\t\t\t");
    for (i = 0; i < SIZE; i++) {
        printf("-----");
    }
    printf("\n\t\tbuffer  |");
    for (i = 0; i < SIZE; i++) {
        if ((full > 0 && i >= out && i < in) || (full == SIZE) || (in < out && (i >= out || i < in))) {
            printf(" %2d |", buffer[i]);
        } else {
            printf("    |");
        }
    }
    printf("\n\t\t\t");
    for (i = 0; i < SIZE; i++) {
        printf("-----");
    }
}


void produce_item() {
    int item;
    printf("Enter the item to produce: ");
    scanf("%d", &item);
    wait(&empty);
    wait(&mutex);
    buffer[in] = item;
    in = (in + 1) % SIZE;
    signal(&mutex);
    signal(&full);
    display_buffer();
}

void consume_item() {
    int item;
    wait(&full);
    wait(&mutex);
    item = buffer[out];
    out = (out + 1) % SIZE;
    signal(&mutex);
    signal(&empty);
    display_buffer();
}

int main() {
    int choice;
    printf("Enter buffer size: ");
    scanf("%d", &SIZE);
    buffer = (int *)malloc(SIZE * sizeof(int));
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    empty = SIZE;
    while (1) {
        printf("\n1) Produce an item         2) Consume an item             3) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    produce_item();
                else
                    printf("\nBUFFER FULL! Cannot produce more items.\n");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consume_item();
                else
                    printf("\nBUFFER EMPTY! Nothing to consume.\n");
                break;
            case 3:
                printf("\nExiting program...\n");
                free(buffer);
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}