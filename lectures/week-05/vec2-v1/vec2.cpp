#include "vec2.h"
#include "math.h"

using namespace std;

vec2::vec2() : x(0.0), y(0.0)
{
//  cout << "vec2::vec2() called " << this << "." << endl;
}

vec2::vec2(double c)
{
  this->x = c;
  this->y = c;
}

vec2::vec2(double x, double y)
{
  this->x = x;
  this->y = y;
//  cout << length() << endl;
}

vec2::vec2(const vec2& o)
{
  x = o.x;
  y = o.y;
}

vec2::~vec2()
{
  cout << "Gone." << endl;
}

vec2& vec2::operator=(const vec2& o)
{
  x = o.x;
  y = o.y;
  return *this;
}

double vec2::length()
{
  return sqrt(x*x + y*y);
}
