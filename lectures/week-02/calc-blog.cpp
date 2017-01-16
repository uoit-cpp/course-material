#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  char op;
  double v1, v2, ans;

  op = argv[1][0];
  v1 = atof(argv[2]);
  v2 = atof(argv[3]);

  switch (op)
  {
    case '+': ans = v1 + v2; break;
    case '-': ans = v1 - v2; break;
    case '/': ans = v1 / v2; break;
    case 'x': ans = v1 * v2; break;
  }
  
  cout << v1 << " " << op << " " << v2 << " = " << ans << endl;

  ofstream f("log.bin", ios::app | ios::binary);
  if (f.is_open()) {
    f.write((char*)&op, sizeof(char));
    f.write((char*)&v1, sizeof(double));
    f.write((char*)&v2, sizeof(double));
    f.write((char*)&ans, sizeof(double));    
    f.close();
  }
  else {
    cerr << "Error saving log."  << endl;
  }
  
  return 0;
}
