# CSCI 1061 - Programming Workshop 2

## Lab 8 - C++ STL

**Due back on Saturday, April 1 before 11:59 pm.**

### Goal: a program to manage student records

You are asked to implement a program to manage `Student` records of the following form:

~~~cpp
class Student
{
  private:
  std::string name_;
  int number_;
  std::vector<int> grades_;
  const int num_courses_;
  
  // You need to implement the following four methods
  static std::string gen_name() { // To do }
  static int gen_number() { // To do }
  static int gen_grade() { // To do }  
  double compute_average() { // To do }
  
  public:
  Student(const std::string& name, int number) : name_(name), number_(number), num_courses_(5)
  {
    for (int i=0; i<num_courses_; ++i) {
      grades_.push_back(std::rand());
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Name = " << s.name_ << ", Number = " << s.number_;
    return os;
  }

  void print_grades(std::ostream& os) const
  {
    for (int i=0; i<num_courses_; ++i) {
      os << grades_[i] << ", ";
    }
  }
};
~~~

#### Number of students will be specified at runtime

The number of students to be stored in the system will be specified at runtime via commandline arguments.  The program will take 1 argument whose value will indicate the number of students to stored in the system.  The following call, for example, will store $7$ students in the system.

~~~bash
$ student-record 7
...
~~~

#### Student records will be initialized with random values

Names, numbers and grades will be set to random values with the following constraints:

- A name is a random string (a-zA-Z0-9) between 6 and 12 characters long;
- A number is a random integer between 201100000 and 201600000; and
- A grade is a random integer between 70 and 100.

*Note that each student stores only 5 grades.*

#### Required functionality

The program will store students in `std::vector` and will implement the following functionality:

1. Print student records; 
- Print student records sorted by name (ascending order); 
- Print student records sorted by average grade (ascending order); and
- Print the student record with the highest average grade (and print average values). 

*Average values may be floats.*

### Some example code to get you started

Consider the code shown below, which showcases the use of `sort` algorithm available in STL.

~~~cpp
#include <iostream>
#include <vector>
#include <ctime> // time()
#include <cstdlib> // srand(), rand()
#include <algorithm> // min_element(), max_element(), sort()

bool sort(int i, int j) { return (i<j); }

int main()
{
  std::srand(std::time(0));

  std::vector<int> x;
  int n = 10;
  for (int i=0; i<n; ++i) {
    x.push_back(std::rand());
  }

  for (std::vector<int>::iterator xi = x.begin(); xi != x.end(); xi++) {
    std::cout << *xi << std::endl;
  }

  std::cout << "min value = " << *std::min_element(x.begin(), x.end()) << std::endl;
  std::cout << "index of min value = " << std::min_element(x.begin(), x.end()) - x.begin() << std::endl;
  
  std::cout << "max value = " << *std::max_element(x.begin(), x.end()) << std::endl;
  std::cout << "index of max value = " << std::max_element(x.begin(), x.end()) - x.begin() << std::endl;

  std::sort(x.begin(), x.end());
  for (std::vector<int>::iterator xi = x.begin(); xi != x.end(); xi++) {
    std::cout << *xi << std::endl;
  }
  
  std::sort(x.begin(), x.end(), sort);
  for (std::vector<int>::iterator xi = x.begin(); xi != x.end(); xi++) {
    std::cout << *xi << std::endl;
  }

  return 0;
}
~~~

### What to submit?

Please submit your source code via Blackboard.  *It is suggested that you implement the entire functionality in a single cpp file.*    