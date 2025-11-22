#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
    int data;
    struct Node *next; 
}Node;

void push(Node **head,int data);
int peek(Node **head);
int del(Node **head, int remove);
void output(Node **head);
int pop(Node **head);
int main(){
    Node* head = NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    peek(&head);
    del(&head,30);
    del(&head,40);
    printf(" pop () %d \n",pop(&head));
    printf(" Treaverse output() \n");
    output(&head);
    
}


void push(Node **head,int data){
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

int peek(Node **head){
    if (*(head) == NULL){
        fprintf(stderr,"List is Empty");
        return -1;
    }

    return (*head)->data;
}
int pop(Node **head){
    if ((*head) == NULL){
        fprintf(stderr,"List is Empty");
        return -1;
    }
    int value = (*head)->data;
    *head = (*head)->next;
    return value;
}
int del(Node **head,int remove){
    if (*(head) == NULL){
        fprintf(stderr,"List is Empty ");
        return -1;
    }
    
   Node *temp = *head;
   Node *prev = NULL;

   while (temp)
   {   
        if (temp->data == remove){
            prev->next = temp->next;
            break; 
        }
        prev = temp;
        temp = temp->next;
   }



}

void output(Node **head){
    Node *last =  *head;
    while (last)
    {
        if(last->next){
            printf(" %d -> ",last->data);
        }
        else{
            printf("%d ",last->data);
        }
        
        last = last->next;
    }
    printf("\n");
}