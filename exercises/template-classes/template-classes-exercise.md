# CSCI 1061U - Programming Workshop 2

## Class exercise - Templates

**This exercise is due before the end of the lecture.**

**Please submit on Blackboard.**

### Goal

Consider the following code.  It implements a fairly basic 3-dimension vector class.  

~~~cpp
#include <iostream>
using namespace std;

class vec3
{
  protected:
  double data[3];

  public:
  vec3() {}

  vec3(double x, double y, double z) {
    data[0] = x;
    data[1] = y;
    data[2] = z;
  }

  vec3(const vec3& v)
  {
    for (int i=0; i<3; ++i) {
      data[i] = v[i];
    }
  }

  const vec3& operator=(const vec3& v)
  {
    for (int i=0; i<3; ++i) {
      data[i] = v[i];
    }
    return *this;
  }
  
  double& operator[](int i) { return data[i]; }
  const double& operator[](int i) const { return data[i]; }

  void print();  

  friend double find_max(const vec3& v);
};

void vec3::print()
{
  cout << "(" << data[0] << "," << data[1] << "," << data[2] << ")" << endl;
}

double find_max(const vec3& v)
{
	double m = v[0];
	if (m < v[1]) m = v[1];
	if (m < v[2]) m = v[2];
	return m;
}

int main()
{
  vec3 v(1,2,3);
  v.print();
  cout << find_max(v) << endl;
  
  return 0;
}
~~~

Currently the vector class stores double values.  **You need to templatize it**, such that we can use this class to store values of other types as seen below. 

~~~cpp
  vec3<int> v(1,2,3);
  v.print();
  cout << find_max(v) << endl;

  vec3<char> v2('z','y','x');
  v2.print();
  cout << find_max(v2) << endl;
~~~

