#include <iostream>
#include "Arr.h"
using namespace std;


void prn_arr(struct Arr& a)
{
  for (int i=0; i<a.sz; i++) {
    cout << a.arr[i] << ' ';
  }
  cout << endl;
}
