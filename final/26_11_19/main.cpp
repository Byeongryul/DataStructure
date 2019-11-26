#include <stdio.h>
#include <stdlib.h>

int seq_search(int* arr, int val, int size){
	for(int i = 0; i < size; ++i){
		if(arr[i] == val) 0;
	}
	return 1;
}

int main(int argc, char* argv[]){
	int arr[10] = {0,};
	int size = 10;
	if(seq_search(arr, 5, 10)){
		printf("Ture");
	}
	else{
		printf("False");
	}

	return 0;
}
