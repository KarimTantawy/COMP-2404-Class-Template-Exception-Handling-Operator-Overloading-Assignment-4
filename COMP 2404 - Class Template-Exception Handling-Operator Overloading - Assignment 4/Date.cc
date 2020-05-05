#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"
//ctor
Date::Date(int d, int m, int y)
{
  cout<<"in default ctor"<<endl;
  setDate(d, m, y);
}
//dtor
Date::~Date()
{
  cout<<"in dtor"<<endl;
}
//set particular date
void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}
//overloading == with other Date objects
bool Date::operator==(Date& d)
{
    return (year == d.year && month == d.month && day == d.day);
}
//overloading < with other Date objects
bool Date::operator<(Date& d)
{
  if(year < d.year)
    return true;
  else if(year == d.year)
  {
    if(month < d.month)
      return true;
    else if(month == d.month)
    {
      if(day < d.day)
        return true;
    }
  }

  return false;
}
//overloading << to output Date data
ostream& operator<<(ostream& out, Date& d)
{
  out<<setfill('0')<<setw(2)<<d.day<<"/"
      <<setfill('0')<<setw(2)<<d.month<<"/"
      <<setfill('0')<<setw(4)<<d.year<<", ObjectID: "
      <<d.getId()<<endl;
  return out;
}

void Date::printLong() const
{
  cout << "in the const version" << endl;
  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;
//  day = 13;
}

void Date::printLong()
{
  cout << "in the non-const version" << endl;
  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;
  day = 13;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = {
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}
