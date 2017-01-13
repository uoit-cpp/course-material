#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream f("num.txt");

  for (int i=0; i<10; ++i)
  {
    // Try one of the following and see how it
    // affects reading
    f << i << endl;
    //f << i;
    //f << i << " ";
  }
  f.close();

  return 0;
}
