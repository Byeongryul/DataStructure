#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph{
    int data[MAX][MAX];
    int n;
};

Graph* init(){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->n = 0;
    for(int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            g->data[i][j] = 0;
        }
    }
    return g;
}

void inputVectex(Graph *g){
    if(g->n <= MAX)
        printf("불가능\n");
    else
        ++(g->n);
}

int main(int argc, char *argv[]){
    Graph *g = init();
    inputVectex(g);

    return 0;
}
