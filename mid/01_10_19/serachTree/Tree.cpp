#include "Tree.h"

struct Q{
    Node *data;
    int loc;
};

Node* TreeNodeInit(int data){
    Node* newTreeNode = (Node*)malloc(sizeof(Node));
    newTreeNode->data = data;
    newTreeNode->left = newTreeNode->right = NULL;
    return newTreeNode;
}

void check_height(Node *root, int now, int *max){//높이 계산
    if(root == NULL){
        if(now > *max) *max = now;
        return;
    }
    check_height(root->left, now + 1, max);
    check_height(root->right, now + 1, max);
}

Q* QInit(Node *data, int loc){
    Q* New = (Q*)malloc(sizeof(Q));
    New->data = data;
    New->loc = loc;
    return New;
}

Q** make_array(Node *root, int size){//배열 만들기
    Q **Root =  (Q**)malloc(sizeof(Q*) * size);
    int i = 0, loc = 1;
    queue <Node *> q;
    q.push(root);
    while(i < size){
        root = q.front();
        if(root != NULL){
            Root[i++] = QInit(root, loc);
        }
        q.pop();
        loc++;
        if(root != NULL){
            q.push(root->left);
            q.push(root->right);
        }
        else{
            q.push(NULL);
            q.push(NULL);
        }
    }
    return Root;
}

void print_array(Q **Root, int size){//배열 출력
    printf("array :\t\t");
    for(int i = 0; i < size; ++i){
        printf(" array[%d] = %d", Root[i]->loc, Root[i]->data->data);
    }
    printf("\n");
}

int check_tap(int height){//들여쓰기 알기
    int tap = 1;
    if(height == 1) tap = 0;
    else for(int i = 2; i < height; tap = tap * 2 + 1, ++i);
    return tap;

}

void print_tap(int tap){
    for(int i = 0;i < tap; ++i){
        printf(" ");
    }
}

void printtree(Q **Root, int height, int tap, int size){
    int loc = 1, count = 0;
    tap *= 2;
    for(int i = 0; i < height; ++i){
        print_tap(tap / 2);
        for(int j = 0; j < pow(2, i); ++j){
            if(count == size) break;
            if(Root[count]->loc == loc++){
                printf("%d", Root[count++]->data->data);
            }
            else printf("N");
            print_tap(tap);
        }
        tap /= 2;
        printf("\n");
    }
}

int check_size(Node *root){
    if(root == NULL) return 0;
    return check_size(root->left) + check_size(root->right) + 1;
}

void print_tree(Node *root){
    printf("\n");

    int height = 0;                         //높이 계산
    check_height(root, 0, &height);

    int size = check_size(root);              //높이에 비례하는 최대 공간

    Q **Root = make_array(root, size);   //배열에 알맞은 노드 넣기

    int tap = check_tap(height);            //얼마나 들여쓸지 확인

    printtree(Root, height, tap, size);
    printf("\n");
}
