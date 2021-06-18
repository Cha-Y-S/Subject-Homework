#include "MyStack.h"

Stack::Stack(int value) {
  this->top = -1;
  this->size = value;
  this->stack = new char[this->size];
}

bool Stack::isFull() {
  if (this->top == this->size - 1)
    return true;
  else
    return false;
}

bool Stack::isEmpty() {
  if (this->top == -1)
    return true;
  else
    return false;
}

void Stack::push(char value) {
  if (this->isFull())
    cout << "Stack is Full\t";
  else
    this->stack[++this->top] = value;
}

char Stack::pop() {
  if (this->isEmpty()) {
    cout << "Stack is Empty\t";
    return -1;
  } else
    return this->stack[this->top--];
}

void Stack::printStack() {
  if (this->isEmpty())
    cout << "Stack is Empty\t";
  else {
    cout << "Stack: ";
    for (int i = this->top; i > -1; i--) {
      cout << this->stack[i] << " ";
    }
    cout << "\t";
  }
}