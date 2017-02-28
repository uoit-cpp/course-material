#include <iostream>
#include "vec2.h"

using namespace std;

int main()
{
  vec2 a;
  a.x = 1.5;
  a.y = 2.7;

  vec2 b(2.4, 54.4);
  //cout << "length of b = " << b.length() << endl;
  
  cout << "a = (" << a.x << "," << a.y << ")" << endl; 
  cout << "b = (" << b.x << "," << b.y << ")" << endl; 

  vec2* c = new vec2(9.9999);
  cout << "c = (" << c->x << "," << c->y << ")" << endl; 
  delete c;

  b = a;
  cout << "b = (" << b.x << "," << b.y << ")" << endl; 
  
  return 0;
}
