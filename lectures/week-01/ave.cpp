#include <iostream>
using namespace std;

int main()
{
  double accum = 0.0;
  int n = 0;
  double num;

  do {

    cout << "Enter a number (-1 to exit): ";
    cin >> num;

    if (num != -1) {
      accum = accum + num;
      ++n;
    }

  } while (num != -1);

  cout << "Average is: " << accum/(double) n << endl;

  return 0;
}




