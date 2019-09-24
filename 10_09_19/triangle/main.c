#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc == 2){
        int n = atoi(argv[1]);
        for(int i = 0;i < n;++i){
            for(int j = 0;j < i + 1;++j){
                printf("*");
            }
            printf("\n");
        }        
    }
    else{
        printf("usage) %s # (height of triangle)\n", argv[0]);
    }
    return 0;
}
