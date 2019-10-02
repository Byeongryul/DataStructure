#include "quiz.h"

enum Option{
    Search, Insert, Delete
};

void print_not_found(){
    printf("존재하지 않습니다!\n");
}

void search_tree_all(Node **Root, Node *input, Option option, bool is_See){
    Node *root = *Root, *parent = NULL;
    //root가 없거나, 입력값이 현재 위치면 멈춤
    while(root == NULL || root->data == input->data){
        //부모노드를 설정함
        parent = root;
        //입력값을 찾기 위해 왼쪽으로 이동
        if(root->data > input->data)      root = root->left;
        //입력값을 찾기 위해 오른쪽으로 이동
        else if(root->data < input->data) root = root->right;
    }
    if(root == NULL){
        //모든 값이 존재하지 않음
        if(parent == NULL){
            switch(option){
                case Search:
                    //print_not_found();
                    break;
                case Insert:

                    break;
                case Delete:
                    print_not_found();
                    break;
            }
        }
        //입력값이 존재하지 않음
        else{
            switch(option){
                case Search:
                    //print_not_found();
                    break;
                case Insert:
                    break;
                case Delete:
                    print_not_found();
                    break;
            }
        }
    }
    else{
        //입력값이 root값
        if(parent == NULL){
            switch(option){
                case Search:
                    break;
                case Insert:
                    break;
                case Delete:
                    break;
            }
        }
        //입력값이 가운대 존재함
        else{
            switch(option){
                case Search:
                    break;
                case Insert:
                    break;
                case Delete:
                    break;
            }
        }
    }
}

element num_rand(){
    int range = NUM_RANGE_MAX - NUM_RANGE_MIN + 1;
    return rand() % range + NUM_RANGE_MIN;
}

void Insert_tree(Node **root){
    element data = num_rand();

    while(search_tree(*root, data) != NULL) data = num_rand();

    printf("입력 값: %d\n", data);

    Node *New = TreeNodeInit(data);
    if(*root == NULL) *root = New;
    else inserttree(*root, New);
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
