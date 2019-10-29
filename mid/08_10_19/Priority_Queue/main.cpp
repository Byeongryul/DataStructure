#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct PQ{
    int *data;
    int size,index;
};

PQ* PQ_init(int size){
    PQ* New = (PQ*)malloc(sizeof(PQ));
    New->data = (int*)malloc(sizeof(int) * (size + 1));
    New->size = size + 1;
    New->index = 0;
    return New;
}

bool PQ_full(PQ* pq){
    return pq->index == pq->size - 1;
}

bool PQ_emtry(PQ* pq){
    return pq->index == 0;
}

void upSwap(PQ *pq, int index){
    int temp = pq->data[index];
    pq->data[index] = pq->data[index / 2];
    pq->data[index / 2] = temp;
}

void upSort(PQ* pq){
    int index = pq->index;
    while(index > 1 && pq->data[index] > pq->data[index / 2]){
        upSwap(pq, index);
        index /= 2;
    }
}

void PQ_input(PQ* pq){
    int data = rand() % 100 + 1;
    printf("%d ", data);
    pq->data[++(pq->index)] = data;
    upSort(pq);
}

void downSwap(PQ *pq, int index1, int index2){
    int temp = pq->data[index1];
    pq->data[index1] = pq->data[index2];
    pq->data[index2] = temp;
}

void downSort(PQ* pq){
    int index = 1, big;
    while(index * 2 <= pq->index && (pq->data[index] < pq->data[index * 2] || pq->data[index] < pq->data[index * 2 + 1])){
        index *= big;
        big = pq->data[index * 2] > pq->data[index * 2 + 1] ? index * 2 : index * 2 + 1;
        downSwap(pq, index, big);
        index *= big;
    }
}

int PQ_find(PQ* pq){
    int result = pq->data[1];
    pq->data[1] = pq->data[(pq->index)--];
    downSort(pq);
    return result;
}

int main(int argc, char *argv[]){
    PQ* my_PQ = NULL;
    int size = 10;

    srand((unsigned int)time(0));
    //printf("size? :");
    //scanf("%d", &size);

    my_PQ = PQ_init(size);

    while(!PQ_full(my_PQ)){
        PQ_input(my_PQ);
    }

    printf("\n");

    for(int i = 0; i < size + 1; ++i){
        printf("%d ", my_PQ->data[i]);
    }

    printf("\n");

    while(!PQ_emtry(my_PQ)){
        printf("%d ", PQ_find(my_PQ));
    }
    printf("\n");

    return 0;
}
