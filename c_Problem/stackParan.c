/*

 * ())(
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int stack(char *arr){
    char *instack;
    instack = (char *)malloc(strlen(arr)+1);
    if (instack == NULL){
        printf("stack Memory allication failed");
        return 1; 
    }
    
    int index = 0;
    for (int i = 0;arr[i]!='\0';i++){
        
        if (*(arr + i) == '('){
            instack[index++] = *(arr + i); 
            
        }
        else{
            if (instack[0]!='\0'){
                index -=1;
                instack[index] = '\0';
            }
            else{
                return -1;
            }
            
        }
        
    }
    
    if (instack[0] == '\0'){
        return 1;
    }
    return -1;
}
int main(int argc, char *argv[]) {
    
    if (argc <= 1) {
       printf("usage : ./a.out <input>\n");
       return 1; 
    }
    
    char *parenthese;
    
    parenthese = (char *)malloc(strlen(argv[1]) + 1);
    
    if (parenthese == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for(int i = 0;i<strlen(argv[1]);i++){
        *(parenthese + i) = argv[1][i];
    }
    printf("%d ",stack(parenthese));
}
