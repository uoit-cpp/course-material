// main.cpp

#include <iostream>
#include "Arr.h"
using namespace std;


extern void prn_arr(struct Arr& a);
extern double ave_arr(struct Arr& a);

int main()
{
  int i = 0;
  Arr a;
  // double arr[10];
  // int sz;
  
  do {
    double tmp;
    cin >> tmp;

    if (tmp < 0) {
      a.sz = i;
      break;
    }

    a.arr[i] = tmp;
    i = i + 1;
  } while(true);

  prn_arr(a);
  cout << ave_arr(a) << endl;
  
  return 0;
}
