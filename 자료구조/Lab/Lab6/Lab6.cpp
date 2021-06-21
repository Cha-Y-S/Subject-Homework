#include <fstream>

#include "MyDoubleLinkedList.hpp"

int main() {
  Dll dll;
  ifstream input;
  string name;
  int weight, height;
  input.open("lab6.dat", ios::in);

  while (!input.eof()) {
    input >> name >> weight >> height;
    dll.insertNode(name, weight, height);
  }

  cout << "1. Forward List" << endl;
  dll.forward();
  cout << endl;

  cout << "2. Search \"Lee\"" << endl;
  dll.searchNode("lee");
  cout << endl;

  cout << "3. Delete \"Lee\"" << endl;
  dll.deleteNode("lee");
  dll.forward();
  cout << endl;

  cout << "4. Insert-after(2nd) - data: park 73 176" << endl;
  dll.insertAfter("park", 73, 176, 2);
  dll.forward();
  cout << endl;

  cout << "5. Find 2nd" << endl;
  dll.findNth(2);
  cout << endl;

  cout << "6. Backward List" << endl;
  dll.backward();

  return 0;
}