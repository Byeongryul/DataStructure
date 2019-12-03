#ifndef LOGGER_H
#define LOGGER_H

#ifdef DEBUG

#define LOG(...) \
	do{ \
		printf("[%s:%s:%d]\t",__FILE__, __func__, __LINE__); \
		printf(__VA_ARGS__); \
		printf("\n"); \
	}while(0)

#define SLOG() \
	do{ \
		printf("[%s:%s:%d]\t",__FILE__, __func__, __LINE__); \
		printf("\n"); \
	}while(0)

#else

#define LOG(...)
#define SLOG()

#endif

#endif
