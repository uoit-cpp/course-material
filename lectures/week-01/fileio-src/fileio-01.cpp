#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream f("numbers.txt");
  if (f.is_open()) {
    cout << "Successfully opened \"numbers.txt\" for reading.\n"; 
    
    string line;
    while ( getline(f, line) ) // getline() returns a true if 
                               // it successfully reads a line
                               // from the file; otherwise, it 
                                 // returns false. 
    {
      cout << line << '\n';   
    }
    
    f.close(); // Don't forget to close the file stream
  }
  else {
    cerr << "Error opening \"numbers.txt\" for reading.\n";
  }

  return 0;
}
