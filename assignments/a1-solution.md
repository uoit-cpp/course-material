# CSCI 1061U - Programming Workshop 2

## Assignment 1 Solution

**Total marks: 100**

### Q1 - Write a `wc` clone. (50 marks)

#### Solution

~~~cpp
#include <iostream>
#include <fstream>

using namespace std;

//#define DEBUG 
#define BUF_LEN 5

int main(int argc, char** argv)
{
  ifstream infile(argv[1]);
  if (!infile.is_open()) {
    cerr << "Cannot open " << argv[3] << " for reading." << endl;
    return -2; // returning a unique code to indicate this error
  }

  int num_bytes = 0;
  int num_lines = 0;
  int num_words = 0;
  bool word_consumed = false;
  
  char buf[BUF_LEN];
  int num_read;
  do {
    infile.read(buf, BUF_LEN-1);
    num_read = infile.gcount();

    if (num_read <= 0) break;

    // Update total bytes
    num_bytes = num_bytes + num_read;

    // examine characters for isspace or newlines
    for (int i=0; i<num_read; ++i)
    {
      if ( !isspace(buf[i]) && !word_consumed ) {
        word_consumed = true;
        ++num_words;
      }
      
      if ( isspace(buf[i]) ) {
        word_consumed = false;

        if (buf[i] == '\n' || buf[i] == '\r') ++num_lines;
      }
    }
    
#ifdef DEBUG   
    // Debug
    buf[num_read] = 0;
    cout << "Bytes read = " << num_read << ": [";
    cout << buf << "]" << endl;
#endif
    
  } while ( !infile.eof() );

  infile.close();

#ifdef DEBUG
  // Debug
  cout << "num lines = " << num_lines << endl;
  cout << "num words = " << num_words << endl;
  cout << "num bytes = " << num_bytes << endl;
#endif
  
  cout << '\t' << num_lines << '\t' << num_words << '\t' << num_bytes << ' ' << argv[1] << endl;
  
  return 0;
}
~~~

### Q2 - Write a program that can compress a text file consisting of English language alphabet [A-Z] using run-length encoding scheme. (50 marks)

#### Solution

~~~cpp
#include <iostream>
#include <fstream>

using namespace std;

#define DEBUG 
#define BUF_LEN 5

void encode(ifstream& infile, ostream& outfile)
{
  bool first_time = true;
  char ch;
  int cnt;
  
  char buf[BUF_LEN];
  int num_read;
  do {
    infile.read(buf, BUF_LEN-1);
    num_read = infile.gcount();

    if (num_read <= 0) break;

    // buf[num_read] = '\0';
    // cout << "["<< buf << "]" << endl;

    
    for (int i=0; i<num_read; ++i) {
      if (first_time) {
        first_time = false;
        ch = buf[i];
        cnt = 1;
        continue;
      }
          
      if (ch != buf[i]) {
        outfile << ch;
        if (cnt > 1) outfile << cnt;

        if (i < num_read) {
          ch = buf[i];
          cnt = 1;
        }
      }
      else {
        ++cnt;
      }
    }
  } while ( !infile.eof() );

  if (cnt > 0) {
    outfile << ch;
    if (cnt > 1) outfile << cnt;
  }
}

void decode(ifstream& infile, ostream& outfile)
{
  char ch;
  int cnt = 0;
  bool first_time = true;
  
  char buf[BUF_LEN];
  int num_read;
  do {
    infile.read(buf, BUF_LEN-1);
    num_read = infile.gcount();
    
    if (num_read <= 0) break;

    for (int i=0; i<num_read; ++i) {

      if (first_time) {
        ch = buf[i];
        first_time = false;
      }
    
      cout << "cnt = " << cnt << ", ";
      cout << "'" << buf[i] << "'";

      if (buf[i] >= 48 && buf[i] <= 57) {
        int d = ((int) buf[i]) - 48;
        cnt *= 10;
        cnt += d;        
        // int cnt1 = atoi(&buf[i]);
        // cnt = cnt + cnt1;

        cout << ", digit '" << buf[i] << "'"; 
      }
      else {
        if (ch != buf[i]) {
          outfile << ch;
          for (int j=0; j<cnt-1; ++j) outfile << ch;
          cnt = 0;
        }
      }

      if (cnt == 0) ch = buf[i];

      cout << endl;
    } 
  } while ( !infile.eof() );  

  outfile << ch;
  for (int j=0; j<cnt-1; ++j) outfile << ch;
}

/////////////////////////////////////////////////
//
// The following is only for testing.
// 
/////////////////////////////////////////////////
void cat(ifstream& infile, ostream& outfile)
{
  char buf[BUF_LEN];
  do {
    infile.read(buf, BUF_LEN-1);

    int num_read = infile.gcount();
    if (num_read <= 0) break;

    buf[num_read] = '\0';
    outfile << buf;
  } while(!infile.eof());
}

int main(int argc, char** argv)
{
  ifstream infile(argv[1]);
  if ( !infile.is_open() ) {
    cerr << "Cannot open " << argv[1] << " for reading." << endl;
    return 0;
  }
  cout << "Input file:" << endl;
  cat(infile, cout);
  infile.close();

  infile.open(argv[1]);
  ofstream outfile("foo.tmp");
  cout << "\nEncoding:" << endl;
  encode(infile, outfile);
  infile.close();
  outfile.close();
  
  infile.open("foo.tmp");
  outfile.open("foo.boo");
  cout << "\nDecoding:" << endl;
  decode(infile, outfile);
  infile.close();
  outfile.close();
  
  return 0;
}
~~~

### Some test files to use

#### test.txt

~~~txt
a
bb ccc d

eeeeee
fff
d

AAAAAAAAAAAAAAAAAA


~~~

#### Part 1

~~~bash
./wc test.txt
	10	8	47 test.txt
~~~

#### Part 2

Encoded file

~~~text
a
b2 c3 d
2e6
f3
d
2A18
3
~~~
