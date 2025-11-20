
#include <stdio.h>
#include <stdlib.h>
int count(int *arr,int target,int size){
    int count = 0;
    for(int i = 0;i<size;i++){
        if(arr[i] == target){
            count+=1;
        }
    }
    return count;
}


int is_even(int n){
    return n % 2 == 0;
}


int palindromic(int *arr,int size){
    int add_count = 0;
    for(int i = 0;i<size;i++){
       int result = count(arr,arr[i],size);
       if (!is_even(result)){
           add_count+=1;
       }
    }
    return(add_count<=1);
}
int main(int argc, char *argv[]) {
    

    if (argc <=1) {
        printf("not argument Found");
        return 0;
    }
    
    int *myarr;
    int size = argc -1;
    myarr = (int *)malloc(size * sizeof(int));
    if (myarr == NULL){
        printf("Memory allocation failed");
        return 1; 
    }
    
    for(int i = 0;i<size;i++){
        *(myarr + i) = atoi(argv[i+1]);
    }
    
    int result = palindromic(myarr,size);
    
    if(result){
        printf("true");
    }
    else{
        printf("false");
    }
}
