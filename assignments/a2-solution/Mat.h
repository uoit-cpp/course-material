#include <iostream>
#include <assert.h>

using namespace std;

class Mat {
  protected:
  double* _data;
  int _nr, _nc;

  public:
  Mat();
  Mat(int nr, int nc);
  Mat(const Mat& m);
  ~Mat();

  inline const int& nrows() const { return _nr; }
  inline const int& ncols() const { return _nc; }

  void set(const double& d);

  const Mat& ones();
  const Mat& zeros();
  const Mat& rand();

  double* operator[](int i);
  const double* operator[](int i) const;
  
  const Mat& operator=(const Mat& m);

  // matrix-matrix addition
  const Mat& operator+=(const Mat& m);  
  friend Mat operator+(const Mat& a, const Mat& b);

  // matrix-matrix subtraction
  const Mat& operator-=(const Mat& m);  
  friend Mat operator-(const Mat& a, const Mat& b);

  // matrix-matrix multiplication
  friend Mat operator*(const Mat& a, const Mat& b);

  // matrix-scalar addition
  const Mat& operator+=(const double& d);
  friend Mat operator+(const Mat& m, const double& d);
  friend Mat operator+(const double& d, const Mat& m);
  
  // matrix-scalar subtraction
  const Mat& operator-=(const double& d);
  friend Mat operator-(const Mat& m, const double& d);
  friend Mat operator-(const double& d, const Mat& m);

  // matrix-scalar multiplication
  const Mat& operator*=(const double& d);
  friend Mat operator*(const Mat& m, const double& d);
  friend Mat operator*(const double& d, const Mat& m);

  // matrix-scalar division
  const Mat& operator/=(const double& d);
  friend Mat operator/(const Mat& m, const double& d);
  friend Mat operator/(const double& d, const Mat& m);

  
  // iostream
  friend ostream& operator<<(ostream& s, const Mat& m);
  friend istream& operator>>(istream& s, Mat& m);  
};
