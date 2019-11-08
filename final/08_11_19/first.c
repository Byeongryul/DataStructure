#include<stdio.h>
#define MAX 100
int arr[MAX][MAX];

void scan(int size){
	int i, j;
	for(i = 0; i < size; ++i){
        for(j = 0; j < size; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
}

void print(int size){
	int i, j;
	for(i = 0; i < size; ++i){
        for(j = 0; j < size; ++j){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main(void){
    int size, i, j, k;
    scanf("%d", &size);
    
    scan(size);
    
    for(k = 0; k < size; ++k){
        for(i = 0; i < size; ++i){
            for(j = 0; j < size; ++j){
                if(arr[i][j] == 0 && arr[k][j] == 1 && arr[i][k] == 1)
                	arr[i][j] = 1;
            }
        }
    }
    print(size);
    return 0;
}
