% Function Pointers, Functors and Lambda Functions Exercise
% CSCI 1061U - Programming workshop 2
% Faisal Qureshi

# In class exercise

**Due by 1:45 pm, Today**

Consider the following code that uses routines `find_smallest()` and `smaller()` to find the smallest values stored in an array of integers

~~~cpp
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

bool smaller(int i, int j)
{
  return i < j;
}

int find_smallest(int a[], int n)
{
  int smallest = a[0];
  for (int i=1; i<n; ++i) {
    if (smaller(a[i], smallest)) smallest = a[i];
  }
  return smallest;
}

int main()
{
  srand(0);
  int a[6];
  for (int i=0; i<6; ++i) a[i] = rand();

  for (int i=0; i<6; ++i) cout << a[i] << endl;
  
  int smallest = find_smallest(a, 6);
  cout << "smallest = " << smallest << endl;
  
  return 0;
}
~~~

Line 

~~~cpp
int smallest = find_smallest(a, 6);
~~~

in the `main()` function gets the smallest value stored in array `a` whose length is `6`.  

Your goal is to modify find_template() function such that we can use it to find the smallest item (by an criteria) in an array of items.

Consider, for example, the Pt class below

~~~cpp
class Vec
{
  protected:
  double _x, _y, _z;

  public:
  Vec() {
    _x = (double) rand() / RAND_MAX;
    _y = (double) rand() / RAND_MAX;
    _z = (double) rand() / RAND_MAX;
  }

  double x() const { return _x; }
  double y() const { return _y; }
  double z() const { return _z; }
  
  friend ostream& operator<<(ostream& os, const Vec& v)
  {
    cout << "(" << v._x << "," << v._y << "," << v._z << ")";
    return os;
  }

  inline double l2() {
    return _x*_x + _y*_y + _z*_z;
  }
};
~~~

This class implements a 3D point.  We can easily set up an array of 3D pts as follows

~~~cpp
Pt a[6];
~~~

Elements of this array (i.e., the 3D points) will be initialized with random values.  See, for example code below and its output:

~~~cpp
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::ostream;

class Vec
{
  protected:
  double _x, _y, _z;

  public:
  Vec() {
    _x = (double) rand() / RAND_MAX;
    _y = (double) rand() / RAND_MAX;
    _z = (double) rand() / RAND_MAX;
  }

  double x() const { return _x; }
  double y() const { return _y; }
  double z() const { return _z; }
  
  friend ostream& operator<<(ostream& os, const Vec& v)
  {
    cout << "(" << v._x << "," << v._y << "," << v._z << ")";
    return os;
  }

  inline double l2() {
    return _x*_x + _y*_y + _z*_z;
  }
};

int main()
{
  srand(0);
  Vec a[6];
  
  for (int i=0; i<4; ++i) cout << a[i] << endl;
  
  return 0;
}
~~~

The output is:

~~~bash
$ g++ lambda-exercise.cpp ; ./a.out
(0.242578,0.0134696,0.383139)
(0.414653,0.067769,0.993127)
(0.484308,0.765338,0.0318338)
(0.0309355,0.93264,0.88788)
(0.59133,0.478779,0.833354)
(0.186335,0.735653,0.115053)
~~~

I wish to use the _modified_ find_smallest function to find the smallest Pt based on the following criteria:

- smallest x value;
- smallest y value;
- smallest z value; and
- smallest squared length.

**The caveat is that I don't want to keep re-writing the `find_smallest()` as my criteria changes.**  

**Furthermore, I may want to use your `find_smallest()` method to operate on other objects, say a class that stores students' first and last names.** 