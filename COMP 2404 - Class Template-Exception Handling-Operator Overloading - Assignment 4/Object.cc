#include <iostream>
using namespace std;
#include <string>

#include "Object.h"

int Object::nextId = 1;

Object::Object()
{
  //initialize id;
  id = nextId;
  //increment static variable to avoid duplicate ids
  nextId++;
}

int Object::getId()
{
  return id;
}
