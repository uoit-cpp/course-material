#ifndef __Student_H__
#define __Student_H__

#include "Person.h"

class Student : public Person 
{
public:
    Student(string name, int age, int grade);

    friend ostream& operator<<(ostream& os, const Student& s);

    int grade;
};

#endif