# This is a comment
CC = g++
CFLAGS = -c -Wall

all: arr

arr: main.o count.o
	$(CC) -o arr main.o count.o

main.o: main.cpp
	$(CC) $(CFLAGS) -o main.o main.cpp

count.o: count.cpp
	$(CC) $(CFLAGS) -o count.o count.cpp 

clean:
	rm arr main.o count.o
