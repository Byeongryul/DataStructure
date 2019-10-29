#include <stdio.h>
#include <stdlib.h>
#ifndef TREE_H
#define TREE_H
typedef int element;

struct TreeNode{
    element data;
    struct TreeNode *left, *right;
};

TreeNode* TreeNodeInit(element data);

void TreeNodeLink(TreeNode *left, TreeNode *med, TreeNode *right);

void preorder(TreeNode *root);

void inorder(TreeNode *root);

void postorder(TreeNode *root);
#endif
