CC = gcc
#CFLAGS = -g
TARGET = sort_test

ifeq ($(OS),Windows_NT)
RM = del
else
RM = rm
endif

all: sort_test

sort_test: sort_test.o sort.o

clean :
	$(RM) *.o

.PHONY: clean
