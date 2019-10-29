#include<stdio.h>
#include<stdlib.h>

struct Dict{
    char key;
    int value;
};

#define PERIOD 26
#define SPACE 27

void print_dict(Dict *data, int size){
    for(int i = 0; i < size; ++i){
        if(data[i].value != 0){
            if(data[i].key == '.')
                printf("PERIOD(%d) / ", data[i].value);
            else if(data[i].key == ' ')
                printf("SPACE(%d) / ", data[i].value);
            else
                printf("%c(%d) / ", data[i].key, data[i].value);
        }
    }
    printf("\b\b \n");
}

int main(int argc, char *argv[]){
    char c_input;
    Dict inputData[28] = {0,};
    Dict sortData[29] = {0,};

    for(int i = 0; i < 26; ++i){
        inputData[i].key = 'a' + i;
    }
    inputData[PERIOD].key = '.';
    inputData[SPACE].key = ' ';

    printf("Input String: ");
    while('\n' != (c_input = getc(stdin))){
        if('a' <= c_input && c_input <= 'z') inputData[c_input - 'a'].value++;
        else if(c_input == '.') inputData[PERIOD].value++;
        else if(c_input == ' ') inputData[SPACE].value++;
    }

    print_dict(inputData, 28);

    int sortSize = 1;
    for(int i = 0; i < 29; ++i){
        if(inputData[i].value != 0){
            sortData[sortSize++] = inputData[i];
            int index = sortSize - 1;
            while(index != 1 && sortData[index].value < sortData[index / 2].value){
                Dict temp = sortData[index];
                sortData[index] = sortData[index / 2];
                sortData[index / 2] = temp;
                index /= 2;
            }
        }
    }
    print_dict(sortData, sortSize);

    for(int i = 0; i < 28; ++i) inputData[i].key = inputData[i].value = 0;

    for(int i = 0; i < 28 && sortSize != 1; ++i){
        inputData[i] = sortData[1];
        sortData[1] = sortData[--sortSize];
        int index = 1;
        while(index > sortSize && (sortData[index].value > sortData[index * 2].value|| sortData[index].value > sortData[index * 2 + 1].value)){
            Dict temp = sortData[index];
            sortData[index] = sortData[index * 2];
            sortData[index * 2] = temp;
            index *= 2;
        }
    }
    print_dict(inputData, 28);
    return 0;
}
