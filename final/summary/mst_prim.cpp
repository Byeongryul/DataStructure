#include <stdio.h>
#include <stdlib.h>

#include <vector>
using namespace std;

#define INF 1000

typedef struct Graph{
    int n;
    vector<vector<int>> weight;
}Graph;

Graph g;

vector<bool> selected;
vector<int> Distance;

int get_min_vertex(int n){
    int v;
    for(int i = 0; i < n; ++i)
        if(!selected[i]){
            v = i;
            break;
        }
    for(int i = 0; i < n; ++i){
        if(!selected[i] && (Distance[i] < Distance[v])) v = i;
    }
    return v;
}

void prim(int s){
    int i, u, v;

    for(u = 0; u < g.n; ++u){
        Distance[u] = INF;
        selected[u] = false;

    }
    Distance[s] = 0;

    for(i = 0; i < g.n; ++i){
        u = get_min_vertex(g.n);
        selected[u] = true;
        if(Distance[u] == INF) return;
        printf("%d\n", u);
        for(v = 0; v < g.n; v++){
            if(g.weight[u][v] != INF)
                if(!selected[v] && g.weight[u][v] < Distance[v])
                    Distance[v] = g.weight[u][v];
        }
    }
}

void setting(int n){
    g.n = n;
    int input;
    printf("자료 입력: \n");
    for(int i = 0; i < n; ++i){
        g.weight.push_back(vector<int>());
        for(int j = 0; j < n; ++j){
            //scanf("%d", &input);
            if(input >= 0)
                g.weight[i].push_back(input);
            else 
                g.weight[i].push_back(INF - 1);
        }
    }
}

int main(int argc, char* argv[]){
    setting(7);
    prim(0);
    return 0;
}
