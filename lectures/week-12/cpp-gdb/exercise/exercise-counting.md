# Exercise - Counting Speed

**Due before the end of the lecture**

Instrument the code to determine which of the two counting methods shown below is faster?

~~~cpp
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

void count1(vector<int>& v, map<int,int>& c)
{
    set<int> uniqueDigits(v.begin(), v.end());
    for (auto num : uniqueDigits)
    {
      c[num] = count(v.begin(), v.end(), num);
    }
}

void count2(vector<int>& v, map<int,int>& c)
{
  for (auto i = v.begin(); i != v.end(); ++i)
  {
    map<int,int>::iterator j = c.find(*i);
    if (j != c.end()) {
      ++(j->second);
    }
    else {
      c[*i] = 1;
    }
  }
}

void make_random_vector(vector<int>& v, int n)
{
  for (int i = 0; i < n; ++i)
  {
    v.push_back(rand() % 3);
  }
}

void print_vector(vector<int>& v)
{
  for (auto i = v.begin(); i != v.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
}

void print_counts(map<int,int>& c)
{
  for (auto i = c.begin(); i != c.end(); ++i) {
    cout << "#" << i->first << " = " << i->second << endl;
  }
}

int main()
{
    srand(0);
    vector<int> v;
    make_random_vector(v, 5);
    print_vector(v);

    cout << "\nCount 1" << endl;
    map<int,int>* c1 = new map<int,int>;
    count1(v, *c1);
    print_counts(*c1);
    delete c1;

    cout << "\nCount 2" << endl;
    map<int,int>* c2 = new map<int,int>;
    count2(v, *c2);
    print_counts(*c2);
    delete c2;
    
    return 0;
}
~~~