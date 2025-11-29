#include <stdio.h>
#include <stdlib.h>


typedef struct binTree
{
    int data;
    struct binTree *left;
    struct binTree *right;

}binTree;


binTree *mlnode(int value){
    binTree *new_value = (binTree*)malloc(sizeof(binTree));
    if (new_value == NULL){
        printf("Memory allocation Failed");
        exit(-1);
    }

    new_value->data = value;
    new_value->left , new_value->right = NULL;
    return new_value;
}

void __init__(binTree *s){
    s->data = -1;
}
int insert(binTree *s,int data){
    if (s->data==-1){
        s->data = data;
        return 0;
    }

    if (s->data < data){
        if(s->right == NULL){
            s->right = mlnode(data);
            return 0;
        }
        else{
            insert(s->right,data);
        }
    }
    else{
        if(s->left == NULL){
            s->left = mlnode(data);
            return 0;
        }
        else{
            insert(s->left,data);
        }
    }
}


int main(){
    binTree *bst;
    bst = (binTree*)malloc(sizeof(binTree));
    __init__(bst);
    insert(bst,10);
    
    insert(bst,20);
    insert(bst,5);
    insert(bst,3);
    insert(bst,4);
}