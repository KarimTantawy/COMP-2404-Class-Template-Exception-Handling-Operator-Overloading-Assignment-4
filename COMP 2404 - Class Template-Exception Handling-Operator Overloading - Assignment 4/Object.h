#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
using namespace std;

//Object super class that manages Id's of objects
class Object
{
  public:
    Object();
    int getId();

  private:
    static int nextId;
    int id;

};

#endif
