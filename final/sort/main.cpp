#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <vector>
using namespace std;

vector<int> temp;
vector<int> quick;
vector<int> mg;

struct timeval startTime, endTime, tempTime;

void setList(int size){
    int data;
    srand((unsigned int)time(NULL));

    for(int i = 0; i < size; ++i){
        data = rand() % size;
        temp.push_back(data);
        quick.push_back(data);
        mg.push_back(data);
    }
}

int getLoc(int left, int right){
    int low, high, value, tmp;
    low = left;
    high = right + 1;
    value = quick[left];
    do{
        do
            low++;
        while(low<=right && quick[low] < value);
        do
            high--;
        while(high>=left && quick[high] > value);
        if(low < high){
            tmp = quick[low];
            quick[low] = quick[high];
            quick[high] = tmp;
        }
    } while(low < high);

    tmp = quick[left];
    quick[left] = quick[high];
    quick[high] = tmp;

    return high;
}

void quSort(int left, int right){
    if(left < right){
        int p = getLoc(left, right);
        quSort(left, p - 1);
        quSort(p + 1, right);
    }
}

void realMgSort(int left, int mid, int right){
    int pl = left, pr = mid + 1;
    vector<int> tmp;
    while(pl != mid + 1 && pr != right + 1){
        if(mg[pl] < mg[pr]){
            tmp.push_back(mg[pl++]);
        }
        else{
            tmp.push_back(mg[pr++]);
        }
    }
    if(pl == mid + 1){
        while(pr != right + 1)
            tmp.push_back(mg[pr++]);
    }
    else{
        while(pl != mid + 1)
            tmp.push_back(mg[pl++]);
    }
    for(int i = left; i <= right; ++i){
        mg[i] = tmp[i - left];
    }
}

void mgSort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mgSort(left, mid);
        mgSort(mid + 1, right);
        realMgSort(left, mid, right);
    } 
}

double getTime(){
    tempTime.tv_sec = endTime.tv_sec - startTime.tv_sec;
    tempTime.tv_usec = endTime.tv_usec - startTime.tv_usec;
    if(tempTime.tv_usec < 0){
        tempTime.tv_sec = tempTime.tv_sec - 1;
        tempTime.tv_usec = tempTime.tv_usec + 1000000;
    }
    return tempTime.tv_sec + tempTime.tv_usec / 1000000.0;
}

int main(int argc, char* argv[]){
    int size = 10;
    //scanf("%d", &size);
    setList(size);

    for(int i = 0; i < size; ++i){
        printf("%d ", temp[i]);
    }
    printf("\n");

    gettimeofday(&startTime, NULL);
    quSort(0, quick.size() - 1);
    gettimeofday(&endTime, NULL);

    printf("Quick Time: %f\n", getTime());
    for(int i = 0; i < (int)quick.size(); ++i){
        printf("%d ", quick[i]);
    }
    printf("\n");

    gettimeofday(&startTime, NULL);
    mgSort(0, mg.size() - 1);
    gettimeofday(&endTime, NULL);

    printf("Merge Time: %f\n", getTime());
    for(int i = 0; i < (int)mg.size(); ++i){
        printf("%d ", mg[i]);
    }
    printf("\n");

    return 0;
}
