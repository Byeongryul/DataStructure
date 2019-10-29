#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

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

void TreeNodeLink(Node *left, Node *mid, Node *right){
    mid->left = left;
    mid->right = right;
}

Node* make_tree(){
    Node* root = TreeNodeInit(1);
    Node* n2 = TreeNodeInit(2);
    Node* n3 = TreeNodeInit(3);
    Node* n4 = TreeNodeInit(4);
    Node* n5 = TreeNodeInit(5);
    Node* n6 = TreeNodeInit(6);
    Node* n7 = TreeNodeInit(7);
    
    TreeNodeLink(n2, root, n3);
    TreeNodeLink(n4, n2, NULL);
    TreeNodeLink(n5, n3, n6);
    TreeNodeLink(NULL, n5, n7);
    
    return root;
}

void level_order(Node *root){
    queue <Node *> q;
    printf("[Level Order]\t");

    q.push(root);
    while (!q.empty()){
        root = q.front();
        q.pop();
        printf(" %d", root->data);
        if(root->left != NULL) q.push(root->left);
        if(root->right != NULL) q.push(root->right);
    }
    printf("\n");
}

void preorder(Node *root){//구조화 문서 출력
    if(root == NULL) return;
    printf(" %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void pre_order(Node *root){//구조화 문서 출력
    printf("[Pre order]\t");
    preorder(root);
    printf("\n");
}

void findleafnodes(Node *root){
    if(root == NULL) return;
    findleafnodes(root->left);
    findleafnodes(root->right);
    if(root->left == NULL && root->right == NULL){
        printf(" %d", root->data);
    }
}

void find_leafnodes(Node *root){
    printf("[Leaf nodes]\t");
    findleafnodes(root);
    printf("\n");
}

int Sum(Node *root){
    if(root == NULL) return 0;
    return Sum(root->left) + Sum(root->right) + root->data;
}

void sum(Node *root){
    printf("[sum]\t\t");
    printf(" %d\n", Sum(root));
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
            else printf("X");
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
    printf("height :\t %d\n", height);

    int size = check_size(root);              //높이에 비례하는 최대 공간
    printf("size :\t\t %d\n", size);

    Q **Root = make_array(root, size);   //배열에 알맞은 노드 넣기
    print_array(Root, size);

    int tap = check_tap(height);            //얼마나 들여쓸지 확인
    printf("first tap :\t %d\n", tap);

    printf("\n\n");
    printtree(Root, height, tap, size);
    printf("\n\n");
}

int main(int argc, char *argv[]){
    Node* root = make_tree();
    level_order(root);
    pre_order(root);
    find_leafnodes(root);
    sum(root);
    print_tree(root);
    return 0;
}
