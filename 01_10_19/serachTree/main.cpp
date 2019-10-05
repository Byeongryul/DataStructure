#include "quiz.h"

int main(int argc, char *argv[]){
    if(!define_is_ok()){
        return 0;
    }

    srand((unsigned int)time(NULL));
    
    Node *root = NULL;

    for(int i = 0; i < MAX_INPUT; ++i){
        insert_tree(&root);
        print_tree(root);
    }
    
    printf("지울 수 있는 기회는 %d번!\n", MAX_OUTPUT);
    for(int i = 0; i < MAX_OUTPUT; ++i){
        delete_tree(&root);
        print_tree(root);
    }
    
    return 0;
}
