#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  ifstream in(argv[1], ios::binary);
  ofstream out(argv[2], ios::binary);

  if ( !in.is_open() ) {
    cerr << "Cannot open " << argv[1] << endl;
    return -1;
  }

  char buf[1000];
  while (true)
  {
    in.read(buf, 1000);
    int n_read = in.gcount();
    cout << "Read " << n_read << " bytes." << endl;

    if (n_read <= 0) break;

    out.write(buf, n_read);
  }
  
  in.close();
  out.close();

}
