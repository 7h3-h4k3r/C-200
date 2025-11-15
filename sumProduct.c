
#include <stdio.h>
#include <stdlib.h>



void printlist(int *arr,int index,int size) {

    if (size == -1) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = index; i <size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}
int sumProduct(int *arr,int size){
    int i = 0;
    while (i < size)
    {
        int sum = -1;
        for(int index = i;index<size;index++){
            if(sum == -1){
                sum = arr[index];
            }
            else{
                sum+= arr[index];
                if (sum == (arr[i] * arr[index])){
                    printlist(arr,i,index+1);
                    return 0;
                }
            }

            
        }
        i+=1;
    }
    return -1;
    
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

    int result = sumProduct(myArray,size);
    if(result == -1){
        printlist(myArray,-1,-1);
    }
    return 0;
}
