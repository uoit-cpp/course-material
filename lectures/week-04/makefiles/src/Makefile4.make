CC = g++
CFLAGS = -c -Wall
DEPS = greetings.h
OBJ = main.o greetings.o

all: helloworld

helloworld: $(OBJ)
	$(CC) -o helloworld main.o greetings.o

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm helloworld main.o greetings.o