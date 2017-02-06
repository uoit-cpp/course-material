#include <iostream>
#include <fstream>

using namespace std;

#define BUF_LEN 5

void caeser_cipher(char* pStr, int n, int shift)
{
  for (int i=0; i<n; ++i)
  {
    char c = pStr[i];
    if (c < 65 || c > 90) continue;

    c = 65 + (((c-65) + shift) % 26);
    pStr[i] = c;
  }
}

int main(int argc, char** argv)
{
  char flag = argv[1][1];
  int shift = atoi(argv[2]);

  int s;
  switch (flag) {
    case 'e':
      s = shift;
      if (shift < 0) s = 26 + s;  
      shift = s;
      break;
    case 'd':
      s = -shift;
      if (s < 0) s = 26 + s;
      shift = s;
      break;
    default:
      cerr << "Invalid flag." << endl;
      cerr << "Usage ./cf [-e|-f] shift infile outfile" << endl;
      return -1; // returning a unique code to indicate this error
  }
  
  ifstream infile(argv[3]);
  if (!infile.is_open()) {
    cerr << "Cannot open " << argv[3] << " for reading." << endl;
    return -2; // returning a unique code to indicate this error
  }

  ofstream outfile(argv[4]);
  if (!outfile.is_open()) {
    cerr << "Cannot open " << argv[4] << " for writing." << endl;
    return -3; // returning a unique code to indicate this error
  }

  char buf[BUF_LEN];
  int num_read;
  do {
    infile.read(buf, BUF_LEN-1);
    num_read = infile.gcount();

    if (num_read <= 0) break;

    // // Debug
    // buf[num_read] = 0;
    // cout << "Bytes read = " << num_read << ": [";
    // cout << buf << "]" << endl;

    // cipher text
    caeser_cipher(buf, num_read, shift);
    
    // write to output file
    outfile.write(buf, num_read);    
  } while ( !infile.eof() );

  infile.close();
  outfile.close();
  
  return 0;
}
