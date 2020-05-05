#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include "Student.h"
#include "Date.h"
//Template(generic) List class that holds elements of type T
//class T must inherit from Object
template <class T>
class List
{
  class Node
  {
    public:
      T* data;
      Node* next;
  };

  public:
    List();
    ~List();
    void print() const;

    List& operator+=(T*);
    List& operator-=(int);

  private:
    Node* head;
    void add(T*);
    void del(const int);
};

//defining particular List Types that will be used in this instance
//otherwise will recieve undefined reference error
template class List<Student>;
template class List<Date>;

#endif
