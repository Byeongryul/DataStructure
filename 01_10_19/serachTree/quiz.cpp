#include "quiz.h"

element num_rand(){
    int range = NUM_RANGE_MAX - NUM_RANGE_MIN + 1;
    return rand() % range + NUM_RANGE_MIN;
}
  
Node* search_tree(Node *root, element data){// 존재여부 확인
    if(root == NULL) return NULL;// 없으면 NULL 출력
    else if(root->data == data) return root;// 있다면 그 노드를 출력
    else if(root->data > data) return search_tree(root->left, data);//노드의 정보가 더 크면 왼쪽으로
    else return search_tree(root->right, data);//노드의 정보가 더 작으면 오른쪽으로
}

void inserttree(Node *root, Node *New){//추가할 위치 탐색 밑 추가
    if(root->data > New->data){
        if(root->left != NULL)
            inserttree(root->left, New);
        else
            root->left = New;
    }
    else if(root->data < New->data){
        if(root->right != NULL)
            inserttree(root->right, New);
        else
            root->right = New;
    }
}


void insert_tree(Node **root){
    element data = num_rand();

    while(search_tree(*root, data) != NULL) data = num_rand();

    printf("입력 값: %d\n", data);

    Node *New = TreeNodeInit(data);
    if(*root == NULL) *root = New;
    else inserttree(*root, New);
}

Node* deep_remove(Node **Root){
    Node *temp = *Root, *root = (*Root)->left;
    if(root->right != NULL){
        while(root->right->right != NULL) root = root->right;
        temp = root->right;
        root->right = temp->left;
    }
    else{
        temp = root;
        (*Root)->left = root->left;
    }
    return temp;
}

Node* select_remove(Node **root, Node *remove){
    Node *temp = *root;
    if(remove->left == NULL && remove->right == NULL){
        temp = NULL;
        free(remove);
    }
    else if(remove->left == NULL){
        temp = remove->right;
        free(remove);
    }
    else if(remove->right == NULL){
        temp = remove->left;
        free(remove);
    }
    else{
        temp = deep_remove(&remove);
        if(remove->left != temp)
            temp->left = remove->left;
        temp->right = remove->right;
        free(remove);
    }
    return temp;
}

void deletetree(Node **Root, Node *remove){//부모 노드를 알아냄
    Node *root = *Root;
    if(root->left == remove){
        root->left = select_remove(Root, remove);
    }
    else if(root->right == remove){
        root->right = select_remove(Root, remove);
    }
    else if(root == remove){
        *Root = select_remove(Root, remove);
    }
    else if(root->data > remove->data) deletetree(&(root->left), remove);
    else if(root->data < remove->data) deletetree(&(root->right), remove);
}

void delete_tree(Node **root){
    int data;
    printf("지울 값: ");
    scanf("%d", &data);

    Node *remove = search_tree(*root, data); // 지울값 확인
    if(remove == NULL) printf("존재하지 않습니다\n");
    else deletetree(root, remove); 
}
