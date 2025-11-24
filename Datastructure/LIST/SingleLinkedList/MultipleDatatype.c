#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 50
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

void append(Node **head , Node **tail,void* data ,Type Datatype){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL ){
        fprintf(stderr,"Error : append() Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->Datatype = Datatype;
    if (*head == NULL && *tail== NULL){
        *head = new_node;
        *tail = new_node;
    }
    else{
        (*tail)->next = new_node;
        *tail = new_node;
    }
}
void print(Node **head){
    Node *temp = *head;
    while (temp)
    {
        switch (temp->Datatype)
        {
        case INT:
            printf("%d",*(int *)temp->data);
            break;
        case FLOAT:
            printf("%f",*(float *)temp->data);
            break;
        case STRING:
            printf("%s",(char *)temp->data);
            break;
        default:
            break;
        }
        
        
       
        if (temp->next!= NULL){
            printf("->");
        }
        temp = temp->next;
    }
    
}
void *getType(char *user_input,int *type){
    char *end;
    long is_int = strtol(user_input,&end,10);
    if (*end=='\0'){
        *type = INT;
        int  *p = malloc(sizeof(int));
        *p = is_int;
        return p;
    }

    float is_float = strtof(user_input,&end);
    if (*end=='\0'){
        *type = FLOAT;
        float  *p = malloc(sizeof(float));
        *p = is_float;
        return p;
    }

    char *p = strdup(user_input);
    *type = 2;
    return p;
}


int main(int args , char *argv[]){
    char *user_input = malloc(MAX_SIZE);
    Node *head = NULL;
    Node *tail = NULL;
    int type = -1;
    while(scanf("%s",user_input)){
        
        void *data = getType(user_input,&type);
        switch (type)
        {
            case INT:
                append(&head,&tail,data,INT);
                break;
            case FLOAT:
                append(&head,&tail,data,FLOAT);
                break;
            case STRING:
                append(&head,&tail,data,STRING);
                break;
            default:
                break;
        }
        print(&head);
        printf("\n");
        
    }
}