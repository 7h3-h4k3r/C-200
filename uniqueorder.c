/*
 * C - The Language That Built the Digital World!
 * Welcome to your C programming adventure!
 *
 * Fun Fact: C was created in 1972 and powers everything from
 * operating systems to embedded devices. You're learning the
 * same language used to build Unix, Linux, and countless others!
 */

#include <stdio.h>
#include <stdlib.h>
int isempty(int *arr){
    if (arr[0]== '\0'){
        return 1;
    }
    return 0;
}

int in(int *arr,int target){
    int index = 0;
    if (isempty(arr)){
        arr[index] = target;
        arr[index+1] = '\0';
        return 1;
    }
    while(arr[index] != '\0'){
        if (arr[index] == target){
            return 1;
        }
        index+=1;
    }
    arr[index] = target;
    arr[index+1] = '\0';
}

void printlist(int *arr) {

    printf("[");
    for (int i = 0; arr[i]!='\0'; i++) {
        printf("%d", arr[i]);
        if (arr[i+1]!='\0'){
            printf(" ,");
        }
    }
    printf("]\n");
}

int main(int argc, char *argv[]) {
    
    if (argc > 1) {
        int MAX = atoi(argv[1]);
        int list_of_max[MAX];
        list_of_max[0] = '\0';
        for (int i = 0; i < argc-2; i++) {
           int value = atoi(argv[i+2]);
           in(list_of_max,value);
        }
    
        int lenof = sizeof(list_of_max) / sizeof(list_of_max[0]);
        printlist(list_of_max);
    } else{
        printf("No arguments provided.\n");
    }

    return 0;
}
