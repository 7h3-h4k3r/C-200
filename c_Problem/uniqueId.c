
#include <stdio.h>
#include<stdlib.h>
int print(int *arr, int index){
    if (index == 0){
        printf("[]\n");
        return 0;
    }
    
    printf("[");
    for (int i = 0;i<index;i++){
        printf("%d",arr[i]);
        if (i < index -1){
            printf(", ");
        }
    }
    printf("]");
}

int sum(int *arr,int size){
    int sumof = 0 ;
    for(int i = 0;i<size;i++){
        sumof+= arr[i];
    }
    
    return sumof;
}
int in_arr(int *arr,int target, int size){
    for(int i = 0;i<size;i++){
        if(arr[i] == target){
            return 0;
        }
    }
    return 1;
}
int unique(int *arr,int size){
    int *unique_arr;
    unique_arr = (int *) malloc(size * sizeof(int));
    int unique_index, temp_index;
    int *temp;
    temp = (int *) malloc(size * sizeof(int));
    for(int i = 0;i<size;i++){
        if (arr[i] == -1){
            unique_arr[unique_index++] = sum(temp,temp_index);
            temp_index = 0;
        }
        else{
            if(in_arr(temp,arr[i],temp_index)){
                temp[temp_index++] = arr[i];
            }
        }
    }

    if(temp_index >0){
        unique_arr[unique_index++] = sum(temp,temp_index);
    }
    
    print(unique_arr,unique_index);
}
int main(int argc, char *argv[]) {

    if (argc <= 1) {
        printf("argument is not Found");
        return 1;
    }
    
    int size = argc -1;
    int *myarr;
    myarr = (int *)malloc(size * sizeof(int));
    if(myarr == NULL){
        printf("Memory allocation is Found");
        return 1;
    }
    
    for(int i=0;i<size;i++){
        *(myarr + i) = atoi(argv[i+1]);
    }
    unique(myarr,size);
    
    return 0;
}
