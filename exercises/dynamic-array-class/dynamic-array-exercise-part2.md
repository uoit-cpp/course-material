# CSCI 1061 - Programming Workshop 2

## Class Exercise

__Must be completed during the class__  See submission instructions below.

### Dynamic Array Class Part 2

You are asked to create an `Arr` class that is able to grow array as/when needed.

_Recall from part 1 of this exercise that class `Arr` dynamically allocates an array for storing double values._

#### Usage

~~~cpp
Arr a; // Array of size 0
a[20] = 10;  // Automatically grows the array to have 21 items.
a[23] = 22;  // Automatically grows the array to have 24 items.
~~~

#### Template file

Use the following template to complete the file.  It already contains the `Arr` class from part 1.  Don't bother with header and cpp files keep things relatively straightforward.

~~~cpp
#include <iostream>
#include <cassert>

using namespace std;

class Arr
{
  protected:
  double* _data;
  int _n;

  public:
  Arr() : _n(0)
  {
    _data = 0;
  }

  Arr(int n) : _n(n)
  {
    _data = new double[_n];
  }

  ~Arr()
  {
    if (_data) delete [] _data;
  }

  Arr(const Arr& o)
  {
    _n = o._n;
    _data = new double[_n];
    for (int i=0; i<_n; ++i) _data[i] = o[i];
  }

  double& operator[](int i)
  {
    if (i < 0 || i >= _n) assert(true);
    return _data[i];
  }

  const double& operator[](int i) const
  {
    if (i < 0 || i >= _n) assert(true);
    return _data[i];
  }

  const int& size() const { return _n; }

  friend ostream& operator<<(ostream& so, const Arr& a)
  {
    for (int i=0; i<a._n; ++i) so << a[i] << ' ';
    return so;
  }

  friend istream& operator>>(istream& si, Arr& a)
  {
    cout << "Expecting " << a._n << " entries." << endl;
    for (int i=0; i<a._n; ++i) si >> a[i];
    return si;
  }
  
  protected:
  const Arr& operator=(const Arr& o) { return *this; } 
};

///////////////////////////
//
// main method
//
///////////////////////////

int main()
{
  Arr a(5);
  cin >> a;
  cout << "a = " << a << endl;

  Arr b(a);
  cout << "b = " << b << endl;

  // a = b; not allowed
  
  return 0;
}
~~~ 

### Submission

Please submit your file (main.cpp) via Blackboard __before the end of this lecture__.