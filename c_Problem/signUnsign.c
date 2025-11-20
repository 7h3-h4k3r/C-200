#include <stdio.h>
#include <stdlib.h>

// 


int sign(int n){
    if (n == 0){
        return 1;
    }
    return 0;
}
void change_it(int *arr , int index ,int size){
    for (int i = index ;i < size;i++){
        arr[i] = arr[i+1];
    }
}

int getvalues(int *arr,int size ,int sign){
    int value = 0;
    int  i = 0;
    for(i = 0;i<size;i++){
        if (sign==1 && 0<arr[i]){
            value = arr[i];
            change_it(arr,i,size);
            return value;
        }
        else if(sign == 0 && 0 > arr[i]){
            value = arr[i];
            change_it(arr,i,size);
            return value;
        }
    }
    value = arr[0];
    change_it(arr,i,size);
    return value;
}
void order_change(int *integerArr,int size){
    int SIGN = 1;
    int i = 0;
    int arr[10];
    int index = 0;
    while (i < size){
        int value = getvalues(integerArr,size-i,SIGN);
        if (SIGN == 1){
            arr[index++] = value; 
            SIGN = sign(SIGN);
        }
        else {
            arr[index++] = value;
            SIGN = sign(SIGN);
        }

        i+=1;
    }
    for (int i = 0;i<index-1;i++){
        printf("%d ",arr[i]);
    }
}

int main(int argc, char *argv[]) {
    
    if (argc <= 1) {
        printf("arugument Missing in the argc ...");
    }
    
    int size = argc;
    int *integerArr;
    integerArr = (int *)malloc(size*sizeof(int));
    for(int i = 1; i < size ;i++){
        *(integerArr + (i-1)) = atoi(argv[i]);
    }
    order_change(integerArr,size);
    
    return 0;
}
