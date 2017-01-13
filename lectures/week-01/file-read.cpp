#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream f("num.txt");
  if (f.is_open())
  {
    int v;
  
    do {
      f >> v;
      if (f) {
        cout << v << endl;
      }

      if (f.eof())
      {
        cout << "End of file reached." << endl;
        return 0;
      }
      
      if (f.fail()) {
        cerr << "Error reading." << endl;
        return -2;
      }

    } while(true);

    f.close();
  }
  else {
    cerr << "Cannot open it." << endl;
    return -1;
  }

  return 0;
}
