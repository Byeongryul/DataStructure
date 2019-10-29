#include<stdio.h>

int main(int argc, char* argv[]){
    printf("Total # of args = %d\n", argc);
    
    for(int i = 0;i < argc;++i){
        printf("arg[%d] = %s\n", i, argv[i]);
    }
    return 100;
}
