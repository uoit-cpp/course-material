CC = g++
CFLAGS = -c -Wall

all: helloworld

helloworld: main.o greetings.o
	$(CC) -o helloworld main.o greetings.o

%.o: %.cpp greetings.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm helloworld main.o greetings.o