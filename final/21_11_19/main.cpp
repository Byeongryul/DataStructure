#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> b;
vector<int> m;
vector<int> q;
vector<int> s;

struct timeval startTime, endTime, tempTime;
double BT, MT, QT, ST;

void setArr(int size){
    srand((unsigned int)time(NULL));
    printf("d");
    for(int i = 0; i < size; ++i){
        b[i] = m[i] = q[i] = s[i] = rand()%size;
    }
}

void BSort(){
    int temp;
    for(int i = b.size() - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            temp = b[j + 1];
            b[j+1] = b[j];
            b[j] =temp;
        }
    }
}

void RMSort(int left, int mid, int right){
    int pl = left, pr = mid + 1;
    vector<int> tmp;
    while(pl != mid + 1 && pr != right + 1){
        if(m[pl] < m[pr]){
            tmp.push_back(m[pl++]);
        }
        else{
            tmp.push_back(m[pr++]);
        }
    }
    if(pl == mid + 1){
        while(pr != right + 1)  tmp.push_back(m[pr++]);
    }
    else{
        while(pl != mid + 1)  tmp.push_back(m[pl++]);
    }
    for(int i = left; i <= right; ++i) m[i] = tmp[i - left];
}

void MSort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        MSort(left, mid);
        MSort(mid + 1, right);
        RMSort(left, mid, right);
    }
}

int getLoc(int left, int right){
    int low, high, value, tmp;
    low = left;
    high = right + 1;
    value = q[left];
    do{
        do low++; while(low<=right && q[low] < value);
        do high--; while(high>=left && q[high] > value);
        if(low < high){
            tmp = q[low];
            q[low] = q[high];
            q[high] = tmp;
        }

    }while(low < high);
        tmp = q[left];
        q[left] = q[high];
        q[high] = tmp;
        return high;
}

void QSort(int left, int right){
    if(left < right){
        int p = getLoc(left, right);
        QSort(left, p - 1);
        QSort(p + 1, right);
    }
}

void SSort(){
    sort(s.begin(), s.end());
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

int main(int argc, char* argv[]){
    int size;
    scanf("%d", &size);

    setArr(size);

    if(size <= 100){
        printf("생성한 배열\n");
        for(int i = 0; i < size && i != 100; ++i){
            printf("%d ", b[i]);
        }
        printf("\n");
    }

    gettimeofday(&startTime, NULL);
    BSort();
    gettimeofday(&endTime, NULL);
    BT = setTime();

    gettimeofday(&startTime, NULL);
    MSort(0, size - 1);
    gettimeofday(&endTime, NULL);
    MT = setTime();

    gettimeofday(&startTime, NULL);
    QSort(0, size - 1);
    gettimeofday(&endTime, NULL);
    QT = setTime();

    gettimeofday(&startTime, NULL);
    SSort();
    gettimeofday(&endTime, NULL);
    ST = setTime();

    if(BT > QT){
        printf("Bublle Sort: Quick Sort 보다 %.1f배 빠름", BT / QT);
    }
    else{
        printf("Bublle Sort: Quick Sort 보다 %.1f배 느름", QT / BT);
    }

    if(MT > QT){
        printf("Bublle Sort: Merge Sort 보다 %.1f배 빠름", MT / QT);
    }
    else{
        printf("Bublle Sort: Merge Sort 보다 %.1f배 느름", QT / MT);
    }

    if(ST > QT){
        printf("Bublle Sort: Quick Sort 보다 %.1f배 빠름", ST / QT);
    }
    else{
        printf("Bublle Sort: Quick Sort 보다 %.1f배 느름", QT / ST);
    }
    return 0;
}
