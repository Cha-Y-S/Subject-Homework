#include "MyLinkedList.hpp"
#include "MyLinkedQueue.hpp"
#include "MyLinkedStack.hpp"

int main() {
  LinkedStack list1;
  LinkedQueue list2;
  LinkedList<char> list3;
  LinkedList<char> list4;

  cout << "List 1: ";
  list1.push('a');
  list1.push('e');
  list1.displayStack();

  cout << "List 2: ";
  list2.enqueue('b');
  list2.enqueue('c');
  list2.enqueue('d');
  list2.displayQueue();

  cout << "List 3: ";
  list3.concatenate(list1, list2);
  list3.printList();

  cout << "List 4: ";
  list4.getInvertList(list3);
  list4.printList();

  return 0;
}