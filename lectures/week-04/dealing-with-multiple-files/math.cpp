// math.cpp

#include <iostream>
#include "Arr.h"
using namespace std;


double ave_arr(struct Arr& a)
{
  double sum=0.;

  for (int i=0; i<a.sz; i++) {
    sum = sum + a.arr[i];
  }

  return sum / (double) a.sz;
}
