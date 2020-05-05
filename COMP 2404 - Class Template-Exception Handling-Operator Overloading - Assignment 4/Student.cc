#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"

//initialize data members
Student::Student(string s1, string s2, string s3, float g)
  : number(s1), name(s2), majorPgm(s3), gpa(g) { }

string Student::getName() const { return name; }
void Student::setName(string n) { name = n; }
//check equality between two student objects name and student number
bool Student::operator==(Student& stu)
{
  return (name == stu.name && number == stu.number);
}
//compare between two student objects name
bool Student::operator<(Student& stu)
{
  return (name < stu.name);
}
//print appropriate info
ostream& operator<<(ostream& out, Student& stu)
{
  out<<"Student:  " << stu.number << "  " << left << setw(10) << stu.name << " "
                     << setw(15) << stu.majorPgm << "   GPA: "
                     << fixed << setprecision(2) << setw(5) << right << stu.gpa <<", ObjectID: "<<
                     stu.getId() << endl;
  return out;
}
