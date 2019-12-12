#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>
using namespace std;

#define MAX_VER 100
#define INF 1000

vector<int> parent;

void set_init(int n){
    for(int i = 0; i < n; ++i){
        parent.push_back(-1);
    }
}

int set_find(int curr){
    if(parent[curr] == -1){
        return curr;
    }
    while(parent[curr] != -1) curr = parent[curr];
    return curr;
}

void set_union(int n1, int n2){
    int root1 = set_find(n1);
    int root2 = set_find(n2);
    if(root1 != root2) parent[root1] = root2;
}

typedef struct Edge{
    int s, e, w;
}Edge;

typedef struct Graph{
    vector<Edge> edges;
}Graph;

Graph g;

void insert_edge(int s, int e, int w){
    Edge temp;
    temp.s = s;
    temp.e = e;
    temp.w = w;
    g.edges.push_back(temp);
}

bool compare(Edge a, Edge b){
    return a.w < b.w;
}

void kruskal(int v){
    int edge_accepted = 0;
    int uset, vset;
    Edge e;

    set_init(g.edges.size());

    sort(g.edges.begin(), g.edges.end(), compare);

    int i = 0;
    while(edge_accepted < v - 1){
        e = g.edges[i];
        uset = set_find(e.s);
        vset = set_find(e.e);
        if(uset != vset){
            printf("%d %d %d\n", e.s, e.e, e.w);
            edge_accepted++;
            set_union(uset, vset);
        }
        i++;
    }
}

int main(int argc, char* argv[]){
    insert_edge(0,1,29);
    insert_edge(1,2,16);
    insert_edge(2,3,12);
    insert_edge(3,4,22);
    insert_edge(4,5,27);
    insert_edge(5,0,10);
    insert_edge(6,1,15);
    insert_edge(6,3,18);
    insert_edge(6,4,25);

    kruskal(7);
    return 0;
}
