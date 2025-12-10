
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    void *value;
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


int enQ(Node **head , Vertax *vertax){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node== NULL){
        printf("Memory allocation failed");
        return -1;
    }
    new_node->value = vertax;
    new_node->next = NULL;
    if (*head == NULL){
        *head = new_node;
        return 1;
    } 

    Node *temp = *head;
    while ( temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    
}

int dQ(Node **head){
    *head = (*head)->next;
}

int isempty(Node *head){
    if (head==NULL){
        return 1;
    }
    return -1;
}
Vertax* init_vertax(int value){
    Vertax *init = (Vertax*)malloc(sizeof(Vertax));
    if (init == NULL){
        fprintf(stderr,"Memory allocation Failed bro init__vertax()");
        return NULL;
    }
    init->vertax = value; 
    init->edge = NULL;
    return init;
}




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
Vertax * get_vertax(Graph **vertax,int num){
    Graph *temp = *vertax;
    while (temp)
    {
        if(temp->v->vertax == num){
            return temp->v;
        }
        temp = temp->next;
    }
    return NULL;
}
int add_edge(Graph **graph,int v1 , int v2){
    // Direct Graph 
    Vertax *vertax1 = get_vertax(graph,v1);
    if(vertax1==NULL){
        fprintf(stderr,"(Value Error)vertax %d is not found",v1);
        return -1;
    }
    Vertax *vertax2 = get_vertax(graph,v2);
    if(vertax2==NULL){
        fprintf(stderr,"(Value Error)vertax %d is not found",v2);
        return -1;
    }
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value  = vertax2;
    if (new_node == NULL){
        printf("Memory allocation Failed add_edge()");
        return -1;
    }
    Node *temp = vertax1->edge;
    if(temp==NULL){
        vertax1->edge = new_node;
        return 1;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    
}

void breathFirstSearch(Graph **graph ,int start){
    Vertax *visited = get_vertax(graph,start);
    //to Already exist functin not writen
    Node *q = NULL;
    enQ(&q,visited);
    while (q)
    {
        Vertax *v = (Vertax *)q->value;
        printf("\nVisited : %d ->",v->vertax);

        Node *e = v->edge;
        while (e)
        {
            Vertax *neighbor = (Vertax *)e->value;
            printf("Neighbor : %d ",neighbor->vertax);
            enQ(&q,neighbor);
            e = e->next;
        }
        printf("\n");
        dQ(&q);
    }
    

}
int main(){
    Graph *graph;
    graph = NULL;
    AddingVertax(&graph,10);
    AddingVertax(&graph,20);
    AddingVertax(&graph,30);
    add_edge(&graph,10,20);
    add_edge(&graph,10,30);
    add_edge(&graph,20,30);
    printf("Debuggind\n");
    breathFirstSearch(&graph,10);
}