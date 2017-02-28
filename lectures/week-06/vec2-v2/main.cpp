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
