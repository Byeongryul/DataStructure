#include <stdio.h>

#include <vector>
using namespace std;

vector<vector<int>> map;

int main(int argc, char* argv[]){
    int size;
    printf("graph size: ");
    scanf("%d", &size);

    for(int i = 0; i < size; ++i){
        map.push_back(vector<int>());
        for(int j = 0; j < size; ++j){
            map[i].push_back(0);
        }
    }

    for(int i = 0; i < (int)map.size(); ++i){
        for(int j = 0; j < (int)map[i].size(); ++j){
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
