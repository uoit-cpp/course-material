#include <iostream>
#include "Person.h"
#include "Student.h"

int main()
{
    Person p("John", 22);
    cout << p << endl;

    Student s("Doe", 19, 12);
    cout << s << endl;

    Person* p1 = new Student("Jane", 21, 15);
    cout << *p1 << endl;
    cout << *((Student*) p1);

    return 0;
}