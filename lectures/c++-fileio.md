# Lecture 2 Notes: File IO

C++ provides iostream library to read from and write to files.  iostream library defines three data types to constructs i/o streams attached to files.  

Data Type | Description
----------|------------
ofstream | This data type represents the output file stream and is used to create files and to write information to files. 
ifstream | This data type represents the input file stream and is used to read information from files.
fstream | This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.

Once an file i/o stream is ready, it behaves similarly to standard streams that you are already familiar with, such as `cin`, `cout` and `cerr`, with a few caveats that we discuss below.  

__Note__: To perform file processing in C++, header files `<iostream>` and `<fstream>` must be included in your C++ source file.

## Reading from a file

### Opening a file for reading

~~~cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("names.txt");
	if (f.is_open()) {
		cout << "Successfully opened \"names.txt\" for reading.\n"; 
		
		// Read contents here
		
		f.close(); // Don't forget to close the file stream
	}
	else {
		cerr << "Error opening \"names.txt\" for reading.\n";
	}

	return 0;
}
~~~

### Reading file contents

#### Example: Numbers, one per line

Say we want to read the following file:

~~~txt
1342
23
354
~~~

This file contains 3 numbers.  Each number is on its own line.  

##### Choice 1

Read these numbers as strings

~~~cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream f("numbers.txt");
	if (f.is_open()) {
		cout << "Successfully opened \"numbers.txt\" for reading.\n"; 
		
		string line;
		while ( getline(f, line) ) // getline() returns a true if 
        		                   // it successfully reads a line
                		           // from the file; otherwise, it 
                       		       // returns false. 
		{
			cout << line << '\n';		
		}
		
		f.close(); // Don't forget to close the file stream
	}
	else {
		cerr << "Error opening \"numbers.txt\" for reading.\n";
	}

	return 0;
}
~~~

The above program will output

~~~bash
1342
23
354
~~~

###### Experiment

What will happen if the numbers are stored as

~~~txt
1342 23 354
~~~

What will be the output of the above program (choice 1)?

##### Choice 2

Read these numbers as integers

~~~cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("numbers.txt");
	if (f.is_open()) {
		cout << "Successfully opened \"numbers.txt\" for reading.\n"; 
		
		while ( !f.eof() ) // eof() method checks wether we
		                   // have reached the end-of-file.
		{
			f >> num;
			cout << num << '\n';
		}
		
		f.close(); // Don't forget to close the file stream
	}
	else {
		cerr << "Error opening \"numbers.txt\" for reading.\n";
	}

	return 0;
}
~~~

The above program will output

~~~bash
1342
23
354
~~~

###### Experiment

Lets repeat the experiment.  What will happen if the numbers are stored as

~~~txt
1342 23 354
~~~

What will be the output of the above program (choice 2)?

_Is it the same output?  If not, why not?_

#### Things to try

- What happens if the file that you want to read doesn't exist?
- What if file disappears in the middle of a read?  Say a file consists of a billion entries, and a hacker deletes it in the middle of a read?


## Writing to a file

### Opening a file for writing

~~~cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream f("names.txt");
	if (f.is_open()) {
		cout << "Successfully opened \"names.txt\" for writing.\n"; 
		
		// Writes contents to the file here
		
		f.close(); // Don't forget to close the file stream
	}
	else {
		cerr << "Error opening \"names.txt\" for writing.\n";
	}

	return 0;
}
~~~

### Writing to a file: numbers, one per line

Lets save a list of numbers to a file.

~~~cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream f("numbers.txt");
	if (f.is_open()) {
		cout << "Successfully opened \"numbers.txt\" for writing.\n"; 
		
		f << 13432 << '\n';
		f << 132 << '\n';
		f << 1432 << '\n';
		
		f.close(); // Don't forget to close the file stream
	}
	else {
		cerr << "Error opening \"numbers.txt\" for writing.\n";
	}

	return 0;
}
~~~

When you compile and run this program one of the following two will happen:

- if numbers.txt file doesn't exist, it will be created.
- if numbers.txt already exists, it will be overwritten.

The contents of this file will be

~~~txt
13432
132
1432
~~~

#### Problem

The above code overwrites the file everytime it opens it for writing.  We can solve this issue by tell the system to open file in the append mode.  Replace

~~~cpp
ofstream f("numbers.txt");
~~~

with

~~~cpp
ofstream f("numbers.txt", ios::app);
~~~

`ios::app` flag sets up ofstream for appending.  

##### Exercise

Now make this change, delete numbers.txt file, and run the above program three times.  What are the contents of numbers.txt file?  Try once using `ios::app` and once without it.

## Case Studies

### 3D vectors: load and store

Develop a program that can store (and load) 3D vectors to (from) a file.  Each 3D vector consists of 3 floating point numbers.  We can store these numbers as doubles.



