#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  ifstream log(argv[1]);

  char op;
  int num1, num2;

  while ( !log.eof() ) 
  {
    log >> op;
    log >> num1;
    log >> num2;
  };

  cout << op << ' ' << num1 << ' ' << num2 << endl;
  
  log.close();
  
  return 0;
}
