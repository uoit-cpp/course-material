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

int MIN(int a, int b)
{
  if (a < b) return a;
  return b;
}

int main()
{
  ofstream f("employees.dat", ios::app | ios::binary);
  if ( !f.is_open() ) {
    cerr << "Cannot open employees.dat for writing.  Not sure what to do.";
    return -1;
  }

  Employee e;
  
  string fname;
  cout << "Enter name: ";
  cin >> fname;

  string lname;
  cout << "Enter name: ";
  cin >> lname;

  cout << "Enter id: ";
  cin >> e.id;

  double wage;
  cout << "Enter wage: ";
  cin >> e.wage;

  strncpy(e.fname, fname.c_str(), MIN(fname.length(), 16));
  strncpy(e.lname, lname.c_str(), MIN(lname.length(), 16));

  f.write((char*)&e, sizeof(Employee));
  
  f.close();
  return 0;
}
