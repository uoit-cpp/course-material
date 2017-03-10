#include <iostream>
#include "Mat.h"

int main()
{
  Mat a(2,3);
  a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
  a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
  cout << a << endl;

  Mat b(2,3);
  b[0][0] = 10; b[0][1] = 20; b[0][2] = 30;
  b[1][0] = 40; b[1][1] = 50; b[1][2] = 60;
  cout << b << endl;

  Mat c = a + b;
  cout << c << endl;

  Mat d = c - b;
  cout << d << endl;

  d += 10000;
  cout << d << endl;

  d -= 1000;
  cout << d << endl;

  d *= 10;
  cout << d << endl;

  d /= 5;
  cout << d << endl;

  srand(0);
  d.rand();
  cout << d << endl;

  Mat e(2,4);
  Mat f(4,3);
  cin >> e;
  cin >> f;
  cout << e << endl;
  cout << f << endl;    
  cout << (e * f) << endl;
  

  // Mat a; cin >> a;
  // Mat b; cin >> b;
  // cout << (a * b) << endl;
  
  return 0;
}

