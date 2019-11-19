#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <vector>
using namespace std;
#include <unistd.h>
#include "logger.h"
#include <math.h>
vector<int> arr;
vector<int> tmp;
int temp;

void print(){
	for(int i = 0; i < 100 && i < tmp.size(); ++i){
		printf("%d ", tmp[i]);

	}
	printf("\n");
}

void istSort(){
	struct timeval f, e;
	int i, j;
	gettimeofday(&f, NULL);
	int loc;
	for(int i = 0; i < tmp.size(); ++i){
		loc = tmp[i];
		for(j = i - 1; j>=0 && tmp[j]>loc; --j){
				tmp[j+1] = tmp[j];
		}
		tmp[j+1] = loc;
	}
	gettimeofday(&e, NULL);
	print();
	printf("%.1f \n", fabs((e.tv_sec - f.tv_sec) + (e.tv_usec - f.tv_usec)/100000.0));
}

void sltSort(){
	struct timeval f, e;
  int loc; 
	gettimeofday(&f, NULL);
	for(int i = 0; i < tmp.size() - 1; ++i){
	  loc = i;
		for(int j = i + 1; j < tmp.size(); ++j){
			if(tmp[loc] > tmp[j]) loc = j;
		}
		if(loc != i){
			temp = tmp[loc];
			tmp[loc] = tmp[i];
		 	tmp[i] = temp;
		}
	}
	gettimeofday(&e, NULL);
	print();
	printf("%.1f \n", fabs((e.tv_sec - f.tv_sec) + (e.tv_usec - f.tv_usec)/100000.0));
}

void bbSort(){
	struct timeval f, e;
	gettimeofday(&f, NULL);
	for(int i = tmp.size() - 1; i > 0; --i){
		for(int j = 0; j < i; ++j){
			if(tmp[j] > tmp[j+1]){
				temp = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = temp;
			}
		}
	}
	gettimeofday(&f, NULL);
	print();
	printf("%.1f \n", fabs((e.tv_sec - f.tv_sec) + (e.tv_usec - f.tv_usec)/100000.0));
}

int main(int argc, char *argv[]){
	int size;
	srand((unsigned int)time(NULL));
	scanf("%d", &size);
	for(int i = 0; i < size; ++i){
		arr.push_back(rand() % size);
	}
	

	for(int i = 0; i < arr.size(); ++i){
		tmp.push_back(arr[i]);
	}
	print();
	istSort();
	for(int i = 0; i < arr.size(); ++i){
		tmp[i] = arr[i];
	}
	sltSort();
	for(int i = 0; i < arr.size(); ++i){
		tmp[i] = arr[i];
	}
	bbSort();	
	return 0;
}
