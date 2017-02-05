# Dealing with Multiple Files
## CSCI 1061

**Faisal Qureshi**

## Files


Consider the following CPP program that comprises 4 files:

- main.cpp;
- out.cpp;
- math.cpp; and
- Arr.h.

### main.cpp

This file contains the `main()` function.  Each CPP program must have only one `main()` function that serves as the entry-point into the program.

This file uses `Arr` struct two functions `prn_arr()` and `ave_arr`, which are not defined in this file.

Struct `Arr` is defined in `Arr.h`.  We use `#include` to include `Arr.h` file into `main.cpp`.

Line `extern void prn_arr(struct Arr& a);` declares that function `prn_arr` is defined somewhere else.  

Line `extern double ave_arr(struct Arr& a);` declares that function `ave_arr` is defined somewhere else.  

~~~cpp
#include <iostream>
#include "Arr.h"
using namespace std;


extern void prn_arr(struct Arr& a); 
extern double ave_arr(struct Arr& a);

int main()
{
  int i = 0;
  Arr a;
  // double arr[10];
  // int sz;

  do {
    double tmp;
    cin >> tmp;

    if (tmp < 0) {
      a.sz = i;
      break;
    }

    a.arr[i] = tmp;
    i = i + 1;
  } while(true);

  prn_arr(a);
  cout << ave_arr(a) << endl;

  return 0;
~~~
  
### out.cpp
  
Function `prn_arr` is defined in this file. 
  
~~~cpp
#include <iostream>
#include "Arr.h"
using namespace std;


void prn_arr(struct Arr& a)
{
  for (int i=0; i<a.sz; i++) {
    cout << a.arr[i] << ' ';
  }
  cout << endl;
}
~~~  

### math.cpp

Function `ave_arr` is defined in this file.

~~~cpp
#include <iostream>
#include "Arr.h"
using namespace std;


double ave_arr(struct Arr& a)
{
  double sum=0.;

  for (int i=0; i<a.sz; i++) {
    sum = sum + a.arr[i];
  }

  return sum / (double) a.sz;
}
~~~

### Arr.h

Struct `Arr` is defined in this header file.

_Note that header files are not compiled._

~~~cpp
struct Arr
{
  double arr[10];
  int sz;
};
~~~

## Compilation

Use `g++` with `-c` flag to compile cpp files to object files as follows:

~~~bash
$ g++ -c main.cpp
$ g++ -c out.cpp
$ g++ -c math.cpp
~~~

Now link the object files to create the executable `ar`.

~~~bash
$ g++ main.o out.o math.o -o ar
~~~

Now you can execute the program as follows:

~~~bash
$ ./ar 
~~~

Note that we never compiled `Arr.h` file. 

## Self-Study

Try to compile the program as follows and see what happens

~~~bash
$ g++ main.o math.o -o arr
~~~

You should receive a linker error, complaining that function `prn_ave` is not found.

