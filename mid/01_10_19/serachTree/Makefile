CC = g++
TARGET = test.out
OBJS = main.o Tree.o quiz.o
CFLAGS = -Wall
LDFLAGS = -lc
all : $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
clean :
	rm -f $(OBJS) $(TARGET)
