#include <iostream>

using namespace std;

void count(char* input, int n, int* count)
{
  for (int i=0; i<n; ++i)
  {
    cout << ((int) input[i] - 65) << endl;
  
    count[(int) input[i]-65] = count[(int) input[i]-65] + 1;
  }
}
