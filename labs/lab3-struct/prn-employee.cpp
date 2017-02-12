#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
  char fname[16];
  char lname[16];
  int id;
  double wage;
};

int main()
{
  ifstream f("employees.dat", ios::binary);
  if ( !f.is_open() ) {
    cerr << "Cannot open employees.dat for reading.  Not sure what to do.";
    return -1;
  }

  Employee e;
  f.read((char*) &e, sizeof(Employee));
  
  cout << string(e.fname, 0, 16) << endl;
  cout << string(e.lname, 0, 16) << endl;
  cout << e.id << endl;
  cout << e.wage << endl;
  
  f.close();
  return 0;
}
