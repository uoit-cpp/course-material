#include "Person.h"

Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << "Person: name = " 
       << p.name << ", age = " 
       << p.age;
    return os;
}