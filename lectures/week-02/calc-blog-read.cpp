#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  char op;
  double v1, v2, ans;

  ifstream f("log.bin", ios::binary | ios::end);
  if (!f.is_open()) {
    cerr << "Error opening log.bin" << endl;
    return -1;
  }

  size_t sz = sizeof(char) + 3 * sizeof(double);
  //f.seekg(0, ios::end);

  while (f.tellg() != 0) {
    f.seekg(-sz, ios::cur);
    f.read((char*)&op, sizeof(char));
    f.read((char*)&v1, sizeof(double));
    f.read((char*)&v2, sizeof(double));
    f.read((char*)&ans, sizeof(double));
    f.seekg(-sz, ios::cur);
  
    if (f) {  
      cout << v1 << " " << op << " " << v2 << " = " << ans << endl;
    }
    else {
      cerr << "Some error occured." << endl;
      cerr << v1 << " " << op << " " << v2 << " = " << ans << endl;
    }
  }
    
  f.close();
  
  return 0;
}
