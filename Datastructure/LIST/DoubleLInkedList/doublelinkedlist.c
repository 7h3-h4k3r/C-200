#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>


#define MAX 50
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}Node ;

typedef struct doubleLinkedList{
    Node *head;
    Node *tail;
}doubleLinkedList;

void Error(char Err[],int Errcode){    
    printf("[*] Err : %s ",Err);
    if (Errcode!=0){
        exit(EXIT_FAILURE);
    }

}



int insert(doubleLinkedList **head , int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL){
        Error("new Node Memory allocation Failed __insert__()",1);
    }
    new_node->data = value;
    if ((*head)->tail  == NULL){
        new_node->prev = NULL;
    } 
    else{
        new_node->prev = (*head)->tail;
    }
    if ((*head)->head == NULL && (*head)->tail == NULL){
        (*head)->head = new_node;
        (*head)->tail = new_node;
    }
    else{
        (*head)->tail->next = new_node;
        (*head)->tail =  new_node;
    }
}

int __pop__(Node **head, int value){
    
    Node *temp = (*head);
    while (temp)
    {
        if(temp->data == value){
            if (temp->prev == NULL){
                temp->next->prev = NULL;
                temp = temp->next;
                return 1;
            }
            else if (temp->next == NULL){
                temp->prev->next = NULL;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

int pop(doubleLinkedList **head, int value){
    (*head)->head;
    if (value == -1){
        value = (*head)->tail->data;
        (*head)->tail->prev->next = NULL;
        return value;
    }

    return __pop__(&(*head)->head,value);
}

void traverse(Node *node){
    Node *temp = node;
    while (temp)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    
}
void __init__(doubleLinkedList **head){
    (*head) = (doubleLinkedList*)malloc(sizeof(doubleLinkedList));
    if ((*head) == NULL){
        Error("Head Memory allocation Failed __init__()",1);
    }
    (*head)->head = NULL;
    (*head)->tail = NULL;
}


int main(){
    doubleLinkedList *head;

    __init__(&head);
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    traverse(&*(head->head));
    pop(&head,30);
    traverse(&*(head->head));
}