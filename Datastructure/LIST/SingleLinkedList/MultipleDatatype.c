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


typedef struct HeadNode
{
    Node *head;
    Node *tail;
}HeadNode;

void append(HeadNode ** headNode,void* data ,Type Datatype){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL ){
        fprintf(stderr,"Error : append() Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->Datatype = Datatype;
    if ((*headNode)->head == NULL && (*headNode)->tail == NULL){
        (*headNode)->head = new_node;
        (*headNode)->tail = new_node;
    }
    else{
        (*headNode)->tail->next = new_node;
        (*headNode)->tail = new_node;
    }
}


int cmpInt(void* src,void* des){
    if (*(int*)src == *(int*)des){
        return 1;
    }
    return 0;

}

int cmpString(void*src , void *des){
    if (strcmp((char*)src,(char*)des)==0){
        return 1;
    }
    return 0;
}

int  cmpFloat(void *src , void *des){
    if (*(float*)src == *(float*)des){
        return 1;
    }
    return 0;
}


int __pop__(HeadNode **headNode,void *value ,Type Datatype){
    
    Node *temp = (*headNode)->head;
    Node *prev = NULL;
    
    while (temp){
        if (temp->Datatype == Datatype){
            switch (Datatype)
            {
            case INT:
                if (cmpInt(temp->data,value)){
                    if (prev==NULL){
                        (*headNode)->head = temp->next;
                        return 0; 
                    }
                    prev->next = temp->next;
                    return 0;
                }
                break;
            case FLOAT:
                if (cmpFloat(temp->data,value)){
                     if (prev==NULL){
                        (*headNode)->head = temp->next;
                        return 0; 
                    }
                    prev->next = temp->next;
                    return 0;
                }
                break; 
            case STRING:
                if (cmpString(temp->data,value)){
                     if (prev==NULL){
                        (*headNode)->head = temp->next;
                        return 0; 
                    }
                    prev->next = temp->next;
                    return 0;
                }
                break;
            
            }
        }
        prev = temp;
        temp = temp->next;       
    }
    
}
    
// int pop(Node **head , Node **tail , int value){
//     if (value==NULL){

//     }
// }
void print(HeadNode **head){
    Node *temp = (*head)->head;
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

int __init__(HeadNode **headNode){
    *(headNode) = (HeadNode *)malloc(sizeof(HeadNode));
    if (*(headNode) == NULL){
        fprintf(stderr,"Err : Memory allocation Failed __inin__() ");
        exit(EXIT_FAILURE);
    }
    (*headNode)->head = NULL;
    (*headNode)->tail = NULL;
}

int main(int args , char *argv[]){
    // char *user_input = malloc(MAX_SIZE);
    // Node *head = NULL;
    // int type = -1;

    HeadNode *headNode;
    __init__(&headNode);

    char *user_input = "5";
    int num = 11;
    float data = 123.6;
    // TODO :INPUT VALIDATAION 
    append(&headNode,user_input,STRING);
    append(&headNode,&num,INT);
    append(&headNode,&data,FLOAT);
    
    // while(scanf("%s",user_input)){
        
    //     void *data = getType(user_input,&type);
    //     switch (type)
    //     {
    //         case INT:
    //             append(&head,&tail,data,INT);
    //             break;
    //         case FLOAT:
    //             append(&head,&tail,data,FLOAT);
    //             break;
    //         case STRING:
    //             append(&head,&tail,data,STRING);
    //             break;
    //         default:
    //             break;
    //     }
    print(&headNode);
    printf("\n");
    // __pop__(&headNode,&(int){11},INT);
    // printf("After __pop__() callin\n");
    // print(&headNode);
    // printf("\n");
    printf("remove String {} is 5\n");
    __pop__(&headNode,&(char[]){"5"},STRING);
    print(&headNode);
    printf("\n");
    //     printf("\n");
        
    // }
}