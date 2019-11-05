#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct {
    int n, weight[MAX_VERTICES][MAX_VERTICES];
} Graph;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

void init_settings(Graph *g, int v){
    for(int i = 0; i < g->n; ++i){
        distance[i] = g->weight[v][i];
    }
}

int search_v(Graph *g){
    int min = INF, index = -1;
    for(int i = 0; i < g->n ; ++i){
        if(found[i]) continue;
        if(min > distance[i]){
            min = distance[i];
            index = i;
        }
    }
    return index;
}

void check_len(Graph *g, int v){
    for(int i = 0; i < g->n; ++i){
        if(distance[i] > distance[v] + g->weight[v][i])
            distance[i] = distance[v] + g->weight[v][i];
    }
}

void shortest_path(Graph *g, int v){
    //초기화
    init_settings(g, v);
    found[v] = 1;

    for(int i = 0; i < g->n - 1; ++i){
        //가장 짧은 길이
        int u = search_v(g);
        found[u] = 1;

        //확인하고 합치기
        check_len(g, u);
    }
}

int main(int argc, char *argv[]){
    Graph g = { 7,
    {{ 0, 7, INF, INF, 3, 10, INF},
    {7, 0, 4, 10, 2, 6, INF},
    {INF, 4, 0, 2, INF, INF, INF},
    {INF, 10, 2, 0, 11, 9, 4},
    {3, 2, INF, 11, 0, INF, 5},
    {10, 6, INF, 9, INF, 0, INF},
    {INF, INF, INF, 4, 5, INF, 0}}
    };

    shortest_path(&g, 0);

    for(int i = 0; i < g.n; ++i){
        printf("%d ", distance[i]);
    }
    printf("\n");
    return 0;
}
