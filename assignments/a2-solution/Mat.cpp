#include "Mat.h"
#include <cassert>
#include <time.h>

Mat::Mat() : _nr(0), _nc(0), _data(0)
{}

Mat::Mat(int nr, int nc) : _nr(nr), _nc(nc)
{
  _data = new double[_nr * _nc];
}

Mat::Mat(const Mat& m)
{
  _nr = m._nr;
  _nc = m._nc;
  _data = new double[_nr * _nc];
  memcpy(_data, m._data, sizeof(double)*_nr*_nc);
}

Mat::~Mat()
{
  if (_data) delete [] _data;
}

double* Mat::operator[](int i)
{
  return _data + i*_nc;
}

const double* Mat::operator[](int i) const
{
  return _data + i*_nc;
}

const Mat& Mat::operator=(const Mat& m)
{
  assert(_nr == m._nr);
  assert(_nc == m._nc);
  memcpy(_data, m._data, sizeof(double)*_nr*_nc);
  return *this;
}

ostream& operator<<(ostream& s, const Mat& m)
{
  s << m._nr << ' ' << m._nc << endl;

  for (int i=0; i<m._nr; ++i) {
    for (int j=0; j<m._nc; ++j) {
      s << m[i][j] << ' ';
    }
    s << endl;
  }
return s;
}

istream& operator>>(istream& s, Mat& m)
{
  int nr, nc;
  s >> nr;
  s >> nc;

  if (nr != m._nr || nc != m._nc) {
     m._nr = nr;
     m._nc = nc;
     if (m._data) delete [] m._data;
     m._data = new double[m._nr*m._nc];
  }

  for (int i=0; i<m._nr; ++i) {
    for (int j=0; j<m._nc; ++j) {
      s >> m[i][j];
    }
  }

  return s;
}

void Mat::set(const double& d)
{
  for (int i=0; i<_nr; ++i) {
    for (int j=0; j<_nc; ++j) {
      (*this)[i][j] = d;
    }
  }
}

// matrix-matrix addition
const Mat& Mat::operator+=(const Mat& m)
{
  assert(_nr == m._nr);
  assert(_nc == m._nc);

  for (int i=0; i<_nr; ++i) {
    for (int j=0; j<_nc; ++j) {
      (*this)[i][j] += m[i][j];
      //_data[i*_nc + j] += m._data[i*_nc + j];
    }
  }
  
  return *this;
}

Mat operator+(const Mat& a, const Mat& b)
{
  Mat result(a);
  result += b;
  return result;
}

// matrix-matrix subtraction
const Mat& Mat::operator-=(const Mat& m)
{
  assert(_nr == m._nr);
  assert(_nc == m._nc);

  for (int i=0; i<_nr; ++i) {
    for (int j=0; j<_nc; ++j) {
      (*this)[i][j] -= m[i][j];
    }
  }
  
  return *this;
}

Mat operator-(const Mat& a, const Mat& b)
{
  Mat result(a);
  result -= b;
  return result;
}

// matrix-matrix multiplication
Mat operator*(const Mat& a, const Mat& b)
{
  assert(a.ncols() == b.nrows());

  Mat result(a.nrows(), b.ncols());

  for (int i=0; i<a.nrows(); ++i) {
      for (int j=0; j<b.ncols(); ++j) {
        result[i][j] = 0;
        for (int k=0; k<a.ncols(); ++k) {
          result[i][j] += (a[i][k] * b[k][j]);
        }
      }
  }
  
  return result;  
}

// matrix-scalar addition
const Mat& Mat::operator+=(const double& d)
{
  for (int i=0; i<_nr; ++i) {
    for (int j=0; j<_nc; ++j) {
      (*this)[i][j] += d;
    }
  }
  return *this;
}

Mat operator+(const Mat& m, const double& d)
{
  Mat result(m);
  result += d;
  return result;
}

Mat operator+(const double& d, const Mat& m)
{
  Mat result(m);
  result += d;
  return result;
}

// matrix-scalar subtraction
const Mat& Mat::operator-=(const double& d)
{
  for (int i=0; i<_nr; ++i) {
    for (int j=0; j<_nc; ++j) {
      (*this)[i][j] -= d;
    }
  }
  return *this;
}

Mat operator-(const Mat& m, const double& d)
{
  Mat result(m);
  result += d;
  return result;
}

Mat operator-(const double& d, const Mat& m)
{
  Mat result(m);
  result += d;
  return result;
}

// matrix-scalar multiplication
const Mat& Mat::operator*=(const double& d)
{
  for (int i=0; i<_nr; ++i) {
    for (int j=0; j<_nc; ++j) {
      (*this)[i][j] *= d;
    }
  }
  return *this;  
}

Mat operator*(const Mat& m, const double& d)
{
  Mat result(m);
  result *= d;
  return result;
}

Mat operator*(const double& d, const Mat& m)
{
  Mat result(m);
  result *= d;
  return result;
}

// matrix-scalar multiplication
const Mat& Mat::operator/=(const double& d)
{
  for (int i=0; i<_nr; ++i) {
    for (int j=0; j<_nc; ++j) {
      (*this)[i][j] /= d;
    }
  }
  return *this;  
}

Mat operator/(const Mat& m, const double& d)
{
  Mat result(m);
  result /= d;
  return result;
}

Mat operator/(const double& d, const Mat& m)
{
  Mat result(m);
  result /= d;
  return result;
}

const Mat& Mat::ones()
{
  set(1.0);
  return *this;
}

const Mat& Mat::zeros()
{
  set(0.0);
  return *this;
}

double cast()
{
  return (double) rand()/RAND_MAX;
}

const Mat& Mat::rand()
{
  for (int i=0; i<_nr; ++i) {
    for (int j=0; j<_nc; ++j) {
      (*this)[i][j] = cast();
    }
  }
  return *this;
}
