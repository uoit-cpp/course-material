#include <iostream>

using namespace std;

void print_bit_pattern(char *d, int sz)
{
  char mask = 1;

  for (int i=0; i<8; ++i) {
    if (mask & d[i]) {
      cout << "bit at " << i << " is 1" << endl;
    }
    else {
      cout << "bit at " << i << " is 0" << endl;
    }
    mask = mask << 1;
  }
}

int main()
{
  char c='A';  // 01000001
  print_bit_pattern(&c, 1);
  
  return 0;
}
