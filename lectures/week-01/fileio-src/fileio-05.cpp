#include <iostream>
#include <fstream>
#include <cstdlib> // For rand(), srand()
#include <ctime> // for time()

using namespace std;

int main()
{

  /////////////////////////////////////////////////////////////////////
  cout <<  "\nTask 1: write 100 integers to a file." << endl;
  ofstream f1("data", ios::binary);
  if (f1.is_open()) {
    int i;
    for (i=0; i<100; ++i) {
      f1.write((char*) &i, sizeof(int));

      if (f1.fail()) {
        cerr << "Write failed\n";
        cerr << "Wrote: " << i << " numbers.\n";
        break;
      }      
    }
    f1.close();
  }

  /////////////////////////////////////////////////////////////////////
  cout <<  "\nTask 2: read 100 integers from a file." << endl;
  ifstream f2("data", ios::binary);
  if (f2.is_open()) {
    int i, d;
    for (i=0; i<100; ++i) {
      f2.read((char*) &d, sizeof(int));
      cout << d << " ";

      if (f2.fail()) {
        cerr << "Read fail\n";
        cerr << "Read: " << i << " numbers.\n";
        break;
      }
      if (f2.eof()) {
        cerr << "EOF reached\n";
        cerr << "Read: " << i << " numbers.\n";
        break;
      }
    }
    cout << endl;    
    f2.close();
  }

  /////////////////////////////////////////////////////////////////////
  cout <<  "\nTask 3: read 50th number" << endl;
  ifstream f3("data", ios::binary);
  if (f3.is_open()) {
    int d;
    f3.seekg(sizeof(int)*49, ios::beg);
    f3.read((char*)&d, sizeof(int));
    
    if (!f3.fail()) {
      cout << d << endl;
    }
    else {
      cerr << "Error reading.";
    }
    f3.close();
  }

  /////////////////////////////////////////////////////////////////////
  cout <<  "\nTask 4: change 50th number to 50000" << endl;
  fstream f4("data", ios::binary | ios::in | ios::out);
  if (f4.is_open()) {
    int d = 50000;
    cout << d << endl;

    f4.clear();
    f4.seekg(0);
    cout << f4.tellg() << endl;
        
    f4.seekp(sizeof(int)*49, ios::beg);
    cout << f4.tellp() << endl;

    f4.write((char*)&d, sizeof(int));
    f4.flush();
    
    if (f4.fail()) {
      cerr << "Error writing.";
    }
    f4.close();
  }
  else {
    cerr << "Error opening to change 50th number\n";
  }

  /////////////////////////////////////////////////////////////////////
  cout <<  "\nTask 5: read 100 integers from a file." << endl;
  ifstream f5("data", ios::binary);
  if (f5.is_open()) {
    int i, d;
    for (i=0; i<100; ++i) {
      f5.read((char*) &d, sizeof(int));
      cout << d << " ";

      if (f5.fail()) {
        cerr << "Read fail\n";
        cerr << "Read: " << i << " numbers.\n";
        break;
      }
      if (f5.eof()) {
        cerr << "EOF reached\n";
        cerr << "Read: " << i << " numbers.\n";
        break;
      }
    }
    cout << endl;
    f5.close();
  }

  /////////////////////////////////////////////////////////////////////
  cout << "\nTask 6: random numbers" << endl;
  cout << "RAND_MAX: " << RAND_MAX << endl;

  srand(0);                    // Defined in <cstdlib>
  cout << "Repeatable random numbers: " << rand() << endl;

  srand(time(0));                    // Defined in <cstdlib>
  cout << "Non-repeatable random numbers: " << rand() << endl;
  
  return 0;
}
