#include "vec3.h"
#include <math.h>

// constructors
vec3::vec3()
{
  m[0] = m[1] = m[2] = 0.0;
}

vec3::vec3(const vec3& v)
{
  m[0] = v[0];
  m[1] = v[1];
  m[2] = v[2];
}

vec3::vec3(float x, float y, float z)
{
  m[0] = x;
  m[1] = y;
  m[2] = z;
}

// indexing
float& vec3::operator[](int i)
{
  return m[i];
}

const float& vec3::operator[](int i) const
{
  return m[i];
}

// assignment
const vec3& vec3::operator=(const vec3& v)
{
  m[0] = v[0];
  m[1] = v[1];
  m[2] = v[2];
  return *this;
}

// multiplication with a scalar
void vec3::operator*=(float s)
{
  m[0] *= s;
  m[1] *= s;
}

vec3 operator*(const vec3& v, float s)
{
  vec3 v1(v);
  v1 *= s;
  return v1;
}

// addition
void vec3::operator+=(const vec3& v)
{
  m[0] += v[0];
  m[1] += v[1];
  m[2] += v[2];
}


vec3 operator+(const vec3& v1, const vec3& v2)
{
  vec3 v(v1);
  v += v2;
  return v;
}

// subtraction
void vec3::operator-=(const vec3& v)
{
  m[0] -= v[0];
  m[1] -= v[1];
  m[2] -= v[2];
}


vec3 operator-(const vec3& v1, const vec3& v2)
{
  vec3 v(v1);
  v -= v2;
  return v;
}

// negation
vec3 vec3::operator-()
{
  return vec3(-m[0],-m[1],-m[2]);
}

// dot product

float operator*(const vec3& v1, const vec3& v2)
{
  float sum = 0.;
  for (int i=0; i<3; ++i) sum += (v1[i] * v2[i]);
  return sum;
}

// cross-product
vec3 operator^(const vec3& v1, const vec3& v2)
{
  return vec3(v1[1]*v2[2] - v2[1]*v1[2],
              - v1[0]*v2[2] + v2[0]*v1[2],
              v1[0]*v2[1] - v2[0]*v1[1]);
}

// length
float vec3::length()
{
  return sqrt(m[0]*m[0] + m[1]*m[1] + m[2]*m[2]);
}

// io 
ostream& operator<<(ostream& o, const vec3& v)
{
  o << v[0] << ' ' << v[1] << ' ' << v[2];
  return o;
}

istream& operator>>(istream& o, vec3& v)
{
  o >> v[0];
  o >> v[1];
  o >> v[2];
  return o;
}

