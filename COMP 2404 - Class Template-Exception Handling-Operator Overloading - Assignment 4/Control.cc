#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "View.h"
#include "Student.h"
#include "List.h"
#include "Date.h"

//launch ui
void Control::launch()
{
  int    choice, id;
  string name, num, maj;
  float  gpa;

  initStudents();
  initDates();

  while (1) {
    view.showMenu(choice);

    if (choice == 0)
      break;

    if (choice == 1) {
      view.printStr("Number: ");
      view.readStr(num);
      view.printStr("Name: ");
      view.readStr(name);
      view.printStr("Major: ");
      view.readStr(maj);
      view.printStr("GPA: ");
      view.readFloat(gpa);

      students += new Student(num, name, maj, gpa);

    }
    else if (choice == 2) {
      view.printStr("Id: ");
      view.readInt(id);

      try
      {
          students -= id;
      }
      catch(string str)
      {
        view.printStr("\nError: " + str + "\n\n");
      }
    }
    else if (choice == 3) {
      view.printStr("Students: \n");
      students.print();
    }
  }

  view.printStr("Students: \n");
  students.print();
  view.printStr("\n");

  view.printStr("Dates: \n");
  dates.print();
  view.printStr("\n");

}
//initialize list of date objects
void Control::initDates()
{
  dates += new Date(23, 12, 1990);
  dates += new Date(0, 0, 2000);
  dates += new Date(1, 1, 2020);
  dates += new Date(14, 5, 2017);
  dates += new Date(13, 12, 2001);
  dates += new Date(24, 12, 2001);
  dates += new Date(27, 7, 2001);
  dates += new Date(6, 6, 0000);
  dates += new Date(5, 9, 2220);
  dates += new Date(13, 11, 2020);
}
//initialize list of student objects
void Control::initStudents()
{
  students += new Student("101083898", "Karim Tantawy", "CompSci", 1.0f);
  students += new Student("123123436", "Alfred", "CompSci", 3.2f);
  students += new Student("193828382", "Fred", "Law", 2.2f);
  students += new Student("129383537", "Christine", "Political Science", 2.4f);
  students += new Student("233523583", "Zed", "Undecided", 3.4f);
  students += new Student("124837572", "Ben", "Compsci", 0.2f);
  students += new Student("387356358", "Gerald", "blanket-weaving", 3.2f);
  students += new Student("385385385", "Helen", "sweater-weaving", 1.0f);
  //Test For Duplicates
  students += new Student("385772685", "Steven", "basket-weaving", 2.0f);
//  students += new Student("385772685", "Steven", "basket-weaving", 2.0f);

  students += new Student("746295826", "Cornelious", "weaving", 4.0f);
}
