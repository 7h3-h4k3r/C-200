/*
 * C with GCC 9.2 - The Latest in C Compilation Technology
 *
 * You're using one of the most advanced C compilers available.
 * GCC 9.2 gives you cutting-edge performance and safety features!
 *
 * Did You Know? C is the #1 choice for operating systems, databases,
 * and embedded systems worldwide. Your skills are in high demand!
 */

#include <stdio.h>
#include <stdlib.h>
void reverse_group(int *arr , int kth , int size ){
    int i = 0;
    
    while (i < size){
        int kth_te = kth;
        for(int j = i;j < kth_te ;j++){
            int temp = *(arr + (kth_te-1));
            *(arr + (kth_te-1)) = *(arr + j);
            *(arr + j) = temp;
            kth_te -=1;
        }
        i+=kth;
        if((kth+kth)  >size){
            break;
        }
        kth = kth + kth;
    }
}
int print(int *arr,int size){
    for(int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(int argc, char *argv[]) {
    
    if (argc <= 1) {
        printf("usage : ./a.out <input>");
        return 1;
    }
    
    int size_of = argc-1;
    int kth = atoi(argv[1]);
    
    int *ledger;
    ledger = (int *)malloc(size_of  * sizeof(int));
    if(ledger == NULL){
        printf("integer Memory  allocation failed");
        return -1;
    }
    for(int i = 1;i<size_of;i++){
        *(ledger + (i-1)) = atoi(argv[i+1]); 
    }
    if (kth>size_of-1){
        print(ledger,size_of-1);
        return 0;
    }
    reverse_group(ledger,kth,size_of);
    print(ledger,size_of-1);
}

