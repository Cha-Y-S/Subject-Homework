#include <fstream>
#include <iostream>

#include "MyStack.hpp"

using namespace std;

int priority(char input);
char *converseInfixToPostfix(char *buffer);
int evalPostFix(char *buffer);

int main() {
  char buffer[BUFSIZ];
  char *postfix;

  ifstream infile("HW2.dat", ios::in);

  while (infile.getline(buffer, BUFSIZ)) {
    cout << "1) Echo data\t(infix form)\t: " << buffer << endl;
    cout << "2) Conversion\t(postifx form)\t: ";
    postfix = converseInfixToPostfix(buffer);
    cout << endl;
    cout << "3) Result\t\t\t: " << evalPostFix(postfix) << endl;
    cout << endl;
  }
}

int priority(char input) {
  switch (input) {
    case ')':
      return 4;
      break;
    case '*':
    case '/':
      return 3;
      break;
    case '+':
    case '-':
      return 2;
      break;
    case '(':
      return 1;
      break;
    case ' ':
      return -1;
      break;
    default:
      return 0;
      break;
  }
}

char *converseInfixToPostfix(char *buffer) {
  Stack<char> stkCon;
  static char post[BUFSIZ];

  int i = 0, j = 0;
  while (buffer[i] != '\0') {
    switch (priority(buffer[i])) {
      case 0:
        post[j++] = buffer[i];
        cout << buffer[i] << " ";
        break;
      case 4:
        while (stkCon.top() != '(') {
          post[j] = stkCon.pop();
          cout << post[j++] << " ";
        }
        break;
      case 3:
      case 2:
        if (priority(buffer[i]) >= priority(stkCon.top())) {
          stkCon.push(buffer[i]);
        }

        else {
          post[j] = stkCon.pop();
          cout << post[j++] << " ";
          stkCon.push(buffer[i]);
        }
        break;
      case 1:
        stkCon.push(buffer[i]);
        break;
      default:
        break;
    }
    i++;
  }

  while (!stkCon.isEmpty()) {
    if (stkCon.top() == '(') {
      stkCon.pop();
      continue;
    } else {
      post[j] = stkCon.pop();
      cout << post[j++] << " ";
    }
  }
  post[j] = '\0';

  return post;
}

int evalPostFix(char *buffer) {
  Stack<int> stkEval;

  int i = 0;
  int op1, op2;
  while (buffer[i] != '\0') {
    switch (priority(buffer[i])) {
      case 0:
        stkEval.push(buffer[i] - '0');
        break;
      case 3:
      case 2:
        op2 = stkEval.pop();
        op1 = stkEval.pop();

        switch (buffer[i]) {
          case '+':
            stkEval.push(op1 + op2);
            break;
          case '-':
            stkEval.push(op1 - op2);
            break;
          case '*':
            stkEval.push(op1 * op2);
            break;
          case '/':
            stkEval.push(op1 / op2);
            break;
        }
        break;
      default:
        break;
    }
    i++;
  }
  return stkEval.pop();
}