#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <vector>
#include <algorithm>
using namespace std;

vector<int> odd;
vector<int> even;

int inputSize(){
    int size;

    srand((unsigned int)time(NULL));
    printf("Input data size: ");
    scanf("%d", &size);

    for(int i = 0; i < size / 2; ++i){
        odd.push_back(rand() / 2 + 1);
        even.push_back(rand() / 2 + 2);
    }


    printf("\n%d odd numbers are generated\n", size / 2);
    return size;
}

void seq_sea(int key){
    for(int i = 0; i < (int)odd.size(); ++i){
        if(odd[i] == key) return;
    }
    return;
}

void bin_sea(int key){
    int min = 0, max = odd.size() - 1;
    int mid;
    while(min <= max){
        mid = (max + min) / 2;
        if(odd[mid] == key) return;
        else if(odd[mid] < key){
            min = mid + 1;
        }
        else max = mid - 1;
    }
    return;
}

double setTime(struct timeval sT, struct timeval eT){
    struct timeval temp;
    temp.tv_sec= eT.tv_sec - sT.tv_sec;
    temp.tv_usec= eT.tv_usec - sT.tv_usec;
    if(temp.tv_usec < 0){

        temp.tv_sec= temp.tv_sec - 1;
        temp.tv_usec = temp.tv_usec + 1000000;
    }
    return temp.tv_sec + temp.tv_usec / 1000000.0;
}

double checkTime(int choice, void(*sea)(int)){
    struct timeval sT, eT;
    gettimeofday(&sT, NULL);

    if(choice % 2){
        for(int i = 0; i < (int)odd.size(); ++i){
            sea(odd[i]);
        }
    }
    else{
        for(int i = 0; i < (int)even.size(); ++i){
            sea(even[i]);
        }
    }

    gettimeofday(&eT, NULL);
    return setTime(sT, eT);
}

void result(int size){
    double seqT, binT;
    printf("\nEven numbers search time (fail)\n");

    seqT = checkTime(2, seq_sea);
    printf("Seq Search time: %fs\n", seqT);
    binT = checkTime(2, bin_sea);
    printf("Bin Search time: %fs\n", binT);
    printf("Bin Search %dx faster.\n", (int)(seqT / binT));

    printf("\nOdd numbers search time (success)\n");

    seqT = checkTime(1, seq_sea);
    printf("Seq Search time: %fs\n", seqT);
    binT = checkTime(1, bin_sea);
    printf("Bin Search time: %fs\n", binT);
    printf("Bin Search %dx faster.\n", (int)(seqT / binT));
}

int main(int argc, char* argvp[]){
    int size;
    size = inputSize();
    result(size);
    return 0;
}
