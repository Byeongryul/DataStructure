#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main(int argc, char* argv[]){
    TreeNode *n1, *n2, *n3;
    n1 = TreeNodeInit(1);
    n2 = TreeNodeInit(2);
    n3 = TreeNodeInit(3);

    TreeNodeLink(n1, n2, n3);

    preorder(n2);
    printf("\n");

    inorder(n2);
    printf("\n");

    postorder(n2);
    printf("\n");
    return 0;
}
