#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int data;
    struct ListNode* link;
};

void PrintMenu(){
    printf("메뉴)\n");
    printf("1.\t원소 등록\n");
    printf("2.\t원소 삭제\n");
    printf("3.\t원소 내역\n");
    printf("4.\t원소 검색\n");
    printf("5.\t원소 개수\n");
    printf("6.\t종료\n");
    printf("입력) ");
}

void DisplayList(ListNode **node){
    printf("List = ");
    if(*node == NULL){
        printf("Empty");
    }
    else{
        for(ListNode *p = *node; p != NULL; p = p->link){
            printf("%d ", p->data);
        }
    }
    printf("\n");
}
/*
void AddList(ListNode **node){
    int n;
    ListNode *temp;
    printf("동록원소) ");
    scanf("%d", &n);
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = n;
    newNode->link = NULL;
    if(*node == NULL){
        *node = newNode;
    }
    else{
        for(temp = *node; temp->link != NULL; temp = temp->link);
        temp->link = newNode;
    }
    DisplayList(node);
}
*/

void AddList(ListNode** head){
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    int num;
    printf("등록원소) ");
    scanf("%d", &num);
    tmp->data = num;
    tmp->link = NULL;
    if(*head==NULL){
        *head=tmp;
    }
    else{
        while((**head).link!=NULL){
            *head=((*head)->link);
        }
        (**head).link=tmp;
    }
}
void RemoveList(ListNode **node){
    int n;
    ListNode *Remove = *node;
    printf("삭제원소) ");
    scanf("%d", &n);
    if(*node != NULL && Remove->data == n){
        *node = Remove->link;
        if(Remove != NULL)  free(Remove);
        DisplayList(node);
        return;
    }
    if(*node != NULL){
        for(Remove = *node; Remove->link != NULL; Remove = Remove->link){
            if(Remove->data == n){
                break;
            }
        }
        for(ListNode *temp = *node; temp->link != NULL; temp = temp->link){
            if(temp->link == Remove){
                temp->link = Remove->link;
                free(Remove);
                break;
            }
        }
    }
    DisplayList(node);
}

void FindList(ListNode **node){
    int n;
    printf("검색원소) ");
    scanf("%d", &n);
    if(*node == NULL){
        printf("존재하지 않음\n");
    }
    else{
        for(ListNode *temp = *node; temp != NULL; temp = temp->link){
            if(temp->data == n){
                printf("존재함\n");
                return;
            }
        }
    }
    printf("존재하지 않음\n");
}

void GetSize(ListNode **node){
    int n = 0;
    if(*node == NULL){
        printf("존재하지 않음");
    }
    else{
        for(ListNode *temp = *node; temp != NULL; temp = temp->link){
            n++;
        }
        printf("%d개 있음", n);
    }
    printf("\n");
}

void FreeList(ListNode **node){
    ListNode *p = *node;
    if(*node == NULL)   return;
    for(ListNode *temp = (*node)->link; temp != NULL; temp = temp->link){
        free(*node);
        *node = temp;
    }
    free(p);
}

int main(int argc, char* argv[]){
    ListNode *head = NULL;
    int input = 0, loop = 1;

    while(loop){
        PrintMenu();
        scanf("%d", &input);
        switch(input){
            case 1: AddList(&head);     break;
            case 2: RemoveList(&head);  break;
            case 3: DisplayList(&head); break;
            case 4: FindList(&head);    break;
            case 5: GetSize(&head);     break;
            case 6: loop = 0;           break;
            default: printf("Wrong input..\n");
        }
    }
    FreeList(&head);
    return 0;
}
