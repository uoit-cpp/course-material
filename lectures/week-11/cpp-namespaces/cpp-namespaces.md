# CSCI 1061U - Programming Workshop 2 

__faisal.qureshi@uoit.ca__

## CPP Namespaces

### Separate compilation

- Program parts
	- Kept in separate files
	- Compiled separately
	- Linked together to create executable
- Class definitions
	- Build a library of classes
	- Re-used by many different programs

### Class separation

- Class independence
	- Separate class definition/specification
		- Usually placed in the header (.h) file
	- Separate class implementation	 (e.g., function declaration)
		- Usually placed in .cpp or .C file
	- Even if implementation changes, class definition doesn't have to change
		- "User" program doesn't need to change.  It continues to use the class as before.

### Encapsulation
 
- Basic Object-Oriented Programming Principle
- Separate how class is used by a programmer from the details of its implementation.
- Ideally changing implementation should have no bearing on how a class can be used.

Consider class Vec definition below

~~~cpp
class Vec {
  protected:
  float d[3];
  
  Vec(float x, float y, float z) {
  	d[0] = x; 
  	d[1] = y; 
  	d[2] = z; 
  }
   
  float length2() const;
};
~~~

Now consider two possible implementations of the length() method.

Implementation 1

~~~cpp
float Vec::length() const
{
  float squared_sum = 0.0;
  
  for (int i=0; i<3; ++i) {
  	squared_sum += (d[i]*d[i]);
  }
  
  return squared_sum;
}
~~~

Implementation 2

~~~cpp
float Vec::length() const
{
  return d[0]*d[0] + d[1]*d[1] + d[2]*d[2];
}
~~~

Notice the actual implementation of method length() doesn't change how this class may be used as seen below

~~~cpp
Vec v1(1,2,3);
cout << "length of v1 is " << v1.length() << endl;
~~~

#### Guidelines

- All members variables should be `private`
- Basic class operations should be
	- Public member functions
	- Friend or ordinary functions
	- Overloaded operators
- Keep class definition separate from class implementation
- Hide class implementation from users of class
- Users only see the header file
- Programs who want to use the class will "include" the header file containing class definition
	- Recall `#include <iostream>`
- Implementation file implements class functions
- Implementation file _must_ include class header file
- It is customary to give the same name to both header and implementation file, e.g.
	- Vec.h (header file) and Vec.cpp (implementation file) 

See example below.  We define Vec class in Vec.h file.

~~~cpp
// Vec.h

class Vec {
  protected:
  float d[3];
  
  Vec(float x, float y, float z);
   
  float length2() const;
};
~~~

And we implement Vec in Vec.cpp file.

~~~cpp
// Vec.cpp

#include "Vec.h"

Vec::Vec(float x, float y, float z)
{
  d[0] = x;
  d[1] = y;
  d[2] = z;
}

float Vec::length2() const
{
  return d[0]*d[0] + d[1]*d[1] + d[2]*d[2];
}
~~~

### Multiple compiles of header files

- A header file may be included multiple times, but it should only be __compiled once__.

Consider class A defined in header A.h.  This class is used in various places in the program.

~~~cpp
// A.h

class A { ... };
~~~

The class implementation resides in A.cpp

~~~cpp
// A.cpp

...
~~~

Say this class is used in the files B.cpp, C.cpp and D.cpp.

__B.cpp__

~~~cpp
// B.cpp

#include "A.h"

...
~~~

__C.cpp__

~~~cpp
// C.cpp

#include "A.h"

...
~~~

__D.cpp__

~~~cpp
// D.cpp

#include "A.h"

...
~~~ 

_Contents in A.h will be compiled everytime files B.cpp, C.cpp and D.cpp are compiled._  We can avoid this by using preprocessor directives, telling the compiler to compile the contents of A.h only once, as follows:

~~~cpp
// A.h

#ifndef FNAME_H
#define FNAME_H

class A { ... };

#endif
~~~

`#ifndef`, `#define` and `#endif` are preprocessors that can be used to _exclude_ portions of code from compilation.   Label FNAME is typically filename for consistency and readability.  E.g.,  FNAME_H is often chosen as `__A_H__`.

This prevents the contents of A.h to be compiled multiple times.

### Namespaces

- Used to create a collection of name definitions
	- Class definitions
	- Variable definitions
- Large programs use many classes and functions.  There are often name conflicts.  It is possible that two functions (say, in different files or coming from different libraries) have the same name.  Namespaces deal with such conflicts.
- We use the `using` directive to pull in the names of members/functions defined in a particular namespace
	- Example: `cout` is defined in namespace `std`.  We have the following three choices to use this in the code:
		- Case 1: Pull in the entire namespace `using namespace std; ... cout << ... ;`  
		- Case 2: Pull in only cout `using std::cout; ... cout << ...;`
		- Case 3: Use namespace for naming `std::cout << ...;
- In C++ all code is part of some namespace
	- If no namespace is specified then it is part of the _global_ namespace
	- Names in global namespace are always avaialable, and we don't need to use the `using` directive or one of its other variants (see above).
- If a name is defined in two names spaces than it is best to qualify it explicitly as follows: `namespace1::func();` and `namespace2::func()`.  I.e., we must specify which namespace to use at what time.
- `using` directive only pulls in the name in the current scope.  So if `using` directive is used inside a function, then the names in the namespace will only be visible in that function.

__Example 1__

Given namespace NS1 and NS2

~~~cpp
{
	using namespace NS1;
	func();
}
{
	using namespace NS2;
	func();
}
~~~

Or


~~~cpp
	NS1::func();
	NS2::func();
~~~

#### Defining a namespace 

- Use `namespace` keyword to define a namespace grouping

~~~cpp
namespace NS
{
	// Code goes here
}
~~~

__Example 1__ 

~~~cpp
namespace csci1061
{
  class Vec {
  };
}
~~~

Then we will use the file as follows

~~~cpp
using namespace csci1061;

Vec v;
~~~

or 

~~~cpp
csci1061::Vec v;
~~~

or 

~~~cpp
using csci1061::Vec;

Vec v;
~~~

__Example 2__

- Function declaration

~~~cpp
namespace NS1
{
  void greeting();
}
~~~

- Function definition

~~~cpp
namespace NS1
{
  void greeting() { cout << "Hello world." << endl; }
}
~~~

#### Declaration vs. directive

##### Declarations

Makes only one (the specified) name available, as seen below.  This prevents any other uses of the name.

~~~cpp
using NS1::getting;
~~~

##### Directive

Makes all names in the namespace available.   

~~~cpp
using namespace NS1;
~~~

#### Naming namespaces

- Always use unique strings
- Many programs choose to use last names, for example
- Can't have two namespaces with the same name

#### Unnamed namespaces

- Every compilation using has a namespace
	- All names are local to the compilation unit
- Use unnamed namespaces to keep things _local_
- Scope of unnamed namespace is compilation unit

##### Global vs. unnamed namespaces

- These are not the same
- Names in global namespace has global scope
- Names in local namespace has local scope, but no name

#### Nested namespaces

It is possible to have nested namespaces

~~~cpp
namespace NS1 {
  namepace NS2 {
    namespace NS3 {
      void func() { ... }
    }
  }
}  
~~~ 

We cam use func() as follows

~~~cpp
NS1::NS2::NS3::func();
~~~ 

#### Function hiding

Recall that we want to keep class implementation hidden from the user of that class.  Similarly, we may want to hide _helping_ functions (local level utilities used within other methods of the class, but not for general consumption) as well.

We can hide helping functions by making these private, or we can place these functions in class implementations unnamed space.

## More information

__More information about namespaces can be found at [http://en.cppreference.com/w/cpp/keyword/namespace](http://en.cppreference.com/w/cpp/keyword/namespace)__


  
