#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ///////////////////////////////////////////////////////
  ofstream f("numbers.txt", ios::binary);
  if (f.is_open()) {
    cout << "Successfully opened \"numbers.txt\" for writing.\n"; 
    
    double pi = 3.14159;
    int century = 100;

    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;

    f.write((char*)&pi, sizeof(double));
    f.write((char*)&century, sizeof(int));    
    
    f.close(); // Don't forget to close the file stream
  }
  else {
    cerr << "Error opening \"numbers.txt\" for writing.\n";
  }

  ///////////////////////////////////////////////////////
  ifstream f2("numbers.txt", ios::binary);
  if (f2.is_open())
  {
    cout << "Successfully opened \"numbers.txt\" for reading.\n";

    double d;
    int i;
    
    f2.read((char*)&d, sizeof(double));
    f2.read((char*)&i, sizeof(int));
    cout << "d: " << d << endl;
    cout << "i: " << i << endl;

    f2.close();
  }
  else {
    cerr << "Error opening \"numbers.txt\" for reading.\n";
  }

  ///////////////////////////////////////////////////////
  ifstream f3("numbers.txt", ios::binary);
  if (f3.is_open())
  {
    cout << "Successfully opened \"numbers.txt\" for reading.\n";

    int i;

    f3.seekg(sizeof(double), ios::beg);
    f3.read((char*)&i, sizeof(int));
    cout << "i: " << i << endl;

    f3.close();
  }
  else {
    cerr << "Error opening \"numbers.txt\" for reading.\n";
  }

  
  return 0;
}
