
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;


typedef struct Vertax{
    int vertax;
    Node *edge;
}Vertax;

typedef struct Graph{
    Vertax *v;
    struct Graph *next;
}Graph;

Vertax* init_vertax(int value){
    Vertax *init = (Vertax*)malloc(sizeof(Graph));
    if (init == NULL){
        fprintf(stderr,"Memory allocation Failed bro init__vertax()");
        return NULL;
    }
    init->vertax = value; 
    init->edge = NULL;
    return init;
}

Node* init_list(int edge){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL){
        fprintf(stderr,"Memory allocation Failed bro init__list()");
        return NULL;
    }
    new_node->value =  edge;
    return new_node;
}
// void AddingEdge(Node **head ,int vertax){
//     Node *new_vetax = init_vertax(vertax);
//     if (head == NULL){
//         *head = new_vetax;
//         return;
//     }
//     Node *temp = *head;
//     while(temp){
//         temp = temp->next;
//     }
//     temp->next = new_vetax;
// }

int AddingVertax(Graph **vertax,int key){
    Graph *newGraph = (Graph*) malloc(sizeof(Graph));
    if (newGraph == NULL){
        printf("Memory allocation Failed");
        return -1;
    }
    newGraph->v = init_vertax(key);
    newGraph->next = NULL;
    if (*vertax == NULL){
        
        *vertax  = newGraph;

        return 1;
    }
    Graph *temp  = *vertax;
    while (temp->next != NULL)
    {
        temp = temp->next;        
    }
    temp->next = newGraph;
    
}

int main(){
    Graph *graph;
    graph = NULL;
    AddingVertax(&graph,10);
    AddingVertax(&graph,20);
    AddingVertax(&graph,30);
}