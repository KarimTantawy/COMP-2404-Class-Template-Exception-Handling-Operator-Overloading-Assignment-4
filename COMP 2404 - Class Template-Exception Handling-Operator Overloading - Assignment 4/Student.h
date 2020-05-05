#ifndef STUDENT_H
#define STUDENT_H

#include <iomanip>
#include "Object.h"
//Student objects that stores student info such as Student Id, name, major and gpa
class Student : public Object
{
  friend ostream& operator<<(ostream&, Student&);

  public:
    Student(string="000000000", string="Hey you!", string="basket-weaving", float=0.0f);
    string getName() const;
    void setName(string n);
    void print() const;

    bool operator<(Student&);
    bool operator==(Student&);

  private:
    const string number;
    string name;
    string majorPgm;
    float  gpa;
};

#endif
