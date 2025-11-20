#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void enqueue(int *arr, int num, int *index) {
    if (*index >= MAX) {
        printf("Queue full!\n");
        return;
    }
    arr[*index] = num;
    (*index)++;
}

void dequeue(int *arr, int *index) {
    if (*index <= 0) {
        printf("Queue empty!\n");
        return;
    }
    for (int i = 0; i < *index - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*index)--;
}

void printQueue(int *arr, int index) {
    if (index == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < index; i++) {
        printf("%d", arr[i]);
        if (i < index - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(int argc, char *argv[]) {
    int list_of_data[MAX];
    int index = 0;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "E") == 0 && i + 1 < argc) {
                int value = atoi(argv[i + 1]);
                enqueue(list_of_data, value, &index);
                i++; 
            } 
            else if (strcmp(argv[i], "D") == 0) {
                dequeue(list_of_data, &index);
            }
        }
    } else {
        printf("No arguments provided.\n");
        return 0;
    }

    printQueue(list_of_data, index);
    return 0;
}
