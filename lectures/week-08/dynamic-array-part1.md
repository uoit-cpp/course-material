# CSCI 1061U - Programming Workshop

## Dynamic array class

### Topics

- `[]` operators: _overloading `[]` operators_

### Task

Create an `Arr` class that implements a dynamically allocated array for storing double values.  

#### Using Arr class

For example, we will be able to use this array as follows:

~~~cpp
Arr a(3);  // Allocate an Arr instance that stores three double values

a[0] = 1;    // Setting values
a[1] = 2.3;
a[2] = 3.43;

// No deallocation is needed!
~~~

#### Using built-in C++ arrays

Notice how the above will be accomplished using built-in C++ arrays.

~~~cpp
double *a = new double[3]; // Allocating an array for storing three double values

a[0] = 1;    // Setting values
a[1] = 2.3;
a[2] = 3.43;

delete [] a; // Don't forget to deallocated this array
~~~

### Code

The following code implements the `Arr` class

~~~cpp
#include <iostream>
#include <cassert>

using namespace std;

class Arr
{
protected:
  double * _data;  // always a good practice to have members (data)
                   // hidden (either protected or private)
  int _n; // size of the array, so we know how big it is
                   
public:
  Arr(int n) : _n(n) // save the passed n, which indicates the size of the array
  {
    _data = new double[_n]; // allocate an array of size n (or _n)
  }
  
  Arr(const Arr& a)
  {
    _n = a._n; // save the size of "this" equal to that of instance "a"
    _data = new double[_n]; // allocate "this" (_n) slots
    for (int i=0; i<_n; ++i) // copy values
    {
      _data[i] = a._data[i];
    }
  }

  ~Arr()
  {
    delete [] _data;
  }

  double& operator[](int i)
  {
    return _data[i];
  }

  const double& operator[](int i) const
  {
    return _data[i];
  }

};

int main()
{
  Arr a(5); // a is an instance of type Arr
            // Arr must have a constructor that takes an int
            //
  			// this instance "a" has 5 slots for storing
  			// double values.
  
  a[1] = 2.3;
  cout << a[1] << endl;
  
  Arr b(a); // b is an instance of Arr
            // Arr must have a constructor that takes an instance of type
            // Arr (why, because a is an instance of Arr)
            //
            // Eureka!  this object Arr must have a copy constructor
            //
            // instance b is an exact copy of a

  return 0;
}
~~~

