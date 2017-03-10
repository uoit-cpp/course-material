#include "Student.h"

Student::Student(string name, int age, int grade) :
    Person(name, age)
{
    this->grade = grade;    
}

ostream& operator<<(ostream& os, const Student& p)
{
    os << "Student: name = " 
       << p.name << ", age = " 
       << p.age << ", grade = " 
       << p.grade;
    return os;
}