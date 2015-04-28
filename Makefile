CC = gcc
#CFLAGS = -g
TARGET = sort_test

all: sort_test.o sort.o
	$(CC) $(CFLAGS) -o $(TARGET) $^
	
clean :
	@rm *.o $(TARGET)
	@del *.o $(TARGET)
	
.PHONY: clean
