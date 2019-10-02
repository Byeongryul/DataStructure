#include <stdlib.h>

struct TreeNode{
    int data;
    TreeNode *left, *right;
};

int evaluate(TreeNode *root){
    if(root == NULL) return 0;
    else if(root->left == NULL && root->right == NULL) return root->data;
    else{
        int temp;
        switch(root->data){
            case '+':
                temp = evaluate(root->left) + evaluate(root->right);
                break;
            case '-':
                temp = evaluate(root->left) - evaluate(root->right);
                break;
            case '*':
                temp = evaluate(root->left) * evaluate(root->right);
                break;
            case '/':
                temp = evaluate(root->left) / evaluate(root->right);
                break;
        }
        return temp;
    }
}

int main(int argc, char *argv[]){
    return 0;
}
