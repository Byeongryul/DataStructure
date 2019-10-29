#include <stdio.h>
#include <stdlib.h>

typedef int element;

struct ListNode{
    element data;
    struct ListNode *link;
};

void PrintListData(const char* String, ListNode * node){
    printf("%s%d\n",String, node->data);
}

ListNode* GetNewNode(element data){
    ListNode *list1 = (ListNode*)malloc(sizeof(ListNode));
    list1->data = data;
    return list1;
}

void Assign(ListNode ** node, ListNode * node2){
    *node = node2;
}

int main(int argc, char* argv[]){
    ListNode *list1 = (ListNode*)malloc(sizeof(ListNode));
    list1->data = 100;
    PrintListData("list1->data = ", list1);
    
    ListNode *list2 = GetNewNode(1);
    PrintListData("list1->data = ", list2);

    ListNode *p = NULL;
    Assign(&p, list2);
    p->data = 10;
    PrintListData("list1->data = ", list2);
    
    free(list1);
    free(list2);
    return 0;
}
