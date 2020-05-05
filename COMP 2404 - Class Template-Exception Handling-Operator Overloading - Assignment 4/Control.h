#ifndef CONTROL_H
#define CONTROL_H

#include "List.h"
#include "View.h"
#include "Student.h"
#include "Date.h"

//control class responsible for flow of program
class Control
{
  public:
    void launch();

  private:
    List<Student> students;
    List<Date> dates;
    View view;

    void initStudents();
    void initDates();
};

#endif
