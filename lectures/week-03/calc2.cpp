#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

// Do this
//
// $ c + 3 5
// $ c - 43 4 
// $ c * 5 5
// $ c / 22 7


int main (int argc, char** argv)
{
  // argc = number of arguments
  // argv[0] = name of the program --- char array
  // argv[1] = first argument --- char array
  // ...

  ofstream log("c.log", ios::app);
  
  char op = argv[1][0];
  float n1 = atof(argv[2]);
  float n2 = atof(argv[3]);

  log << op << ' ' << n1 << ' ' << n2 << endl;
  log.close();
  
  switch (op) {
    case '+': cout << n1 + n2 << endl; break;
    case '-': cout << n1 - n2 << endl; break;
    case '/': cout << n1 / n2 << endl; break;
    case '*': cout << n1 * n2 << endl; break;
    default: cout << "oops" << endl;
  }
  
  return 0;
}
