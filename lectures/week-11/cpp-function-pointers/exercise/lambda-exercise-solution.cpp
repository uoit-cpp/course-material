#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::ostream;

class Vec
{
  protected:
  double _x, _y, _z;

  public:
  Vec() {
    _x = (double) rand() / RAND_MAX;
    _y = (double) rand() / RAND_MAX;
    _z = (double) rand() / RAND_MAX;
  }

  double x() const { return _x; }
  double y() const { return _y; }
  double z() const { return _z; }
  
  friend ostream& operator<<(ostream& os, const Vec& v)
  {
    cout << "(" << v._x << "," << v._y << "," << v._z << ")";
    return os;
  }

  inline double l2() {
    return _x*_x + _y*_y + _z*_z;
  }
};

bool smallerX(Vec i, Vec j)
{
  cout << i.x() << " " << i.y() << endl;

  return i.x() < j.x();
}

bool smallerY(Vec i, Vec j)
{
 return i.y() < j.y();
}


template<typename T, typename Func>
T find_smallest(T a[], int n, Func smaller)
{
  T smallest = a[0];
  for (int i=1; i<n; ++i) {
    if (smaller(a[i], smallest)) smallest = a[i];
  }
  return smallest;
}

int main()
{
  srand(0);
  Vec a[6];

  for (int i=0; i<6; ++i) cout << a[i] << endl;
  
  Vec smallest = find_smallest<Vec>(a, 6, smallerX);
  cout << "smallest = " << smallest << endl;

  smallest = find_smallest<Vec>(a, 6, smallerY);
  cout << "smallest = " << smallest << endl;
  
  return 0;
}
