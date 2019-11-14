#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

typedef int Type;

vector<Type> arr;

void setData(){
	int inputSize = 30;
	srand((unsigned int)time(NULL));
	for(int i = 0; i < inputSize; ++i){
		arr.push_back(rand() % 10);
	}
}

void print(){
	for(int i = 0; i < arr.size(); ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sltSort(){
	int loc
	Type temp;
	for(int i = 0; i < arr.size(); ++i){ 
		loc = i;
		for(int j = i + 1; j < arr.size(); ++j){
			if(arr[loc] < arr[j]){
				temp = arr[loc];
				arr[loc] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void istSort(){
	Type temp;
	
}

int main(int argc, char *argv[]){
	for(int i = 0; i < 3; ++i){
		setData();
		print();
		sltSort();
		print();
		arr.clear();
	}
	return 0;
}
