#ifndef __MYLINKEDSTACK_HPP__
#define __MYLINKEDSTACK_HPP__

#include <iostream>

#include "MyNode.hpp"

using namespace std;

class LinkedStack {
 private:
  Node<char> *top;

 public:
  LinkedStack();
  bool isEmpty();
  void push(char value);
  char pop();
  void displayStack();
};

LinkedStack::LinkedStack() {
  this->top = NULL;
}

bool LinkedStack::isEmpty() {
  if (this->top == NULL)
    return true;
  else
    return false;
}

void LinkedStack::push(char value) {
  Node<char> *temp = new Node<char>(value);

  if (this->isEmpty())
    this->top = temp;
  else {
    temp->next = this->top;
    this->top = temp;
  }
}

char LinkedStack::pop() {
  Node<char> *p;
  char a;
  if (this->isEmpty())
    a = -1;
  else {
    a = this->top->data;
    p = top;
    top = top->next;
    delete p;
  }
  return a;
}

void LinkedStack::displayStack() {
  if (this->isEmpty())
    cout << "Stack is empty" << endl;
  else {
    Node<char> *p = top;
    while (p != NULL) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
}

#endif