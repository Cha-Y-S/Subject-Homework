#ifndef __MYSTACK_HPP__
#define __MYSTACK_HPP__

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack {
 private:
  int topIndex;
  vector<T> stack;

 public:
  Stack();
  bool isEmpty();
  void push(T data);
  T pop();
  T top();
};

template <typename T>
Stack<T>::Stack() {
  this->topIndex = -1;
}

template <typename T>
bool Stack<T>::isEmpty() {
  return this->topIndex == -1 ? true : false;
}

template <typename T>
void Stack<T>::push(T data) {
  this->stack.push_back(data);
  topIndex++;
}

template <typename T>
T Stack<T>::pop() {
  if (this->topIndex == -1) {
    cout << "Stack is Empty" << endl;
    return -1;
  } else {
    T result = stack[topIndex--];
    stack.pop_back();
    return result;
  }
}

template <typename T>
T Stack<T>::top() {
  return this->isEmpty() ? -1 : this->stack[this->topIndex];
}
#endif