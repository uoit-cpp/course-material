#include <iostream>
#include <fstream>

using namespace std;

// Defining a structure
struct my_struct {
  char c;
  int i;
  float f;
};

void func(my_struct s) {
  my_struct s1 = s;
  cout << "s1.c = " << s1.c << endl;
  cout << "s1.i = " << s1.i << endl;
  cout << "s1.f = " << s1.f << endl;    
}

int main(int argc, char** argv)
{
  cout << "size of char   = " << sizeof(char) << endl;
  cout << "size of int    = " << sizeof(int) << endl;
  cout << "size of short  = " << sizeof(short) << endl;
  cout << "size of long   = " << sizeof(long) << endl;
  cout << "size of float  = " << sizeof(float) << endl;
  cout << "size of double = " << sizeof(double) << endl;

  cout << "\nDefining a structure" << endl;
  my_struct s;
  s.c = 'a';
  s.i = 34;
  s.f = 124.0;
  cout << "s.c = " << s.c << endl;
  cout << "s.i = " << s.i << endl;
  cout << "s.f = " << s.f << endl;
  cout << "size of my_struct = " << sizeof(s) << endl;  

  // Another way to define a structure
  cout << "\nAnother way to define a structure" << endl;
  typedef struct {
    long j;
  } my_struct_2;

  my_struct_2 s2;
  s2.j = 332L;
  cout << s2.j << endl;

  // Reading and writing structures from files
  cout << "\nReading and writing structures" << endl;
  ofstream f1("tmp.dat", ios::binary);
  f1.write((char*) &s, sizeof(s));
  f1.close();

  ifstream f2("tmp.dat", ios::binary);
  my_struct s3;
  f2.read((char*)&s3, sizeof(s3));
  f2.close();
  cout << "s3.c = " << s3.c << endl;
  cout << "s3.i = " << s3.i << endl;
  cout << "s3.f = " << s3.f << endl;

  // Passing structures as arguments
  cout << "\nPassing structures as arguments" << endl;
  func(s3);

  // Structures assignments
  cout << "\nStructure assignments" << endl;
  my_struct s4;
  s4 = s3;
  cout << "s4.c = " << s4.c << endl;
  cout << "s4.i = " << s4.i << endl;
  cout << "s4.f = " << s4.f << endl;

  return 0;
}
