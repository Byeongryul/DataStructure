#include <stdio.h>
#include <stdlib.h>

typedef double element;

struct ListNode{
    element data;
    struct ListNode * link;
};

ListNode* GetNewNode(element data){
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

void InputNode(ListNode * node, element data){
    ListNode * temp = GetNewNode(data);
    temp->link = node->link;
    node->link = temp;
}

int main(int argc, char* argv[]){
    ListNode * Head = GetNewNode(0);
    ListNode * Next = GetNewNode(1);
    ListNode * temp = NULL;
    Head->link = Next;
    
    InputNode(Head, 2);

    for(temp = Head;temp != NULL;temp = temp->link){
        printf("%.1f ", temp->data);
    }
    return 0;
}
