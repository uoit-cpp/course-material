#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
  stringstream ss;

  ss << "This is a message that I am saving into a string stream.";

  char c;
  ss >> c;
  
  cout << "ss = [" << c << "]" << endl;

  cout << "tellp = " << ss.tellp() << endl; 
  cout << "tellg = " << ss.tellg() << endl;
  
  return 0;
}
