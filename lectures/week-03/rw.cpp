#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  fstream f("tmp.dat", ios::binary | ios::in | ios::out);

  for (int i=0; i<10; ++i) {
    f.write((char*)&i, sizeof(int));
  }
  f.flush();

  f.seekg(5*sizeof(int), ios::beg);
  int d;
  f.read((char*)&d, sizeof(int));
  cout << "Read at location 5: " << d << endl; 

  cout << "Read pointer = " << f.tellg() << endl;
  cout << "Write pointer = " << f.tellp() << endl;
  
  f.close();
  
  return 0;
}
