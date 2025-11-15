#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 10

void count(int *arr, int size ,int *on,int *off){
    
    for(int i=0;i < size;i++){
        if(arr[i] == 1){*on +=1;}
        else{*off +=1;}

    }
}

void copy(int *source, int *destination , int size){
    for(int i = 0;i<size;i++){
        destination[i] = source[i];
    }
}

void printlist(int *arr,int size) {

    if (size == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i <size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}
void *LongestLightSwitch(int *arr,int size){
    int i  = 0;
    int longest_light[MAX];
    int Max_len = -1;
    int index_count = 0;
    int on = 0,off=0;
    while (i < size)
    {
        int temp_Arr[MAX];
        for(int sensor = i;sensor < size ; sensor++){
            temp_Arr[index_count++] = *(arr + sensor);
            count(temp_Arr,index_count,&on,&off);
            if(on>off && Max_len < index_count){
                Max_len = index_count;
                copy(temp_Arr,longest_light,index_count);
                
            }
            on = 0;off =0;
        }
        index_count = 0;
        i+=1;
    }
    printlist(longest_light,Max_len);
    return longest_light;
    
}


int main(int argc, char *argv[]) {
    
    if (argc <= 1) {
       printf("usage : ./a.out <input>\n");
       return 1; 
    }
    int *myArray;
    int size = argc-1;
    myArray = (int *)malloc(size * sizeof(int));
    if (myArray == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    for(int i = 0;i<size;i++){
        *(myArray  + i) = atoi(argv[i+1]);
    }

    int *longestOnOff = LongestLightSwitch(myArray,size);
    
    return 0;
}