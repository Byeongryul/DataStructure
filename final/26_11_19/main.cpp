#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <vector>
#include <algorithm>
using namespace std;

vector<int> array;

struct timeval startTime, endTime, tempTime;
double BT, MT, QT, ST;

void setArr(int size, int key){
	srand((unsigned int)time(NULL));
	for(int i = 0; i < size - 1; ++i){
		int n = rand()%size;
		array.push_back(n);
	}
	array.push_back(key);
}

double setTime(){
	tempTime.tv_sec = endTime.tv_sec - startTime.tv_sec;
	tempTime.tv_usec = endTime.tv_usec - startTime.tv_usec;
	if(tempTime.tv_usec < 0){
		tempTime.tv_sec = tempTime.tv_sec - 1;
		tempTime.tv_usec = tempTime.tv_usec + 1000000;
	}
	return tempTime.tv_sec + tempTime.tv_usec / 1000000.0;
}

int seq_search(int val, int size){
	for(int i = 0; i < size; ++i){
		if(array[i] == val) return i;
	}
	return -1;
}

int binary_search(int val){
	int min = 0, max = array.size() - 1;
	int mid = max / 2;
	while(min <= mid && mid <= max){
		if(array[mid] == val){
			return mid;
		}
		else if(array[mid] < val){
			if(mid == min) break;
			min = mid;
			mid = (max + min) / 2;
		}
		else{
			if(mid == max) break;
			max = mid;
			mid = (max + min) / 2;
		}
	}
	return -1;
}

int main(int argc, char* argv[]){
	int size = 10;
	//scanf("%d", &size);
	setArr(size, 10);
	sort(array.begin(), array.end());

	for(int i = 0; i < array.size() && i < 100;++i){
		printf("%d ", array[i]);
	}
	printf("\n");
	
	printf("%d\n", seq_search(5));
	printf("%d\n", binary_search(1));

	return 0;
}
