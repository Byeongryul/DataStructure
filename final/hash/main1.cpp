#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char input[MAX];

typedef struct Link{
    char data[MAX];
    struct Link *link;
}Link;

Link* data[10];

void inputData(){
    printf("영어 단어를 입력: ");
    fgets(input, MAX, stdin);
    input[strlen(input) - 1] = '\0';
    printf("%s\n", input);
}

int hashFunc(){
    int key = 0;
    for(int i = 0; i < (int)strlen(input); ++i){
        key += input[i];
    }
    key %= 10;
    return key;
}

void pushFunc(int key){
    Link *temp = data[key];
    Link *value = (Link*)malloc(sizeof(Link));
    strcpy(value->data, input);

    if(temp == NULL){
        data[key] = value;
        return;
    }
    while(temp->link != NULL){
        printf("Collision 발생\n");
        temp = temp->link;
    }
        temp->link = value;
    //Collision 발생 시, "Collision 발생" 출력 후 "Linear Probing" 수행
}

void printData(){
    for(int i = 0; i < 10; ++i){
        printf("%d: ", i);
        for(Link* temp = data[i]; temp != NULL; temp = temp->link){
            printf("%s ", temp->data);
        }
        printf("\n");
    }
}

int FunHashingQuiz(){
    int key = 0;
    while(1){
        //영어 단어를 입력 : 단, "exit" 입력시 프로그램 종료
        inputData();
        if(!strcmp(input, "exit")){
            return 1;
        }
        //키 값을 생성하고
        key = hashFunc();
        //해당 키에 맞는 버킷에 넣고, 단 해시 테이블 버킷의 갯수는 10개
        pushFunc(key);
        //수행 후의 해시테이블 출력
        printData();
    }
}


int main(int argc, char* argv[]){
    while(1){
        
        if(FunHashingQuiz()){
            break;
        }
    }
    return 0;
}
