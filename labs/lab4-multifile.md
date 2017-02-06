# CSCI 1061U - Programming Workshop 2

## Lab 3 - C++ Structs

**Due back on Saturday, February 11 before 11:59 pm.**

### Introduction

The goal of this lab is to get ourselves familiar with multi-file C++ programs.  We'll complete the following task:

1. Modify the `main()` method such that the array `arr` only contains letters from A to Z. 
2. Write `void count(char* arr, int n, int* counts)` that returns the count of each letter in the array. 
3. Save this function in `count.cpp` file.
4. Create a Makefile with following targets:
	- all
	- clear
	- arr
5. The Makefile should compile the `arr` executable from `count.cpp` and `main.cpp` file.  The skeleton for the `main.cpp` file is provided below. 

#### `main.cpp` file

The following file uses random number generator to fills an array `arr` with random values.  The random values lie between `0` and `RAND_MAX`.  

~~~cpp
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <count>" << endl;
    cerr << "\t<count> is an integer between 10 and 10000\n";
    cerr << "\tExiting.";
    return -1;
  }

  int n = atoi(argv[1]);
  if (n < 10 || n > 10000) {
    cerr << "Usage: " << argv[0] << " <count>" << endl;
    cerr << "\t<count> is an integer between 10 and 10000\n";
    cerr << "\tExiting.";
    return -2;
  }
  
  srand(time(NULL));

  //////////////////////////////////////////////
  //
  // TODO
  // Change the following line to char* arr = new char[n];
  //
  //////////////////////////////////////////////
  int* arr = new int[n];

  //////////////////////////////////////////////
  //
  // TODO
  // Change the following lines such arr
  // contains letter A - Z.   The letters will be 
  // a randomly generated.
  //
  //////////////////////////////////////////////
  for (int i=0; i<n; ++i) {
    arr[i] = rand();
  }

  for (int i=0; i<n; ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
  
  delete [] arr;

  return 0;
}
~~~	

To complete the tasks shown above you will need to modify this file such that the `arr` will contain letters A to Z, which are randomly generated. 

### Submission

Please submit `main.cpp`, `count.cpp` and `Makefile` via Blackboard.