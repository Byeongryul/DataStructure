#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define DEBUG
#include "logger.h"

vector<int> arr;

void setArr(int size){
    srand((unsigned int)time(NULL));

    for(int i = 0; i < size; ++i){
        int n = rand()%size;
        arr.push_back(n);
    }
}

void print(){
    if(arr.size() <= 100){
        for(int i = 0; i < (int)arr.size(); ++i)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

double setTime(struct timeval startTime, struct timeval endTime){
    struct timeval tempTime;
    tempTime.tv_sec = endTime.tv_sec - startTime.tv_sec;
    tempTime.tv_usec = endTime.tv_usec - startTime.tv_usec;
    if(tempTime.tv_usec < 0){
        tempTime.tv_sec = tempTime.tv_sec - 1;
        tempTime.tv_usec = tempTime.tv_usec + 1000000;
    }
    return tempTime.tv_sec + tempTime.tv_usec / 1000000.0;
}

int seq_sea(int key){
    for(int i = 0; i < (int)arr.size(); ++i)
        if(arr[i] == key) return i;
    return -1;

    int i;
    arr.push_back(key);
    for(i = 0; arr[i] == key; ++i);
    arr.pop_back();
    if(i == (int)arr.size() + 1) return -1;
    else return i;
}

int bin_sea(int key){
    int min = 0, max = arr.size() - 1;
    int mid;
    while(min <= max){
        mid = (max+ min) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key){
            min = mid + 1;
        }
        else{
            max = mid - 1;
        }
    }
    return -1;
}

int index_sea(int key){
    int size = (int)sqrt((double)arr.size());
    int s = size * (size - 1), e = size * size;
    int data[size], index[size];

    for(int i = 0; i < size; ++i){
        data[i] = arr[i * size];
        index[i] = i * size;
    }

    if(key < data[0]) return -1;
    else{
        for(int i = 1; i < size; ++i){
            if(key < data[i]){
                s = index[i - 1];
                e = index[i];
                break;
            }
        }
    }
    for(int i = s; i <= e; ++i){
        if(key == arr[i]){
            return i;
        }
    }
    return -1;
}

int inter_sea(int key){
    int min, max, j;
    min = 0;
    max = (int)arr.size() - 1;
    while(arr[min] < key && key <= arr[max]){
        j = (key - arr[min]) / (arr[max] - arr[min]) * (max - min) + min;
        if(key > arr[j]) min = j + 1;
        else if (key < arr[j]) max = j - 1;
        else min = j;
    }
    if(arr[min] == key) return min;
    else return -1;
}

double checkTime(int key, int(*sea)(int)){
    struct timeval sT, eT;
    gettimeofday(&sT, NULL);
    int place = sea(key);
    gettimeofday(&eT, NULL);
    if(place == -1) printf("없음");
    else printf("%d", place);
    printf("\n");
    return setTime(sT, eT);
}

int main(int argc, char* argv[]){
    int size = 100, key = 50;
    double seqT, binT, indexT, interT;
    seqT = binT = indexT = interT = 0;

    printf("size input: ");
    scanf("%d", &size);
    key = size / 2;

    setArr(size);
    sort(arr.begin(), arr.end());
    print();

    printf("key input: ");
    scanf("%d", &key);

    seqT = checkTime(key, seq_sea);
    binT = checkTime(key, bin_sea);
    indexT = checkTime(key, index_sea);
    interT = checkTime(key, inter_sea);

    printf("seq:%f bin:%f index:%f inter:%f\n", seqT, binT, indexT, interT);

    return 0;
}
