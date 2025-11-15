// 3 1 1 2 2 1 1



#include <stdio.h>
#include <stdlib.h>


int ktime(int *times ,int *last_int,int k,int size){
    int i = 0;
    
    while (i<=size)
    {
        if(i!=0){
            if(last_int[1] == times[i]){
                last_int[0] = last_int[0]+1;
            }
            else if(last_int[0]== k){
                return 1;
            }
            else{
                last_int[0] = 1;
                last_int[1]= times[i];
                last_int[2] = i;
            }  
        }
        
        i+=1;  
    }
    return 0;
}
int main(int argc, char *argv[]) {
    
    if (argc > 1) {
        int lenof_arr = argc-1;
    
        int threshold = atoi(argv[1]);
        
        int times[lenof_arr];
        int i;  
        for (i = 1;i <=lenof_arr-1;i++){
            times[i-1] = atoi(argv[i+1]);
        }
        times[i-1] = '\0';
        int last_int[] = {1,times[0],0};
        int result = ktime(times,last_int,threshold,lenof_arr-1);
        if (result){
            printf("%d",last_int[2]);
        }
        else{
            printf("%d",-1);
        }
    
    } else {
        printf("No arguments provided.\n");
    }

   
    return 0;
}
