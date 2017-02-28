# CSCI 1061 - Programming Workshop 2

## Class Exercise Solution

### Dynamic Array Class Part 1

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

int main()
{
  Arr a(5);
  cin >> a;
  cout << "a = " << a << endl;

  Arr b(a);
  cout << "b = " << b << endl;

  b[2] = 3333;
  cout << "b = " << b << endl;
  
  return 0;
}
~~~