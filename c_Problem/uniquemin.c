// 1 1 2 2 
//7 5 2 4 4 2 7 8



#include <stdio.h>
#include <stdlib.h>


int unique(int *arr,int index,int target){
    int count = 0;
    while (arr[index]!='\0')
    {
        if(arr[index] == target){
           count+=1;
        }
        if (count>1){
            return 0;
        }
        index+=1;
    }
    return 1;

}

int min(int n1,int n2){
    
    if(n1 > n2){
        return n2;
    }
    return n1;
}

int main(int argc, char *argv[]) {
    int lenof_arr = argc-1;

    int times[lenof_arr];

    int i; 
    if (argc > 1) { 
        for (i = 1;i <=lenof_arr;i++){
            times[i-1] = atoi(argv[i]);
        }
        times[i-1] = '\0';    
    
    } else {
        printf("No arguments provided.\n");
    }
    i = 0;
    int min_value = 10000000;
    while (i < lenof_arr){
        int result = unique(times,0,times[i]);
        if (result){
            min_value = min(abs(min_value),abs(times[i]));
        }
        i+=1;
    }
    if(min_value==10000000){
        printf("%d",-1);
    }else{
        printf("%d",min_value);
    }
   
    
   
    return 0;
}
