#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
/*

ENUMURATINO AND STRUCT DATA'S are move on to sapareate File ,

Handling via Make file &&  oops in future 


enum Type has Handling via Which type of Data user can give IT 

INT - Interget 
Float  - decimal point 0.03
String - mutiple character 

*/
typedef enum Type{
    INT,
    FLOAT,
    STRING
}Type;

typedef struct Node{
    void *data;
    Type Datatype;
    struct Node *next;
}Node;

void append(Node **head , void* data ,Type Datatype){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL){
        fprintf(stderr,"Error : append() Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->Datatype = Datatype;
    if (*head == NULL){
        *head = new_node;
    }
    else{
        new_node->next = *head;
        *head = new_node;
    }
}

int getType(char *user_input){
    char *end;
    long is_int = strtol(user_input,&end,10);
    if (*end=='\0'){
        return INT;
    }

    float is_float = strtof(user_input,&end);
    if (*end=='\0'){
        return FLOAT;
    }

    return STRING;
}


int main(int args , char *argv[]){
    char *user_input = "5";
    Node *head = NULL;
    int num = 11;
    float data = 123.6;
    // TODO :INPUT VALIDATAION 
    append(&head,user_input,STRING);
    append(&head,&num,INT);
    append(&head,&data,FLOAT);
}