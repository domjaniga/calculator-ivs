CC=gcc
CFLAGS=-I.

all: library_test

library_test: library_test.c library.o
	$(CC) -o library_test library_test.c library.o $(CFLAGS) -lm

library.o: ../src/library.c ../src/library.h
	$(CC) -c ../src/library.c $(CFLAGS)

clean:
	rm -f library_test library.o
