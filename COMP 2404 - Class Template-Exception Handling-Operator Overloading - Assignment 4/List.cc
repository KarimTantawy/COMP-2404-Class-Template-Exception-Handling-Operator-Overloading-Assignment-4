#include <iostream>
#include <string>
using namespace std;

#include "List.h"

template <class T>
List<T>::List() : head(NULL) { }

template <class T>
List<T>::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}
//overloading += to add aditional elements of type T
template <class T>
List<T>& List<T>::operator+=(T* d)
{
  add(d);
  return *this;
}
//removing elements of type T, by Object Id
template <class T>
List<T>& List<T>::operator-=(int id)
{
  del(id);
  return *this;
}
//helper function for overloaded operator +=
template <class T>
void List<T>::add(T* d)
{
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = d;
  tmpNode->next = NULL;

  prevNode = NULL;
  currNode = head;

  while (currNode != NULL)
  {

    if(*d == *currNode->data)
    {
      delete tmpNode;
      return;
    }

    if (*d < *currNode->data)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL)
    head = tmpNode;
  else
    prevNode->next = tmpNode;

  tmpNode->next  = currNode;

}
//helper function for overloaded operator -=
template <class T>
void List<T>::del(const int id)
{
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getId() == id)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

// we get here if we didn't find the name or if we did find the name
  if (currNode == NULL) {
    throw((string)"Object ID " + to_string(id) + " does not exist!");
    return;
  }

  if (prevNode == NULL)
    head = currNode->next;
  else
    prevNode->next = currNode->next;

  delete currNode->data;
  delete currNode;
}

template <class T>
void List<T>::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    cout<<*currNode->data<<endl;
    currNode = currNode->next;
  }
}
