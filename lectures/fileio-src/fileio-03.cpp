#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream f("numbers.txt");
  if (f.is_open()) {
    cout << "Successfully opened \"numbers.txt\" for writing.\n"; 
    
    f << 3.14159 << '\n';
    f << 8321 << '\n';
    
    f.close(); // Don't forget to close the file stream
  }
  else {
    cerr << "Error opening \"numbers.txt\" for writing.\n";
  }

  return 0;
}
