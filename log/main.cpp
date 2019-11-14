#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#ifdef DEBUG
#define LOG(...) printf("[%s:%s:%d]\t",__FILE__, __func__, __LINE__); printf(__VA_ARGS__), printf("\n");
#define SLOG() printf("[%s:%s:%d]\t",__FILE__, __func__, __LINE__); printf("\n");
#else
#define LOG(...)
#endif

void func(){
	LOG(" ");
	LOG(" ");
	LOG(" ");
}

int main(int argc, char *argv[]){
	func();
	LOG(" ");
	LOG(" ");
	LOG(" ");
	LOG(" ");
	LOG(" ");
	LOG(" ");
	return 0;
}
