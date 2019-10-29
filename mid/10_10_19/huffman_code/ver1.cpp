#include <stdio.h>
#include <stdlib.h>

#define PERIOD 26
#define SPACE 27

struct PQ{
    char key[28];
    int data[28], size, index;
};

PQ* PQinit(){
    PQ* New = (PQ*)malloc(sizeof(PQ));
    New->size = New->index = 1;
    for(int i = 0; i < 28; ++i) New->key[i +1] = 'a' + i;
    return New;
}

void PQinput(PQ* pq, int data){
    pq->data[++(pq->size)] = data;
    int size = pq->size;
    if(size > 1 && pq->data[size] < pq->data[size / 2]){
        int temp = pq->data[size];
        pq->data[size] = pq->data[size / 2];
        pq->data[size / 2] = temp;
        char ctemp = pq->key[size];
        pq->key[size] = pq->key[size / 2];
        pq->key[size / 2] = ctemp;
    }
    pq->index = pq->size;
}

void PQoutput(PQ* pq){
    printf("SORTED : ");
    while(pq->index != 1){
        printf("%c(%d), ", pq->key[1], pq->data[1]);
        pq->data[1] = pq->data[pq->index +1];
        pq->key[1] = pq->key[(pq->index)-- + 1];
        int index = 1, big;
        while(index * 2 <= pq->index && (pq->data[index] > pq->data[index * 2] || pq->data[index] > pq->data[index * 2 + 1])){
            big = pq->data[index * 2]<pq->data[index * 2 + 1] ? index * 2: index * 2 + 1;
           int temp = pq->data[index];
           pq->data[index] = pq->data[big];
           pq->data[big] = temp;
           char cemp = pq->key[index];
           pq->key[index] = pq->key[big];
           pq->key[big] = cemp;
           index*= big;
        }
    }
    printf("\b\b  ");
}

void input_string(char *string_count, char *high){
    char c;
    printf("Input String: ");
    while('\n' != (c = getc(stdin))){
        if('a' < c && c < 'z'){
            string_count[c - 'a']++;
            if(*high < c) *high = c;
        }
        else if(c == '.'){
            string_count[PERIOD]++;
            if(*high < c) *high = c;
        }
        else if(c == ' '){
            string_count[SPACE]++;
            if(*high < c) *high = c;
        }
    }
}

void print_data(char *c_count, char high){
    for(int i = 0; i < 26; ++i){
        if(c_count[i] != 0){
            printf("%c(%d)", char(i + 'a'), c_count[i]);
        printf(" / ");
        }
    }
    if(c_count[PERIOD] != 0){
        printf("%s(%d)", "PERIOD", c_count[PERIOD]);
        printf(" / ");
    }
    if(c_count[SPACE] != 0)
        printf("%s(%d)","SPACE", c_count[SPACE]);
        printf(" / ");
    printf("\b\b  \n");
}

void print_sort(char *c_count){
    PQ* New = PQinit();
    for(int i = 0; i < 26; ++i){
        if(c_count[i] != 0){
            PQinput(New, c_count[i]);
        }
    }
    PQoutput(New);
}

int main(int argc, char *argv[]){
    char c_count[28] = {0,}, high = 0;
    input_string(c_count, &high);
    print_data(c_count, high);
    printf("\n");
    print_sort(c_count);
    return 0;
}
