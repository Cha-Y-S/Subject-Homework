#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <iostream>
#include <vector>

using namespace std;

class Stack {
 private:
  int top;
  vector<int> stack;

 public:
  Stack();
  bool isEmpty();
  void push(int value);
  int pop();
};

Stack::Stack() {
  this->top = -1;
}

bool Stack::isEmpty() {
  if (this->top == -1)
    return true;
  else
    return false;
}

void Stack::push(int value) {
  this->stack.push_back(value);
  this->top++;
}

int Stack::pop() {
  if (this->top == -1)
    return -1;
  else {
    int num = stack[this->top--];
    stack.pop_back();
    return num;
  }
}

#endif