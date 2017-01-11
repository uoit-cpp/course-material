# Lecture 2 Notes: File IO

__Faisal Qureshi__  
faisal.qureshi@uoit.ca 

C++ provides __iostream__ library to read from and write to files.  iostream library defines three data types to constructs i/o streams attached to files.  

Data Type | Description
----------|------------
ofstream | This data type represents the output file stream and is used to create files and to write information to files. 
ifstream | This data type represents the input file stream and is used to read information from files.
fstream | This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.

Once an file (IO) stream is ready, it behaves similarly to standard streams that you are already familiar with, such as `cin`, `cout` and `cerr`, with a few caveats that we discuss below.  

__Note__: To perform file processing in C++, header files `<iostream>` and `<fstream>` must be included in your C++ source file.

## Reading from a file

### Opening a file for reading

Use

~~~cpp
ifstream f("filename.txt");
~~~

or 

~~~cpp
ifstream f;
f.open("filename.txt");
~~~

To setup `f` as the read stream from file `filename.txt`.  See the code below.

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

Use `getline()` method

~~~cpp
...
if (f.is_open()) {
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
...
~~~

[Source code](fileio-src/fileio-01.cpp)

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

Use extraction operator `>>`

~~~cpp
...
if (f.is_open()) {
	while ( !f.eof() ) // eof() method checks wether we
	                   // have reached the end-of-file.
	{
		int num;
		f >> num;
		cout << num << '\n';
	}
	
	f.close(); // Don't forget to close the file stream
}
...
~~~

The above program will output

~~~bash
1342
23
354
~~~

[Source code](fileio-src/fileio-02.cpp)

###### Experiment

Lets repeat the experiment.  What will happen if the numbers are stored as

~~~txt
1342 23 354
~~~

What will be the output of the above program (choice 2)?

_Is it the same output?  If not, why not?_

#### Things to try

- What happens if the file that you want to read doesn't exist?
- What if file disappears in the middle of a read?  Say a file sits on an external USB drive and someone yanks it out in a middle of a read?


## Writing to a file

### Opening a file for writing

Use

~~~cpp
ofstream f("filename.txt");
~~~

or 

~~~cpp
ofstream f;
f.open("filename.txt");
~~~

See the code below

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

Lets save a list of numbers to a file using insertion operator `<<` .

~~~cpp
...
if (f.is_open()) {
	f << 3.14159 << '\n';
	f << 8321 << '\n';
	
	f.close(); // Don't forget to close the file stream
}
...
~~~

[Source code](fileio-src/fileio-03.cpp)

When you compile and run this program one of the following two will happen:

- if numbers.txt file doesn't exist, it will be created.
- if numbers.txt already exists, it will be __overwritten__.

The contents of this file will be

~~~txt
3.14159
8321
~~~

#### Problem

The above code __overwrites__ the file everytime it opens it for writing.  We can solve this issue by telling the system to open file in the append mode.  Replace

~~~cpp
ofstream f("numbers.txt");
~~~

with

~~~cpp
ofstream f("numbers.txt", ios::app);
~~~

`ios::app` flag sets up ofstream for appending.  

### Buffered Output

Output in C++ may be buffered. This means that anything that is output to a file stream may __not be written to disk immediately__.  Instead several writes may be group together to improve performance (disk access is painfully slow).  Typically buffered writes is not an issue; however, it can lead to problems in unique circumstances.  For example, if a program crashes.  The contents may not yet be written to the file and all changes may be lost.  It is possible to force a write by _flushing_.  Use `flush()` to force a write to the disk. 

Note that closing a file also _flushes_ a buffer, forcing a write to the disk of course.

Interestingly, `std::endl` which is often used in place of `\n` also forces a flush.  Relying upon `std::endl` instead of `\n` to indicate a newline, for example, can adversaly effect the performance.  Interesting, eh!

~~~cpp
f << "CSCI 1061U\n" << "Programming workshop 2\n";
f.flush();  // forces a save to the file
~~~

Alternately, 

~~~cpp
f << "CSCI 1061U\n" << "Programming workshop 2" << endl;
~~~

__Note:__ In practice, it is preferrable to use `flush()`.  This gives a clear signal that you intend to force a write-to-the-file.

### File modes

File stream constructors take an optional second parameter that allows you to specify information about how the file should be opened. This parameter is called mode, and the valid flags that it accepts live in the `ios` class.

ios file mode | Meaning
--------------|--------
app	| Opens the file in append mode
ate	| Seeks to the end of the file before reading/writing
binary | Opens the file in binary mode (instead of text mode)
in | Opens the file in read mode (default for ifstream)
nocreate | Opens the file only if it already exists
noreplace | Opens the file only if it does not already exist
out | Opens the file in write mode (default for ofstream)
trunc | Erases the file if it already exists

It is possible to specify multiple flags by bitwise ORing them together (using the `|` operator). 

### Binary files

`ios:binary` mode flag can be used to open a file for read/write in binary mode.    

Insertion `<<` and extraction `>>` operators are not meant to be used for binary mode files.  

To understand the difference between the two modes, consider the following example.  Say you want to write 3.14159 to a file.  In text mode, this can be accomplished as `f << 3.14159`.  The `<<` operator will write '3', '.', '1','4','5','9' to the file, which will take 7 bytes.  In binary mode, however, it will only take 32 bits (or 4 bytes), since it will be written as a double.

You'll use `read` and `write` methods to read/write from binary files.

~~~cpp
double pi = 3.14159;
ofstream f("pi.dat", ios::binary);
f.write(&pi, sizeof(double));
~~~

and

~~~cpp
double d;
ifstream f("pi.dat", ios::binary);
f.read(&d, sizeof(double));
~~~

If there is a read error `gcount()` can be used to see how many bytes are actually read.

[Source code](fileio-src/fileio-04.cpp) showing storing and loading binary values to a file.

### Random Access 

It is possible to set the location in the file where you want to perform the next read or write.

1. Move read location forward n bytes from the beginning: `f.seekg( n );`
2. Move read location forward n bytes from the current location: `f.seekg( n, ios::cur );`
3. Move read location back n bytes from the current location: `f.seekg( n, ios::end );`
4. Find the current read location `f.tellg();`
5. `seekp()` and `tellp()` can be used to move the write locations.

# Exercises 

1. Write a program for storing and loading 3D vectors to a file.
2. Write a program for storing and loading lastname, firstname to a file.



