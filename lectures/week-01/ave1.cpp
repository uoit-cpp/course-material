#include <iostream>
using namespace std;

int main()
{
  double accum = 0.0;
  int n = 0;
  double num;

  for (;;) {

    cout << "Enter a number (-1 to exit): ";
    cin >> num;

    if (num != -1) {
      accum = accum + num;
      ++n;
      continue;  // Lets go ask for the next number
    }

    break; // If we find ourselves here, it means that
           // the user has entered a -1.
  }
  
  cout << "Average is: " << accum/(double) n << endl;

  return 0;
}




