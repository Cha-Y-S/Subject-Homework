// Stack Palindrome - 20163162, Cha Yoonsung, Lab3-2
#include <cstring>
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

void checkPalindrome(char* buffer);
bool compare(char a, char b);

int main() {
  ifstream infile;
  infile.open("Lab3-2.dat");
  char buffer[80];

  while (!infile.eof()) {
    infile >> buffer;
    cout << buffer << "\t\t";
    checkPalindrome(buffer);
  }

  return 0;
}

void checkPalindrome(char* buffer) {
  Stack stack(MAX_SIZE);
  int length = strlen(buffer);
  int i;

  if (length % 2 == 0) {
    for (i = 0; i < length / 2; i++)
      stack.push(buffer[i]);
  } else {
    for (i = 0; i < length / 2; i++)
      stack.push(buffer[i]);
    i++;
  }

  bool flag;
  while (!stack.isEmpty()) {
    flag = compare(buffer[i], stack.pop());
    if (flag == false) {
      cout << "Not a Palindrome" << endl;
      return;
    }
    i++;
  }
  cout << "A Palindrome" << endl;
}

bool compare(char a, char b) {
  if (a == b)
    return true;
  else
    return false;
}