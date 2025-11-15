
#include <stdio.h>
#include <stdlib.h>
int max(int n1 ,int n2){
    if(n1 <= n2){
        return n2;
    }
    return n1;
}
int sliding(int *times,int index,int data){
    int i = index;
    int j = -1;
    while(times[i] != '\0'){
        j+=1;
        times[i] = times[i+1];
        i=i+1;
    }
    times[index] = data;
    times[i] = '\0';
    return j;
}
int get_data(int *times,int threshold,int size)
{
    int i = 0 ;
    while(times[i] != '\0'){
        int sum = times[i] + times[i+1];
        if (sum <= threshold){
            int insert = max(times[i],times[i+1]);
            insert = sliding(times,i,insert);
            if(insert>0){
                i-=1;
            }
        }
        i = i+1;
    }
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
    

        get_data(times,threshold,lenof_arr-1);
        i = 0;
        for (i = 0;times[i] != '\0';i++){
            printf("%d\n",times[i]);
        }
    } else {
        printf("No arguments provided.\n");
    }

   
    return 0;
}
