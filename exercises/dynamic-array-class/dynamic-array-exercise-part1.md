# CSCI 1061 - Programming Workshop 2

## Class Exercise

__Must be completed during the class__  See submission instructions below.

### A Dynamic Array Class

Write a `Arr` class that implements a dynamic array for storing double values.  It should have the following functionality.

#### Declare a double array of size 0

~~~cpp
Arr a;
~~~

#### Declare a double array of size n, 3 in the following example

~~~cpp
Arr a(3);
a[0] = 1.2;
a[1] = 32;
a[2] = 3;
a[3] = 3; // Should print, "array bounds exceeded."
~~~ 

#### Declare an array using an existing error

~~~cpp
Arr a(3);
a[0] = 1.2;
a[1] = 32;
a[2] = 3;

Arr b(a); // b is a copy of a.
          // It has same length as a,
          // and same values.
~~~

#### Compiler should give an error on the following

~~~cpp
Arr a(3);
Arr b(3);

a = b; // This should not be allowed
~~~

#### Extraction and Insertion operators should be supported

~~~cpp
Arr a(3)
cin >> a; // This should print "Expecting 3 numbers" to standard out.
          // And read in the 3 entries.
cout << "a = " << a << endl; // This should print out the 3 entries.
~~~

#### Don't forget to release the dynamically allocated memory

Meaning, don't forget the destructor.

#### Template file

Use the following template to complete the file.  You may put the `Arr` class and the `main()` function in one class.  Don't bother with header and cpp files keep things relatively straightforward.

~~~cpp
// main.cpp file

#include <iostream>
#include <cassert>

using namespace std;

class Arr
{
	// TO DO
};

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