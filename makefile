CC=g++
CFLAGS=-I.

all: program

program: program.o swap.o
	$(CC) -o program program.o swap.o

program.o: program.cpp
	$(CC) -c program.cpp $(CFLAGS)

swap.o: swap.cpp
	$(CC) -c swap.cpp $(CFLAGS)

clean:
	rm -f *.o program
