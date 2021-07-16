// Recursive Addition, Difference & Sum - 20163162, Cha Yoonsung, Lab1-2
#include <iostream>

using namespace std;

int recursiveAdd(int x, int y);
int recursiveDiff(int x, int y);
int recursiveSum(int x);

int main() {
  int x, y, z;

  cout << "Enter number 1: ";
  cin >> x;

  cout << "Enter number 2: ";
  cin >> y;

  cout << "\tAddition Result is: " << recursiveAdd(x, y) << endl;
  cout << "\tDifference Result is: " << recursiveDiff(x, y) << endl;

  cout << "Enter number 3: ";
  cin >> z;

  cout << "\tResult is: ";
  int sum = recursiveSum(z);
  cout << sum << endl;

  return 0;
}

int recursiveAdd(int x, int y) {
  if (y == 0)
    return x;
  else
    return recursiveAdd(x + 1, y - 1);
}

int recursiveDiff(int x, int y) {
  if (x > y) {
    int temp = x;
    x = y;
    y = temp;
  }

  if (x == 0)
    return y;
  else
    return recursiveDiff(x - 1, y - 1);
}

int recursiveSum(int x) {
  int sum = 0;
  if (x == 1) {
    cout << x << " = ";
    return 1;
  } else {
    cout << x << " + ";
    sum += x + recursiveSum(x - 1);
  }
  return sum;
}