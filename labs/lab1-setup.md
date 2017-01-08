# CSCI 1061U - Programming Workshop 2
## Lab 1 - Setting up C++ Development System


### Objectives ###

The goal is this lab is to set our machine for C++ development.  We
will also install CMake, a cross-platform build system and Boost C++
libraries.  This lab assumes that you have Linux (Ubuntu) installed on
your system.  If you are running a windows box, you can use
[VirtualBox](https://www.virtualbox.org) to set up an Ubuntu virtual machine.

### Install C++ compile systems

~~~bash
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential
~~~

Now check gcc version

~~~bash
$ gcc –v
~~~

Also, see if make compile tool is properly installed

~~~bash
$ make –v
~~~

#### Install Boost Libraries

~~~bash
$ sudo apt-get install libboost-all-dev
~~~

#### Install CMake build system

~~~bash
$ sudo apt-get install cmake
~~~

Check cmake install

~~~bash
$ cmake
~~~

#### Hello World Application

Create a file `helloworld.cpp`

~~~cpp
#include <iostream>
using namespace std::cout;
using namespace std::endl;

int main(int argc, char** argv)
{
    cout << "Hello world" << endl;
    return 0;
}
~~~

Now lets compile and run it.

~~~bash
$ g++ helloworld.cpp -o helloworld
$ ./helloworld
Hello World
$
~~~

### Creating a static library

Create a file `average.cpp`

~~~cpp
float average3(float a, float b, float c)
{
	return (a + b + c) / 3.0;
}
~~~

Also create a file `average.h`

~~~cpp
float average3(float a, float b, float c);
~~~

Now create a static library called `average.a`

~~~bash
$ g++ -c average.cpp
$ ar rvs average.a average.o
~~~

Ok, so at this point you have a library called `average.a`, which can be statically linked against other C++ programs.  The C++ programs will be able to use the functionality available in the `average.a` file.  Currently, it only has a single function that computes the average of 3 numbers.

#### Create a program that uses 'average.a' to compute the average of 3 numbers

Create a file `lab1.cpp`

~~~cpp
#include "average.h"
#include <iostream>
using namespace std;

int main()
{
        float a, b, c;
        cout << "Enter a: "; cin >> a;
        cout << "Enter b: "; cin >> b;
        cout << "Enter c: "; cin >> c;

        cout << "Average of a, b and c is " << average3(a, b, c) << endl;
        return 0;
}
~~~

Compile and link it with the library.

~~~bash
$ g++ -c lab1.cpp
$ g++ lab1.o average.a -o lab1
~~~

*Note that when writing lab1.cpp, we didn't use average.cpp file.*  Vendors distribute their software via libraries.  This way they don't need to distribute the source files.

### Complete the following tasks

Complete the following tasks:

- Create a method `void average(const float* arr, int arr_size, float& ave, float& sd);` that computes average and standard deviation of the values passed in the array.  Place this method definition and declaration in average.{h,cpp} files.
- Add the following code in `lab1.cpp` file and ensure that it works as expected.  *Play with different values and lengths of the array.*

~~~cpp
	float arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float ave, sd;
	average(arr, 5, ave, sd);
	cout << "Average of arr is " << ave << endl;
	cout << "SD of arr is " << sd << endl;
~~~

###Submission
Please submit `average.cpp`, `average.h` and `lab1.cpp` files via Blackboard. 