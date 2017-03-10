#ifndef __Person_H__
#define __Person_H__

#include <string>
#include <ostream>
using namespace std;

class Person
{
public:
    Person(string name, int age);

    friend ostream& operator<<(ostream& os, const Person& p);

    string name;
    int age;
};

#endif