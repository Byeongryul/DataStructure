#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <list>
using namespace std;

vector<list<int>> map;

int main(int argc, char *argv[]){
    int size;
    printf("input size: ");
    scanf("%d", &size);

    for(int i = 0; i < size; ++i){
        map.push_back(list<int>());
    }

    list<int>::iterator itr;
    for(int i = 0; i < (int)map.size(); ++i){
        itr = map[i].begin();
        printf("%d -> ", i);
        for(itr = map[i].begin(); itr != map[i].end(); ++itr){
            printf("%d ", *itr);
        }
        printf("\n");
    }

    return 0;
}
