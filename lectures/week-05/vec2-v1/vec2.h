#include <iostream>

class vec2 {
public:
  double x;
  double y;

public:
  vec2();
  vec2(double c);
  vec2(double x, double y);
  vec2(const vec2& o);
  ~vec2();
  
public:
  double length();

  // Assignment operator
  vec2& operator=(const vec2& o); 
};
