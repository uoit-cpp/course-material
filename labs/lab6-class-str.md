# CSCI 1061U - Programming Workshop 2

## Lab 6 - C++ Classes 

**Due back on Saturday, March 11 before 11:59 pm.**

### Objectives ###

We all love the `std::string` class.  So lets make our own.  The goal today is to create a simple `str` class that _mimic_ the functionality of the `std::string` class.  To keep things civilized, I have taken the liberty of implementing part of the `str` class.  You are asked to complete the rest of the functions.

#### Task

Please implement your functions in the str.cpp class.

##### Header file declaring `str` class.

~~~cpp
// str.h

#ifndef __str_h__
#define __str_h__

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


class str
{
  protected:
  char* _buf;  // pointer to the underlying storage
  int _n;      // size of the buffer

  public:
  
  // constructors of various forms
  str();      
  str(int n);  
  str(char ch);
  str(const char* c_str);

  // lets not forget the destructor
  ~str();

  // inline functions for finding length info of the str
  inline const int& length() const { return _n; }
  inline bool is_empty() const { return length() == 0; }

  // index operators
  char& operator[](int i) { return _buf[i]; }
  const char& operator[](int i) const { return _buf[i]; }
  
  // TODO 1. You need to implement the assignment operator
  const str& operator=(const str& s);

  // TODO 2. You need to implement the + operator concatenates two str
  friend str operator+(const str& a, const str& b);

  friend ostream& operator<<(ostream& os, const str& s);
  friend istream& operator>>(istream& is, str& s);
};

#endif
~~~

##### Meanwhile the `str.cpp` file looks like

~~~cpp
// str.cpp

#include "str.h"

str::str() : _n(0), _buf(0)
{}

str::str(int n) : _n(n)
{
  _buf = new char[_n];
}

str::str(char ch) : _n(1)
{
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str)
{
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i=0; i<_n; ++i) _buf[i]=c_str[i];
}

str::~str()
{
  if (_buf) delete [] _buf;
}

ostream& operator<<(ostream& os, const str& s)
{
  if (!s.is_empty()) {
    for (int i=0; i<s.length(); ++i) {
      cout << s[i];
    }
  }
  else cout << "[null str]";
  
  return os;
}

istream& operator>>(istream& is, str& s)
{
  char ch;
  do {
    ch = is.get();
    if (ch == ' ' || ch == '\n') break;
    s = s + ch;
  } while(true);

  return is;
}

// 1. TODO - assignment operator

// 2. TODO - concatenation operator
~~~

##### And the `main.cpp` is

~~~cpp
// main.cpp

#include "str.h"

int main()
{
  str s1; 
  cout << s1 << endl;
  
  str s2("Hello"); 
  cout << s2 << endl;
  
  str s3("World");

  str s4 = s2 + " " + s3;
  cout << s4 << endl;

  str s5, s6;
  cin >> s5 >> s6;
  cout << s5 << ' ' << s6;
  
  return 0;
}
~~~

When I compile and run the code (`g++ main.cpp str.cpp -o str`) I get the following output

~~~bash
$ ./str <---- user
[null str]
Hello
Hello World
123 345 <---- user
123 345
~~~

###Submission

Please submit the completed `str.cpp` file via Blackboard.