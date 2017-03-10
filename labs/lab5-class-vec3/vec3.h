#ifndef __vec3_h__
#define __vec3_h__

#include <iostream>
using namespace std;

class vec3
{
private:
  float m[3];

public:

  // constructors
  vec3();
  vec3(const vec3& v);
  vec3(float x, float y, float z);

  // indexing
  float& operator[](int i);
  const float& operator[](int i) const;

  // assignment
  const vec3& operator=(const vec3& v);

  // multiplication with a scalar
  void operator*=(float s);  
  friend vec3 operator*(const vec3& v, float s);

  // addition
  void operator+=(const vec3& v);
  friend vec3 operator+(const vec3& v1, const vec3& v2);

  // subtraction
  void operator-=(const vec3& v);
  friend vec3 operator-(const vec3& v1, const vec3& v2);

  // negation
  vec3 operator-();
  
  // dot product
  friend float operator*(const vec3& v1, const vec3& v2);

  // cross product
  friend vec3 operator^(const vec3& v1, const vec3& v2);

  // length
  float length();
  
  // io
  friend ostream& operator<<(ostream& o, const vec3& v);
  friend istream& operator>>(istream& o, vec3& v);
};

#endif
