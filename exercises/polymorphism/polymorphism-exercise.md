# CSCI 1061U - Programming Workshop 2

## Class exercise - Polymorphism

**This exercise is due before the end of the lecture.**

**Please submit on Blackboard.**

### Goal

Consider the following code.  You are asked to complete the Triangle and the Rectangle class, such that the following code works as expected.

~~~cpp
// main.cpp

#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    Polygon (int a, int b) : width(a), height(b) {}
    virtual int area (void) =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

// TO DO
class Rectangle

// TO DO
class Triangle

int main () {
  Polygon * ppoly1 = new Rectangle (4,5);
  Polygon * ppoly2 = new Triangle (4,5);
  ppoly1->printarea();
  ppoly2->printarea();
  delete ppoly1;
  delete ppoly2;
  return 0;
}
~~~

#### Computing areas

Area of a rectangle is $w \times h$, where $w$ and $h$ refer to the width and the height of the rectangle, respectively.

Area of a triangle is $\frac{w \times h}{2}$, where $w$ and $h$ refer to the width and the height of the triangle, respectively.