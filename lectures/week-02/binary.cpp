#include <iostream>
#include <string>

using namespace std;

string to_binary(char* c, int n)
{
  char mask=0x01;
  string b;
  b.resize(8*n);

//  cout << "mask = " << (int) mask << endl;
//  cout << "c = " << (int) c[0] << endl;

  for (int j=0; j<n; ++j) {
    for (int i=7; i>=0; --i) {
//      cout << "mask >> " << i << " is " << (unsigned int) (mask << i) << ", ";
      if (c[j] & (mask << i)) {
        b[j*8 + (7-i)] = '1';
//        cout << "Found a 1 at " << i << endl;
      }
      else {
        b[j*8 + (7-i)] = '0';
//        cout << "Found a 0 at " << i << endl;
      }
    }
  }
  
  return b;
}

int main()
{
  char c='A';
  cout << c << " in binary is " << to_binary(&c, 1) << endl;

  c='B';
  cout << c << " in binary is " << to_binary(&c, 1) << endl;

  int i = 64;
  cout << i << " in binary is " << to_binary((char *)&i, sizeof(int)) << endl;  

  double d = 64.0;
  cout << d << " in binary is " << to_binary((char *)&d, sizeof(double)) << endl;  

  
  return 0;
}
