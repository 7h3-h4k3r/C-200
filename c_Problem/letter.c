#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int display(char *argv[],int size){

    for(int i = 0;i<size;i++){
        printf("%s",argv[i+1]);
    }
}

int allocation(void *point){
    if (point ==NULL){
        printf("Memory allocation Failed");
        exit(-1);
    }
    return 0;
}

int in(char target,char *uniqe, int size){
    for(int i = 0;i<size;i++){
        if (target == uniqe[i]){
            return i;
        }
    }

    return -1;
}

void frequenc(char *unique , int *count_data ,int size , char *argv[]){
    int i =0;
    int index = 0;
    while(i < size){
        
        for(int j = 0;j < strlen(argv[i+1]);j++){
            int value = in(argv[i][j],unique,index);
            if(value!=-1){
                count_data[value] +=1;
            }
            else{
                unique[index] = argv[i][j];
                count_data[index] = 1;
                index++;
            }
        }
        
        i++;
        if (index == 1){
            unique[index] = "";
            count_data[index] = 1;
            index++;
        }
        else{
            count_data[1]+=1;
        }
    }
}
void dic_data_allocation(char *argv[] , int size){
    char *unique_data;
    unique_data = (char *) malloc(size * sizeof(char));
    allocation(unique_data);
    int *count_data;
    count_data = (int *) malloc(size * sizeof(char));
    allocation(count_data);
    frequenc(unique_data,count_data,size,argv);   
    
}
int main(int args , char* argv[]){
    if (args<=1){
        printf("usage ./a.out <input>");
    }
   dic_data_allocation(argv,args);  
}