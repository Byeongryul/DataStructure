#include <stdio.h>
#include "Tree.h"

Tree* treeInit(int size){
    Tree *new = (Tree*)malloc(sizeof(Tree));
    new->data = (int*)malloc(sizeof(int)*size);
    new->size = size;
    return new;
}

void treeDel(Tree* temp){
    free(temp->data);
    free(temp);
}


