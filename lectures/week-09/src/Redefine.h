////////////////////////////////////////////////////////////////
// from Person.h
////////////////////////////////////////////////////////////////
class Person 
{
    ...
    void print_info(); 
};

////////////////////////////////////////////////////////////////
// from Student.h
////////////////////////////////////////////////////////////////
class Student : public Person
{
    ...
    void print_info(); // Redefining print_info() base class method
};

////////////////////////////////////////////////////////////////
// from main.cpp
////////////////////////////////////////////////////////////////
Person p;
Student s;
s.print_info(); // Calls redefined function
s.Person::print_info(); // Calls original print_info() base class method
