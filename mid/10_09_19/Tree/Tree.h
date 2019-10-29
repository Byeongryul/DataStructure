#ifndef TREE_H
#define TREE_H

typedef struct{
    int *data;
    int size;
}Tree;

Tree* treeInit(int size);
void treeDel(Tree* temp);


#endif
