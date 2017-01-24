#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  ifstream log(argv[1], ios::binary);

  char op;
  float num1, num2;

  log.seekg(-sizeof(char)-2*sizeof(float), ios::end);
  
  log.read((char*) &op, sizeof(char));
  log.read((char*) &num1, sizeof(float));
  log.read((char*) &num2, sizeof(float));

  cout << op << ' ' << num1 << ' ' << num2 << endl;
  
  log.close();
  
  return 0;
}
