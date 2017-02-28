# CSCI 1061U - Programming Workshop

## Vec2 class continued from last week

### Topics

- `const` functions: _indicate that this member function doesn't change the current instance_.	 
- `const` references: _these references cannot be used to modify an instance.  these can only be passed to functions that expect a const reference_. 
- `friends` functions: _non-member functions and operators of class that can access protected members and methods of that class_.
- extractor (`>>`) operator: _used to send contents to an ostream, such as cout, a file, etc._
- insertor (`<<`) operator: _used to read contents from an istream, such as cin, a file, etc._

### Code Example

Consider the following `vec2.h` file that showcases the use of `const` and `friend` functions.

It also provides a recipe for writing insertion `<<` and extraction `>>` operators.

#### vec2.h

~~~cpp
#include <iostream>

class vec2 {
protected:
  double x;
  double y;
  
public:
  vec2();
  vec2(double c);
  vec2(double x, double y);
  vec2(const vec2& o); // Copy constructor
  ~vec2(); // Destructor
  
public:
  double length2() const; // A member const function
                          // to compute the squared length
                          // of this function.  By declaring
                          // this function const, we
                          // promise that this function
                          // will not modify "this" instance, i.e.,
                          // members x and y will remain unchanged.
                          // this allows the following to work
                          //
                          //   vec2 v(1,2);
                          //   const vec2& const_v_ref = v;
                          //   cout << "Squred length = " << const_v_ref.length2() << endl;
                          //
                          // Note that if this function was not
                          // declared const, the following statement
                          // will give a compile-time error:
                          //
                          //   const_v_ref.length2()
  
  friend double length2(const vec2& v); // A friend function, which is not
                                        // not a member of vec2, to compute
                                        // the squred length of this vector.
                                        // Since this function is not a member,
                                        // we need to pass a vec2 as argument.
                                        // Here we pass a const references to
                                        // a vec2.  This is the recommended
                                        // approach to pass objects due to the following
                                        // advantages:
                                        //    1. We are only passing a reference to
                                        //       the object, avoiding a copy.
                                        //    2. Since we don't expect a vec2 to
                                        //       change because its squared length
                                        //       is computed, we pass a const reference.
                                        // Note that we also decrare this function
                                        // a friend.  That allows that vec2 instance
                                        // within this function can access the protected
                                        // members of vec2.
                                        
  const vec2& operator=(const vec2& o) { // Assignment operator
    x = o.x;
    y = o.y;
    return *this;
  }

  // vec2 a, b;
  // cout << a << ' ' << b << endl;
  friend std::ostream& operator<<(std::ostream& stream, const vec2& o) { // Insertor operator
                                                                         // Use to insert data to
                                                                         // ostream objects
    stream << o.x << ' ' << o.y;
    return stream;
  }

  // vec2 a
  // cin >> a;
  friend std::istream& operator>>(std::istream& stream, vec2& o) { // extractor operator
                                                                   // Use to extract data from
                                                                   // istream objects
    stream >> o.x;
    stream >> o.y;
    return stream;
  }
}
~~~

#### vec2.cpp

The corresponding cpp file `vec2.cpp` is

~~~cpp
#include "vec2.h"
#include "math.h"

using namespace std;

vec2::vec2() : x(0.0), y(0.0)
{
}

vec2::vec2(double c)
{
  x = c;
  y = c;
}

vec2::vec2(double x, double y)
{
  this->x = x; // Using this pointer to differentiate
  this->y = y; // between members x and y and
               // function arguments x and y.
}

vec2::vec2(const vec2& o)
{
  x = o.x;
  y = o.y;
}

vec2::~vec2()
{}

double vec2::length2() const
{
  return x*x + y*y;
}

double length2(const vec2& v)
{
  return v.x*v.x + v.y*v.y;
}
~~~

#### main.cpp

And the `main.cpp` file that you can use to experiment with these files is

~~~cpp
#include <iostream>
#include "vec2.h"

using namespace std;


int main()
{
  vec2 a(2,4);
  cout << "a = " << a << endl;
  cout << "length of a = " << a.length2() << endl;
  cout << "length of a = " << length2(a) << endl;

  const vec2& b = a;
  cout << "length of b = " << b.length2() << endl;

  vec2 c;
  c = b;
  cout << "length of c = " << c.length2() << endl;

  vec2 d;
  cout << "d = " << d << endl;
  cout << "Enter d: ";
  cin >> d;
  cout << "d = " << d << endl;
  
  return 0;
}
~~~

#### Compilation

You can compile this program as follows:

~~~bash
$ g++ vec2.cpp main.cpp -o v
~~~