#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

extern int count(char* input, int n, int* count);

int main(int argc, char** argv)
{
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <count>" << endl;
    cerr << "\t<count> is an integer between 10 and 10000\n";
    cerr << "\tExiting.";
    return -1;
  }

  int n = atoi(argv[1]);
  if (n < 10 || n > 10000) {
    cerr << "Usage: " << argv[0] << " <count>" << endl;
    cerr << "\t<count> is an integer between 10 and 10000\n";
    cerr << "\tExiting.";
    return -2;
  }
  
  srand(time(NULL));
  // int* arr = new int[n];
  // for (int i=0; i<n; ++i) {
  //   arr[i] = rand();
  // }
  char* arr = new char[n];
  for (int i=0; i<n; ++i) {
    char c =  (char) (floor((rand() / (double) RAND_MAX) * 25.0) + 65);
    arr[i] = c;
  }

  for (int i=0; i<n; ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;

  int counts[26];
  for (int i=0; i<26; ++i) counts[i] = 0;  
  count(arr, n, counts);
  for (int i=0; i<26; ++i) {
    cout << (char) (i+65) << " = " << counts[i] << endl;
  }
  
  delete [] arr;

  return 0;
}
