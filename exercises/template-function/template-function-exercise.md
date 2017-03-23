# CSCI 1061U - Programming Workshop 2

## Class exercise - Template Functions

**This exercise is due before the end of the lecture.**

**Please submit on Blackboard.**

Consider the following code

~~~cpp
#include <iostream>
using namespace std;

int min(int a, int b)
{
  if (a < b) return a;
  return b;
}

int main()
{
  int x, y;

  cout << "Enter first number: ";
  cin >> x;

  cout << "Enter second number: ";
  cin >> y;

  int smaller;
  smaller = min(x, y);
  
  cout << "Smaller number is " << smaller << endl;

  return 0;
}
~~~

**Goal**

This function implements a `min` function.  You are asked to _templatize_ it.  This will allow us to use this `min` function to compare values of types other than integer.

### Why template function

You can see the problem with the current min function if you change 

~~~cpp
int x, y;
~~~

to 

~~~cpp
float x, y;
~~~