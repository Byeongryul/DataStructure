#include <stdio.h>
#include <vector>
using namespace std;

void merge(int list[], int left, int mid, int right){
	int pl = left, pr = mid + 1;
	vector<int> temp;
	while(pl != mid + 1 && pr != right + 1)
		list[pl] < list[pr] ? temp.push_back(list[pl++]) : temp.push_back(list[pr++]);
	if(pl == mid + 1)
		while(pr != right + 1)
			temp.push_back(list[pr++]);
	else
		while(pl != mid + 1)
			temp.push_back(list[pl++]);
	for(int i = 0; i <= right; ++i){
		list[i] = temp[i];
	}
}

int main(int argc, char* argv[]){
	int list[] = {1,3,7,11,2,4,6,8};
	int left = 0, right = 7, mid = 3;
	merge(list, left, mid, right);

	for(int i = left; i <= right; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}
