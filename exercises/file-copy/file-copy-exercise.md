# CSCI 1061 - Programming Workshop 2

## Class Exercise

You are asked to write file copy program in C++.  The program will take two arguments.  The first argument will be the name of the file to _copy from_; where as, the second argument will be the name of the file to _copy to_.  Your program is a simplified version of the `cp` command in linux.

### Example Usage

The following command will copy text file `in.txt` to `out.txt`.

~~~bash
$ ./file-copy in.txt out.txt 
~~~  

Similarly, the following command will copy image `in.jpg` to `out.jpg`

~~~bash
$ ./file-copy in.jpg out.jpg 
~~~  

And so on.  

### Caveats

Please adhere to the following conditions:

- Your program `file-copy` should be able to handle file of any type and any size.
- You may assume that memory available to your program is less than the size of the files that need copying.  This suggests that you cannot load the entire file in the memory.  __Assume that the largest buffer size that you are allowed to allocate is 1000 bytes.__
- You are may use functions available in `fstream` and `iostream`
- You may __not__ any other advanced functions.  E.g., you may not invoke the system `cp` command to do the task for you.

You can use the following `main.cpp` skeleton to write your program.

~~~cpp
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	// argv[0] is the name of the program
	// argv[1] is the name of the input file
	// argv[2] is the name of the output file
	// max character buffer size allowed is 1000

	// TODO

	return 0;
}
~~~

### Submission

Please submit it via Blackboard.  The exercise is due before the end of this lecture.
