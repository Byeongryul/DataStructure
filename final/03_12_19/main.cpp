#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <algorithm>
using namespace std;

void scan(int *n, int *k, int *m){
    printf("Input Number range(N): ");
    scanf("%d", n);

    printf("Input Array size(K): ");
    scanf("%d", k);
    
    printf("Input Index insterval (M): ");
    scanf("%d", m);
}

void setting(int n, int k, int m, vector<int> &arr, vector<int> &index){
    for(int i = 0; i < k;++i){
        arr.push_back(rand() % n + 1);
    } 
    sort(arr.begin(), arr.end());
}

void settingPrint(int n, int k, int m, vector<int> &arr, vector<int> &index){
    printf("%d random numbers[1:%d] are generated\n", k, n);
    printf("[");
    for(int i = 0; i < (int)arr.size(); ++i){
        printf("%d,", arr[i]);
    }
    printf("\b]\n\n");

    printf("Index:\n");
    for(int i = 0; i * m < k; ++i){
        index.push_back(arr[i * m]);
        printf("%d->%d\n", index[i], i * m);
    }
    printf("\n");
}

int seq_sea_find(int key, vector<int> &arr){
    for(int i = 0; i < (int)arr.size(); ++i){
        if(arr[i] == key) return key;
    }
    return -1;
}

int seq_sea(int key, vector<int> &arr){
    int count = 0;
    for(int i = 0; i < (int)arr.size(); ++i){
        ++count;
        if(arr[i] == key) return count;
    }
    return count;
}

int index_sea(int key, int m, vector<int> &arr, vector<int> &index){
    int s, e;
    int count = 0;
    if(key < index[0]) return ++count;
    else{
        for(int i = 1; i < (int)index.size(); ++i){
            ++count;
            if(key < index[i]){
                s = m * (i - 1);
                e = m * i;
            }
        }
    }
    for(int i = s; i <= e; ++i){
        ++count;
        if(key == arr[i]){
            return count;
        }
    }
    return count;
}

void playing(int n, int k, int m, vector<int> &arr, vector<int> &index){
    int seaN;
    while(1){
        printf("Input Search Number: ");
        scanf("%d", &seaN);
        if(seq_sea_find(seaN, arr) != -1){
            printf("SUCCESS");
        }
        else{
            printf("FAIL");
        }
        
        printf("(Indexed: %d, Seq: %d)\n", index_sea(seaN, m, arr, index), seq_sea(seaN, arr));
    }
}

int main(int argc, char *argv[]){
    srand((unsigned int)time(NULL));
    int n, k, m;
    vector<int> arr;
    vector<int> index;

    scan(&n, &k, &m);

    setting(n, k, m, arr, index);

    settingPrint(n, k, m, arr, index);

    playing(n, k, m, arr, index);

    return 0;
}
