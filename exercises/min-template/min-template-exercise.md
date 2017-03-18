# CSCI 1061U - Programming Workshop 2

## Class Exercise - Template Functions

**This needs to be submitted before the end of the lecture.**

**Please submit via Blackboard**

### Templatize min function

Consider the code below.  It contains a min function.  The min function can handle arguments of type int only.
You are asked to templatize it.  So it will work for types other than int.

~~~cpp
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

int min(int a, int b)
{
  if (a < b) return a;
  return b;
}

int main()
{
  cout << "Not using templates." << endl;

  int x = 1, y = 2;
  cout << min(x, y) << endl;
  
  return 0;
}
~~~

Once you have successfully templatized the min function, the following should work

~~~cpp
int main()
{
  cout << "Not using templates." << endl;

  int x = 1, y = 2;
  cout << min<int>(x, y) << endl;

  float a = 23., b = 232.;
  cout << min<float>(a, b) << endl;

  return 0;
}
~~~
