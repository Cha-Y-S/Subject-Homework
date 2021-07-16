#include "MyHashMap.hpp"

int main() {
  HashTable ht;
  int input;
  int value;
  cout << "---------- MENU ----------" << endl;
  cout << "| 1. findKey\t\t |" << endl;
  cout << "| 2. insertKey\t\t |" << endl;
  cout << "| 3. deleteKey\t\t |" << endl;
  cout << "| 4. Quit\t\t |" << endl;
  cout << "--------------------------" << endl;

  do {
    cout << "Input number: ";
    cin >> input;
    switch (input) {
      case 1:
        cout << "Input number to find: ";
        cin >> value;
        ht.findKey(value);
        break;
      case 2:
        cout << "Input number to insert: ";
        cin >> value;
        ht.insertKey(value);
        break;
      case 3:
        cout << "Input number to delete: ";
        cin >> value;
        ht.deleteKey(value);
        break;
      case 4:
        break;
      default:
        cout << "Error: Wrong Input!" << endl;
        cout << "Please input number in the menu" << endl;
        break;
    }
    cout << endl;
    ht.printTable();
    cout << endl;
  } while (input != 4);

  return 0;
}