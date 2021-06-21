// Singly Linked List - 20163162, Cha Yoonsung, Lab5-1
#include <iostream>

#include "MyLinkedList.hpp"

using namespace std;

int main() {
  LinkedList<int> sll;

  sll.deleteNode(10);

  cout << "List: ";
  sll.insertNode(10);
  sll.insertNode(5);
  sll.printList();

  sll.insertNode(30);
  sll.searchNode(5);

  cout << "List: ";
  sll.deleteNode(5);
  sll.printList();

  sll.printNth(3);
  sll.printLast();

  cout << "Invert List: ";
  sll.insertNode(40);
  sll.invertList();

  return 0;
}