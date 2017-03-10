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
