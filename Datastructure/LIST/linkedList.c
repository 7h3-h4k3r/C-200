#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
    int data;
    struct Node *next; 
}Node;

void push(Node **head,int data);


int main(){
    Node* head = NULL;
    push(&head,10);
    push(&head,20);
    
}


void push(Node** head,int data){
    Node * new_node = (Node*)malloc(sizeof(Node));
    if (!new_node){
        perror("Memory allocation Failed");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    if (*(head) == NULL){
        *(head) = new_node;
    }else{
        new_node->next = *(head);
        *(head) = new_node;
    }
}