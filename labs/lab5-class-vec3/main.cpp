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
