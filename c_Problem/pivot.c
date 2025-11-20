#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//10 10 8 12 10 5
#define MAX 10

int addon(int *destination , int *source ,int des_len , int sour_len){
    for(int i = 0;i < sour_len ;i++){
        *(destination + des_len) = *(source + i);
        des_len+=1; 
    }
    return des_len;
}
void printformat(int *arr, int index) {
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
void pivot_calculate(int *arr, int pivot, int size){
    int *less = malloc(sizeof(int) * size);
    int *equal = malloc(sizeof(int) * size);
    int *greater = malloc(sizeof(int) * size);

    int l = 0,e =0 ,g = 0;
    for(int i = 0;i < size; i++){
        if(arr[i] == pivot){
            equal[e++] = *(arr + i);
        }
        else if(arr[i] > pivot){
            greater[g++] = *(arr + i);
        }else{
            less[l++] = *(arr + i);
        }

    }
    l = addon(less,equal,l,e);
    l = addon(less,greater,l,g);
    printformat(less,l);
}
int main(int argc, char *argv[]) {
    if (argc <= 1) {
       printf("usage : ./a.out <input>\n");
       return 1; 
    }
    int *myArray;
    int pivot = atoi(argv[1]);
    int size = argc-2;
    myArray = (int *)malloc(size * sizeof(int));
    if (myArray == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    for(int i = 1;i<=size;i++){
        *(myArray  + i-1) = atoi(argv[i+1]);
    }
    pivot_calculate(myArray,pivot,size);
    return 0;
}