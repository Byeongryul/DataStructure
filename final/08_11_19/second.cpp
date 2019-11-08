#include <stdio.h>
#include <vector>

#define MAX_V 500
#define MAX_DIS 100001

int timer[MAX_V];
int is_visit[MAX_V];

int next[(MAX_V * MAX_V - MAX_V) / 2];
int haveNext[MAX_V];

int main(int argc, char *argv[]){
	int size;
	scanf("%d", &size);	

	for(int i = 0; i < size; ++i){
		scanf("%d", &timer[i]);
	}
	return 0;
}
