# CSCI 1061U - Programming Workshop 2

## Class exercise - Template Functions

**This exercise is due before the end of the lecture.**

**Please submit on Blackboard.**

### Part 1

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

#### Why template function

You can see the problem with the current min function if you change 

~~~cpp
int x, y;
~~~

to 

~~~cpp
float x, y;
~~~

**Submit part 1 once complete**

### Part 2

_Only start this part once you have completed part 1._

Consider the class super_hero, which stores the name and the attack power of a super hero. 

~~~cpp
class SuperHero
{
  protected:
  string _name;
  float _power;

  public:
  SuperHero(const string& name, float power) : _name(name), _power(power)
  {}
};
~~~ 

How can we use the templated min function that you implemented in part 1 to decide which of the two superheros is weaker...  See below.

~~~cpp
...

SuperHero bat("Batman", 1.2);
SuperHero sup("Superman", 3.2);

SuperHero weaker = ... // use your min function here 
                       // to find the weaker of teh two
cout << weaker << " is weaker." << endl;

...
~~~

**Submit part 2 once complete**

_Add the solution to your cpp file and submit again._
