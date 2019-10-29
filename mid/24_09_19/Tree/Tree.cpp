#include "Tree.h"

TreeNode* TreeNodeInit(element data){
    TreeNode *init = (TreeNode*)malloc(sizeof(TreeNode));
    init->data = data;
    init->left = init->right = NULL;
    return init;
}

void TreeNodeLink(TreeNode *left, TreeNode *med, TreeNode *right){
    med->left = left;
    med->right = right;
}

void preorder(TreeNode *root){//구조화 문서 출력
    if(root == NULL) return;
    printf("%d", (int)root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {//수식
    if(root == NULL) return;
    inorder(root->left);
    printf("%d", (int)root->data);
    inorder(root->right);
}

void postorder(TreeNode *root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", (int)root->data);
}
