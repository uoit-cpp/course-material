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
  
  return 0;
}
