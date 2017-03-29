# C++ Exception Handling

## CSCI 1061U - Programming Workshop 2

**faisal.qureshi@uoit.ca**

## Exception Handling

- A mechanism to handle “unexpected” situations
	- File disappears in the middle of reading
	- A network connection drops
	- Division by zero occurs

## Dealing with unexpected situation

- Use error checking (if statements) to see if execution of a particular line of code will result in an error
	- Do not execute the line of code that will give rise to the error
	- Only feasible in very simple situations	

### Case 1: Do nothing and hope for the best

~~~cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  double d, t;

  cout << "Enter distance: ";
  cin >> d;
  cout << "Enter time: ";
  cin >> t;

  cout << "Velocity is: " << d/t << endl; 

  return 0;
}
~~~

Output 

~~~bash
./velocity-no-error-checking
Enter distance: 2
Enter time: 0
Velocity is: inf
~~~

### Case 2: Check for possible errors

Avoid executing statements that may lead to those errors

~~~cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  double d, t;

  cout << "Enter distance: ";
  cin >> d;
  cout << "Enter time: ";
  cin >> t;

  if (t <= 0) {
    cout << "Cannot compute velocity" << endl;
  }
  else {
    cout << "Velocity is: " << d/t << endl;
  }

  return 0;
}
~~~

Output

~~~bash
./velocity-error-checking
Enter distance: 2
Enter time: 0
Cannot compute velocity
~~~

### Case 3: Use exception handling

~~~cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  double d, t;

  try {  
    cout << "Enter distance: ";
    cin >> d;
    cout << "Enter time: ";
    cin >> t;

    if (t <= 0) throw d;

    cout << "Velocity is: " << d/t << endl; 
  }
  catch (double e)
  {
    cout << "Exception raised." << endl;
  }
  cout << "Continue ..." << endl;

  return 0;
}
~~~

Output

~~~bash
./velocity-exception-handling
Enter distance: 3
Enter time: 0
Exception raised.
Continue ...
~~~

## Anatomy of Exception Handling

Separates normal execution from what should be done in exceptional circumstances, keeping logic simple and design clean

### try-block

Normal execution

~~~cpp
try {  
  cout << "Enter distance: ";
  cin >> d;
  cout << "Enter time: ";
  cin >> t;

  if (t <= 0) throw d;

  cout << "Velocity is: " << d/t << endl; 
}
~~~

### catch-block

Code that needs to be executed in exceptional circumstances

~~~cpp
catch (double e)
{
  cout << "Exception raised." << endl;
}
~~~

### throw statment

~~~cpp
if (t <= 0) throw d;
~~~

## Exception handling

- Flow of control goes from try-block to catch-block when exception is thrown
- Each thrown exception must be handled in catch-block

## Throwing an exception

- Keyword `throw` followed by exception type
- Throw acts like a “function call”

~~~cpp
try {  
  cout << "Enter distance: ";
  cin >> d;
  cout << "Enter time: ";
  cin >> t;

  if (t <= 0) throw d;

  cout << "Velocity is: " << d/t << endl; 
}
~~~

## catch-block

- catch-block looks like a function definition
- catch-block is **not a function**, but it has similar behavior

~~~cpp
catch (double e)
{
  cout << "Exception raised." << endl;
}
~~~

- Each catch-block can have at most one parameter
	- e is catch-block parameter
	- e specifies what kind of of thrown value this catch block should catch
	- The value of e is available within catch-block
	- The parameter name doesn't have to be "e".
	- It is also okay to not use e at all as seen below

~~~cpp
catch (double)
{
  cout << "Exception raised." << endl;
}
~~~	

## Exception classes

- `throw` statement can throw value of any type, even user-defined classes
- Class constructor is called to _construct_ the class object that is subsequently thrown
	- It is possible to store data and other relevant info within the class object 

In the following code, exception of type `BadTime` is thrown in case the user enters an invalid value for time.

~~~cpp
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class BadTime
{
  private:
  double t;
  string n;

  public:
  BadTime(double time) : t(time) {
    n = "BadTime";
  }

  string getName() const { return n; }
  double getValue() const { return t; }
};

int main()
{
  double d, t;

  try {  
    cout << "Enter distance: ";
    cin >> d;
    cout << "Enter time: ";
    cin >> t;

    if (t <= 0) throw BadTime(t);

    cout << "Velocity is: " << d/t << endl; 
  }
  catch (BadTime bd)
  {
    cout << "Exception " << bd.getName()
         << " called with value " << bd.getValue()
         << endl;
  }
  
  cout << "Continue doing what you were doing." << endl;
  
  return 0;
}
~~~

Output

~~~bash
$./velocity-exception-classes
Enter distance: 12
Enter time: 2
Velocity is: 6
Continue doing what you were doing.
$./velocity-exception-classes
Enter distance: 3
Enter time: 0
Exception BadTime called with value 0
Continue doing what you were doing.
$./velocity-exception-classes
Enter distance: 4
Enter time: -1
Exception BadTime called with value -1
Continue doing what you were doing.
~~~

## Multiple throws in a try-block

- try-block typically throws any number of exception values, of different types
- The try-block ends once the first exception is thrown

~~~cpp
try {

  throw Exception1();

  throw Exception2();

  throw ExceptionN();  
}
~~~

- Each catch-block only catches “one type” of exception
- Place many catch-blocks after each try-block to catch “all possible” exceptions that may be thrown by the try-block

~~~cpp
catch(Exception1 e) {
  // body
}
catch(Exception2 e) {
  // body
}

catch(ExceptionN e) {
  // body
}
catch(...) {
  // body
}
~~~

- Order of catch-blocks important
- Catch-blocks tried “in-order” after try-block
	- First match handles it
- You can use the catch-all statement as seen below to catch any _unhandled_ exceptions
- Always place the catch-all (`catch(...)`) statement at the end of catch statments, otherwise, any catch statement that comes after a catch-all statement will never get a chance to "catch a thrown exception"

Syntax for `catch-all block` is

~~~cpp
catch(...) {
}
~~~

**Example code** that shows multiple exceptions being thrown and caught

~~~cpp
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class BadTime
{
  private:
  double t;
  string n;

  public:
  BadTime(double time) : t(time) {
    n = "BadTime";
  }

  string getName() const { return n; }
  double getValue() const { return t; }
};

class ZeroDistance
{};

class NegativeDistance
{};

int main()
{
  double d, t;

  try {  
    cout << "Enter distance: ";
    cin >> d;
    if (d == 0) throw ZeroDistance();
    if (d < 0) throw NegativeDistance();
    
    cout << "Enter time: ";
    cin >> t;
    if (t <= 0) throw BadTime(t);
    

    cout << "Velocity is: " << d/t << endl; 
  }
  catch (BadTime bt)
  {
    // We explictly name the catch paramter bd, since we plan to use
    // it below
    
    cout << "Exception " << bt.getName()
         << " called with value " << bt.getValue()
         << endl;
  }
  catch (ZeroDistance)
  {
    // Note we do not mention (name) catch parameter.
    // Since we don't plan to use it here.

    cout << "Exception: ZeroDistance." << endl;
  }
  catch (...)
  {
    // A catch-all block
    //
    // Notice that the try-block is throwning a NegativeDistance
    // exception that we don't explicitly catch.  We
    // use this catch-all block to catch any unhandled
    // exceptions that may be thrown by the try block.

    cout << "Exception: an unhandled exception." << endl;
  }

  cout << "Program safely continues, once the exception is handeled." << endl;

  return 0;
}
~~~

Output 

~~~bash
$./velocity-multiple-exceptions
Enter distance: 1
Enter time: .2
Velocity is: 5
Program safely continues, once the exception is handeled.
$./velocity-multiple-exceptions
Enter distance: -2
Exception: an unhandled exception.
Program safely continues, once the exception is handeled.
$./velocity-multiple-exceptions
Enter distance: 34
Enter time: 0
Exception BadTime called with value 0
Program safely continues, once the exception is handeled.
$./velocity-multiple-exceptions
Enter distance: 0
Exception: ZeroDistance.
Program safely continues, once the exception is handeled.
~~~

## Trivial Exception Classes

- No member variables- No member functions (except default constructor)
- Nothing but it’s name, which is enough
- Might be "nothing to do" with exception value
- Used simply to "get to" catch block
- Can omit catch block parameter

E.g.,

~~~cpp
class ZeroDistance
{};
~~~

## Throwing Exception in a function

It is possible that an exception is thrown in a function, but it is caught in the _calling function_ try-catch-block.  The try-block seen below, for example, does not contain a throw statement.  Here, function `safeDivide` throws the exception `DivideByZero`, but the exception is handled in the try-catch-block of the calling function.  

~~~cpp
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

class DivideByZero
{};

double safeDivide(int top, int bottom) throw (DivideByZero);

int main( )
{
    int numerator;
    int denominator;
    double quotient;
    cout << "Enter numerator:\n"; 
    cin >> numerator;
    cout << "Enter denominator:\n";
    cin >> denominator;

    try
    {
       quotient = safeDivide(numerator, denominator);
    }
    catch(DivideByZero)
    {
         cout << "Error: Division by zero!\n"
              << "Program aborting.\n";
         exit(0);
    }

    cout << numerator << "/" << denominator 
         << " = " << quotient << endl;

    cout << "End of program.\n";
    return 0;
}

double safeDivide(int top, int bottom) throw (DivideByZero)
{
    if (bottom == 0)
        throw DivideByZero( );

    return top/static_cast<double>(bottom);
}
~~~

This scenario is actually rather common.  It makes sense to catch exception in the _calling_ function, since this allows the calling function to react in different ways to the thrown exception.  In one situation the calling function may choose to abort the program; where as, in some other situation the calling function may choose to continue.

Consider the two situations below

**Situation 1**

~~~cpp
void allocate_memory() throw OutOfMemory {}

try {
  allocate_memory();
}
catch(OutOfMemory) {
  // abort
}
~~~

**Situation 2**

~~~cpp
void allocate_memory() throw OutOfMemory {}

try {
  allocate_memory();
}
catch(OutOfMemory) {
  // ask for more memory
}
~~~

In the first situation the calling function chose to abort the program; where as, in the second situation the calling function chose to ask for more memory. 

## Specifying thrown exceptions

Functions, e.g. `safeDivide` above, that throw exceptions, but don't catch them should warn users that it will throw an exception.  Specifically, such functions should list _all_ exceptions that it can throw.  This is list is often called "exception list" or "throw list".

E.g.,

~~~cppdouble safeDivide(int top, int bottom) throw (DividebyZero);
~~~

or (if more than one)

~~~cppdouble safeDivide(int top, int bottom) throw (DividebyZero, SomeOtherException);
~~~

The "exception list" or "throw list" should appear in both function's declaration and definition.  
b
If a function throws an exception that was not in its "throw list", built-in function `unexpected()` is automatically called.  The default behavior of `unpected()` function is to terminate the program.  Note that the fact that a function throws an exception that is not in its throw list does not create a compile-time or run-time error.  Btw. `unexpected()` is also called if no try-catch block is found.

### Case 1

Exception types `DividebyZero` or `OtherException` treated normally.  All others invoke `unexpected()`.

~~~cpp
void someFunction() throw(DividebyZero, OtherException);
~~~

### Case 2

Empty exception list, all exceptions invoke `unexpected()`

~~~cppvoid someFunction() throw ();~~~### Case 3All exceptions of all types treated normally~~~cppvoid someFunction();~~~

## Derived classes

Polymorphism plays an important role in exceptions.  Say class B is derived from class A.  If the catch-block handles exception of type class A (i.e., class A is in exception specification) then it will also catch exception of class B is thrown.  

E.g., 

~~~cpp
class A {};
class B : public A {};

try {
	throw B;
}
catch (A)
{
	// This block will catch if B is thrown
	// in the try block.
}
~~~

See the code below for this behavior in action.

~~~cpp
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class BadTime
{
  private:
  double t;
  string n;

  public:
  BadTime(double time) : t(time) {
    n = "BadTime";
  }

  string getName() const { return n; }
  double getValue() const { return t; }
};

class InvalidDistance
{
  protected:
  string name;

  public:
  InvalidDistance() {
    name = "InvalidDistance";
  }

  string getName() const { return name; }
};

class ZeroDistance : public InvalidDistance
{
  public:
  ZeroDistance() : InvalidDistance()
  {
    name = name + " -> " + "ZeroDistance";
  }
};

class NegativeDistance : public InvalidDistance
{
  public:
  NegativeDistance() : InvalidDistance()
  {
    name = name + " -> " + "NegativeDistance";
  }
};

int main()
{
  double d, t;

  try {  
    cout << "Enter distance: ";
    cin >> d;
    if (d == 0) throw ZeroDistance();
    if (d < 0) throw NegativeDistance();
    
    cout << "Enter time: ";
    cin >> t;
    if (t <= 0) throw BadTime(t);
    

    cout << "Velocity is: " << d/t << endl; 
  }
  catch (BadTime bt)
  {
    // We explictly name the catch paramter bd, since we plan to use
    // it below
    
    cout << "Exception " << bt.getName()
         << " called with value " << bt.getValue()
         << endl;
  }
  catch (InvalidDistance id)
  {
    // Notice that this catch-block catches
    // InvalidDistance.

    cout << "Exception " << id.getName()
         << " caught." << endl;
  }
  catch (...)
  {
    // A catch-all block
    //
    // Notice that the try-block is throwning a NegativeDistance
    // exception that we don't explicitly catch.  We
    // use this catch-all block to catch any unhandled
    // exceptions that may be thrown by the try block.

    cout << "Exception: an unhandled exception." << endl;
  }

  cout << "Program safely continues, once the exception is handeled." << endl;
  
  return 0;
}
~~~

Output

~~~bash
$./velocity-exceptions-polymorphism
Enter distance: 2
Enter time: 1
Velocity is: 2
Program safely continues, once the exception is handeled.
$./velocity-exceptions-polymorphism
Enter distance: -2
Exception InvalidDistance -> NegativeDistance caught.
Program safely continues, once the exception is handeled.
$./velocity-exceptions-polymorphism
Enter distance: 0
Exception InvalidDistance -> ZeroDistance caught.
Program safely continues, once the exception is handeled.
~~~

Note that `ZeroDistance` and `NegativeDistance` is not in exception list, but these are caught by `catch(InvalidDistance id)` catch-block, since both `ZeroDistance` and `NegativeDistance` are derived from class `InvalidDistance`.

## `unexpected()`

This function is called whenever an unhandled exception is thrown.  The default behavior is to `terminate` the program.  It is possible to redifine this function by using `set_unexpected`.  I suggest checking out the compiler documentation to the interested reader.

## Rules of Thumb

- Exception throw and catch typically reside in different functions, and even in different files
- The function that throws the exception should provide a throw list, which lists the exceptions that the function throws
- A program should not have _uncaught exceptions_.  If an exception is not caught function `terminate()` is called, terminating the program
- Recall that `unpected()` is also called if an exception that is not in the throw list is thrown.  This will terminate the program
- Exceptions should be used _sparingly_
	- Exceptions alter the flow of the program (recall the `goto` statement)
- It is best to use exceptions when all other design avenues have been exhausted

## Rethrowing an exception 

- It is legal to throw an exception in the catch-block.  In practice it is done very rarely.
- This behavior throws to a catch-block within the same chain.
- Use `rethrow;` to throw the same exception up
- Use `throw SomeNewException;` to throw a different exception to the subsequent catch-blocks

## Further reading

- [http://www.cplusplus.com/doc/tutorial/exceptions/](http://www.cplusplus.com/doc/tutorial/exceptions/}
- Absolution C++ 6 Ed.