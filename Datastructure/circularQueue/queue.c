
#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
}queue;


typedef struct HeadNode
{
    queue *head;
    queue *tail;
}HeadNode;

int enqueue(HeadNode **head, int value){
    queue *n = (queue*)malloc(sizeof(queue));
    n->data = value;
    if((*head)->head==NULL){
        (*head)->head = n;
        (*head)->tail = n;
        (*head)->head->next = (*head)->tail;
        (*head)->tail->next = (*head)->head;    
	return 0;    
}
    
    (*head)->tail->next = n;
    (*head)->tail->next->next = (*head)->head;
   


}

int main(){
    HeadNode *h;
    h->head = NULL;
    h->tail = NULL;
    enqueue(&h,10);
    enqueue(&h,20);
    enqueue(&h,30);
}


