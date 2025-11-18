#include <stdio.h>

int main(){
    int arr[] = {5, 3, 7, 9 ,1};
    int i = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    while (i < size)
    {
        int swapped = 0;

        for (int j = 0;j<size-1;j++){
            if (arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }

        if (swapped!=1){
            break;
        }
        i+=1;
    }

    for(int i = 0;i< size;i++){
        printf("%d",arr[i]);
    }
    

}