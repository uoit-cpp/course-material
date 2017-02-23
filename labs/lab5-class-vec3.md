# CSCI 1061U - Programming Workshop 2

## Lab 5 - C++ Classes 

**Due back on Saturday, March 4 before 11:59 pm.**

### Objectives ###

Create a `vec3` class that implements a 3-dimensional vector.  It also implements basic vector functionality: addition, subtraction, scaling, negation, dot product, cross product, etc.

#### Task

Provide the `vec3.cpp` file that contains the body for the `vec3` class declared in the header file `vec3.h` provided below.

##### Header file declaring `vec3` class.

~~~cpp
// vec3.h
#ifndef __vec3_h__
#define __vec3_h__

#include <iostream>
using namespace std;

class vec3
{
private:
  float m[3];

public:

  // constructors
  vec3();
  vec3(const vec3& v);
  vec3(float x, float y, float z);

  // indexing
  float& operator[](int i);
  const float& operator[](int i) const;

  // assignment
  const vec3& operator=(const vec3& v);

  // multiplication with a scalar
  void operator*=(float s);  
  friend vec3 operator*(const vec3& v, float s);

  // addition
  void operator+=(const vec3& v);
  friend vec3 operator+(const vec3& v1, const vec3& v2);

  // subtraction
  void operator-=(const vec3& v);
  friend vec3 operator-(const vec3& v1, const vec3& v2);

  // negation
  vec3 operator-();
  
  // dot product
  friend float operator*(const vec3& v1, const vec3& v2);

  // cross product
  friend vec3 operator^(const vec3& v1, const vec3& v2);

  // length
  float length();
  
  // io
  friend ostream& operator<<(ostream& o, const vec3& v);
  friend istream& operator>>(istream& o, vec3& v);
};

#endif
~~~

##### Using vec3 class

Consider the following `main.cpp` file that is using the `vec3` class declared above

~~~cpp
#include <iostream>
#include "vec3.h"
using namespace std;

int main()
{
  vec3 a;
  cout << "a:" << a << endl;

  a += vec3(2,3,5);
  cout << "a+=vec3(2,3,5): " << a << endl;

  a[0] = 22;
  cout << "a[0]=22: " << a << endl;

  vec3 b(1,2,3);
  cout << "b: " << b << endl;

  cout << "b-a: " << b - a << endl;
  
  cout << "b*a: " << b*a << endl;

  cout << "b^a: " << (b^a) << endl;

  cout << "-b: " << -b << endl;

  return 0;
}
~~~ 

###### Compilation

We compile the code as follows:

~~~bash
$ g++ main.cpp vec3.cpp -o v
~~~

*Note that you are to provide the vec3.cpp file.*

###### Execution

The output is

~~~bash
$ ./v
a:0 0 0
a+=vec3(2,3,5): 2 3 5
a[0]=22: 22 3 5
b: 1 2 3
b-a: -21 -1 -2
b*a: 43
b^a: 1 61 -41
-b: -1 -2 -3
~~~

###Submission

Please submit your `vec3.cpp` file via Blackboard.