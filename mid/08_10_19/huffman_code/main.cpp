#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct HC{
    int count, change;
    char origin;
};

struct PQ{
    HC* data;
    int size, index;
};

PQ* PQinit(){
    PQ *New = (PQ*)malloc(sizeof(PQ));
    New->data = (HC*)calloc(1, sizeof(HC));
    New->size = New->index = 1;
    return New;
}

int have_input(PQ* pq, char c){
    for(int i = 1; i < pq->size; ++i){
        if(pq->data[i].origin == c){
            pq->data[i].count++;
            return i;
        }
    }
    return 0;
}

void swap(HC* data, int index1, int index2){
    int count = data[index1].count;
    data[index1].count = data[index2].count;
    data[index2].count = count;
    char origin = data[index1].origin;
    data[index1].origin = data[index2].origin;
    data[index2].origin = origin;
}

void upSort(PQ* pq, int loc){
    HC *data = pq->data;
    while(loc > 1 && data[loc].count > data[loc / 2].count){
        swap(data, loc, loc/2);
    }
}

void input_c(PQ* pq, char c){
    int loc = have_input(pq, c);
    if(loc == 0){
        pq->data = (HC*)realloc(pq->data, sizeof(HC) * ++(pq->size));
        pq->data[pq->index].count = 1;
        pq->data[pq->index].origin = c;
        pq->index++;
    }
    else{
        upSort(pq, loc);
    }
}

void print_data(PQ* pq){
    for(int i = 1; i < pq->size; ++i){
        printf("문자:\'%c\' 개수:%d\n",pq->data[i].origin, pq->data[i].count);
    }
}

void input_pq(HC** hc, PQ* pq){
    *hc = (HC*)malloc(sizeof(HC) * pq->size - 1);
    for(int i = 0; pq->size != 1; ++i){
        (*hc)[i] = pq->data[1];
        pq->data[1] = pq->data[pq->size--];
    }
}

int main(int argc, char *argv[]){
    PQ* mypq = PQinit();    // 문자 체크
    HC* myhc = NULL;
    queue<char> str;        // 문자 원문
    char c;                 // 임시 저장

    printf("문자를 입력하세요:");
    while('\n' != (c = getc(stdin))){   //엔터까지 입력
        input_c(mypq, c);
        str.push(c);
    }

    print_data(mypq);

    input_pq(&myhc, mypq);

    for(int i = 0;i < mypq->index - 1; ++i){
        printf("%c %d\n", myhc[i].origin, myhc[i].count);
    }
    printf("\n");
    
    printf("%d %d\n",mypq->size, mypq->index);
    while(!str.empty()){
        printf("%c", str.front());
        str.pop();
    }
    printf("\n");
    return 0;
}
