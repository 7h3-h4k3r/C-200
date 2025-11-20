
#include <stdio.h>
#include <stdlib.h>
void sum_segment(int *arr , int size,int target){
    for(int i = 0;i<size;i++){
        printf("%d",arr[i]);
    }
}
int main(int argc, char *argv[]) {
   
    if (argc <= 1) {
        printf("args not found");
        return -1;
    }
    int target = argv[1];
    int size = argc -1;
    int  *myar;
    myar = (int *)malloc(size * sizeof(int));
    if (myar == NULL){
        printf("Memory allocation failed");
        return -1;
    }
    for(int i = 1;i<size-1;i++){
        *(myar + (i-1)) = atoi(argv[i+1]);
    }
    
    sum_segment(myar,size-1,target);
    return 0;
}
