#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char input[MAX];
char data[10][MAX];

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
    int count = 0;
    while(data[(key + count) % 10][0] != '\0' && count < 10){
        printf("Collision 발생\n");
        count++;
        printf("Linear Probing\n");
    }
    //Collision 발생 시, "Collision 발생" 출력 후 "Linear Probing" 수행
    if(count < 10)  strcpy(data[(key + count) % 10], input);
    else    printf("Full!\n");
}

void printData(){
    for(int i = 0; i < 10; ++i){
        printf("%d: %s\n", i, data[i]);
    }
}

void FunHashingQuiz(){
    int key = 0;
    while(1){
        //영어 단어를 입력 : 단, "exit" 입력시 프로그램 종료
        inputData();
        if(!strcmp(input, "exit")){
            return;
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
    FunHashingQuiz();
    return 0;
}
