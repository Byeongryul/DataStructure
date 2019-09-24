#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct node* next;
};

Node * AllocNewNode(int value){
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void AllocNewNodePP(Node **node, int value){
    *Node = AllocNewNode(value);
}
int main(int argc, char* argv[]){
    Node *head = NULL;
    AllocNewNodePP(&head, 20);
    printf("%d ", head->value);

    printf("\n");
    return 0;
}
