# CSCI 1061u - Programming Workshop 2 

## Winter 2017

### In-class exercise

**Please submit on Blackboard.**

**Due before the end of the class.**

Consider the following `queue.h` and `main.cpp`.  It implements a simple array based queue that can be used to store `int` values.  Our `queue` implementation has an error.  Can you fix it?

`queue.h` file is provided below: 

~~~cpp
#ifndef __queue_h__
#define __queue_h__

#include <iostream>
using namespace std;

namespace PW2 {

class queue
{
  private:
  int* a_;
  int n_;
  int f_;
  int b_;
  
  void resize(int n) {
    if (n == n_) return;
    
    int* tmp = new int[n];
    int ncopy = n < n_ ? n : n_;
    for (int i=0; i<ncopy; ++i) tmp[i] = a_[i];
    delete[] a_;
    a_ = tmp;
    n_ = n;
  }
  
  public:
  queue() : a_(0), n_(0), f_(0), b_(0) {}

  void push(int v) {
    if (b_ + 1 > n_) {
      resize(n_+1);
    }
  
    a_[b_] = v;
    b_++;
  }

  int pop() {
    int v = a_[f_];
    f_--;
    return v;
  }

  void debug()
  {
    cout << "\nDEBUG queue" << endl;
    cout << "f_ = " << f_ << endl;
    cout << "b_ = " << b_ << endl;
  
    if (f_ == b_) {
      cout << "Empty queue" << endl;
    }
    else {
      for (int i=f_; i<b_; ++i) cout << a_[i] << " ";
      cout << endl;
    }
    cout << "DEBUG queue\n" << endl;
  }
};

}

#endif
~~~

`main.cpp` file is provided below: 

~~~cpp
#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
  queue q;
  q.debug();

  cout << "push 1" << endl;
  q.push(1);
  cout << "push 2" << endl;
  q.push(2);
  q.debug();

  cout << "pop " << q.pop() << endl;
  cout << "pop " << q.pop() << endl;
  q.debug();

  cout << "push 3" << endl;
  q.push(3);
  cout << "push 4" << endl;
  q.push(4);
  q.debug();

  cout << "pop " << q.pop() << endl;
  cout << "pop " << q.pop() << endl;
  q.debug();

  
  return 0;
}
~~~

You can use the following `Makefile` to build the program.

~~~makefile
CC = g++
CFLAGS =
LDFLAGS =

HEADERS = queue.h
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = queue

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CC) -c $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
~~~

## What to submit?

Submit the fixed `queue.h` file via Blackboard.
