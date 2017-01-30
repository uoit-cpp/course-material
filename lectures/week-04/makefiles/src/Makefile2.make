# This is a comment
CC = g++
CFLAGS = -c -Wall

all: helloworld

helloworld: main.o greetings.o
	$(CC) -o helloworld main.o greetings.o

main.o: main.cpp greetings.h
	$(CC) $(CFLAGS) -o main.o main.cpp

greetings.o: greetings.cpp
	$(CC) $(CFLAGS) -o greetings.o greetings.cpp 

clean:
	rm helloworld main.o greetings.o