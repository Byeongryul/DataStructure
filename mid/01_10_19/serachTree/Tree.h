#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <queue>

using namespace std;

typedef int element;

struct Node{
    element data;
    Node *left, *right;
};

Node* TreeNodeInit(element data);

void print_tree(Node *root);

#endif
