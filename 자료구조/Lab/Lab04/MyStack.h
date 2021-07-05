#include <iostream>

using namespace std;

#ifndef __MYSTACK_H__
#define __MYSTACK_H__

class Stack {
 private:
  int top;
  int size;
  char* stack;

 public:
  Stack(int value);
  bool isFull();
  bool isEmpty();
  void push(char value);
  char pop();
  void printStack();
};

#endif
