
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int is_even(int n){
    return n % 2 == 0;
}

int evenOdd(int *arr,int size){

    int temp[MAX];
    int Odd[MAX];
    int index = 0 ;
    int evenindex = 0;
    for(int i = 0 ;i<size;i++){
        if(!is_even(i)){
            Odd[index++] = arr[i];
        }
        else{
            temp[evenindex++] = arr[i];
        }
    }

    for(int i = 0;i< index;i++){
        temp[evenindex++] = Odd[i];
    }
    for (int i =0;i < size;i++){
        printf("%d ",temp[i]);
    }
}


int main(int argc, char *argv[]) {
    
    if (argc <= 1) {
        printf("usage ./a.out <input>");
        return 1;
    }
    int *listof;
    listof = (int *)malloc((argc-1) * sizeof(int));
    for(int i=0 ;i <argc -1;i++){
        *(listof + i) = atoi(argv[i+1]);
    }
    evenOdd(listof,argc-1);
    return 0;
}
