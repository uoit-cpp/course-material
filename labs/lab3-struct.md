# CSCI 1061U - Programming Workshop 2

## Lab 3 - C++ Structs

**Due back on Saturday, February 4 before 11:59 pm.**

### Introduction

The goal of this exercise is to save information employee information for XYZ Corp. in a file.  See the various aspects of this program below.

#### Step 1

Create a struct that can store employee id, wages and first and last names.  To keep things simple, we assume that employee names are stored in char[], and we only store the first 16 characters of the name.  See below.

~~~cpp
struct Employee {
	char fname[16];
	char lname[16];
	int id;
	double wages
};
~~~

#### Step 2

Now write a program that adds an employee to the `employees.dat` file.

~~~bash
$ add-employee
Enter firstname: Captain
Enter lastname: America
Enter id: 2
Enter wage: 5.00
~~~

This program will append this record to the `employees.dat`.

#### Step 3

Now write a program that prints the info of the employee with the passed employee id.

~~~bash
$ prn-employee 2
America, Captain
	id = 2
	wage = $5.00
~~~

### Hints

- Use binary file read/write to store employee structures effeciently
- You can find the size of `struct Employee` using `sizeof(Employee)`.
- Structs can be written out to a file using `write()` function.
- `write()` function takes address to a memory and the number of bytes to be written to the file.
- It may be easier to get first and last name using `std::string` as follows:

~~~cpp
string fname;
cout << "Enter first name: ";
cin >> fname;
~~~

- You can easily convert a `char[]` to a string as follows

~~~cpp
char c_array[10];
string str(c_array,0,10); // starting position, 0, count 10
~~~

- It is possble to get a `const char[]` from an `std::string` using `c_str()` function.

#### Submission

Please submit `prn-employee.cpp` and `add-employee.cpp` files via Blackboard.