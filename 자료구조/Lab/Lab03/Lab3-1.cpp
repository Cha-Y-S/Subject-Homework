// Parentheses Checker - 20163162, Cha Yoonsung, Lab3-1
#include <fstream>
#include <iostream>
#define MAX_SIZE 100

using namespace std;

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
};

Stack::Stack(int value) {
  this->top = -1;
  this->size = value;
  this->stack = new char[size];
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
  if (isFull())
    return;
  else
    this->stack[++this->top] = value;
}

char Stack::pop() {
  if (isEmpty())
    return -1;
  else
    return this->stack[this->top--];
}

bool checkParentheses(char* buffer);
bool match(char a, char b);

int main() {
  ifstream infile;
  infile.open("lab3-1.dat", ios::in);
  char buffer[80];

  while (infile.getline(buffer, 80)) {
    cout << buffer << "\t\t";
    bool validity = checkParentheses(buffer);
    if (validity)
      cout << "Valid" << endl;
  }

  return 0;
}

bool checkParentheses(char* buffer) {
  Stack stack(MAX_SIZE);
  int i = 0;

  while (buffer[i] != '\0') {
    if (buffer[i] == '(' || buffer[i] == '{' || buffer[i] == '[')
      stack.push(buffer[i]);
    if (buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']') {
      if (stack.isEmpty()) {
        cout << "Invalid(Unbalanced Parenthese)" << endl;
        return false;
      } else {
        char temp = stack.pop();
        if (!match(temp, buffer[i])) {
          cout << "Invalid(Mismatched Parentheses)" << endl;
          return false;
        }
      }
    }
    i++;
  }

  if (stack.isEmpty())
    return true;
  else {
    cout << "Invalid(Unbalanced Parentheses)" << endl;
    return false;
  }
}

bool match(char a, char b) {
  switch (a) {
    case '(':
      if (b == ')')
        return true;
      else
        return false;
      break;
    case '{':
      if (b == '}')
        return true;
      else
        return false;
      break;
    case '[':
      if (b == ']')
        return true;
      else
        return false;
  }
}