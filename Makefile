CC = gcc
#CFLAGS = -g

#On Windows.
TARGET = sort_test.exe
RM = del

#On Linux.
#TARGET = sort_test
#RM = rm

all: sort_test.o sort.o
	$(CC) $(CFLAGS) -o $(TARGET) $^
	
clean :
	$(RM) *.o $(TARGET)
	
.PHONY: clean