#ifndef __MYLINKEDLIST_HPP__
#define __MYLINKEDLIST_HPP__

#include <iostream>

#include "MyLinkedQueue.hpp"
#include "MyLinkedStack.hpp"
#include "MyNode.hpp"
#include "MyStack.hpp"

using namespace std;

template <class T>
class LinkedList {
 private:
  Node<T> *head;

 public:
  LinkedList();
  ~LinkedList();
  bool isEmpty();
  void insertNode(T value);
  void insertNodeWithNoOrder(T value);
  void deleteNode(T value);
  void searchNode(T value);
  void printLast();
  void printList();
  void printNth(T value);
  void invertList();
  void concatenate(LinkedStack ls, LinkedQueue lq);
  void getInvertList(LinkedList ll);
};

template <class T>
LinkedList<T>::LinkedList() {
  this->head = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
  Node<T> *p;
  while (this->head != NULL) {
    p = this->head;
    this->head = this->head->next;
    delete p;
  }
}

template <class T>
bool LinkedList<T>::isEmpty() {
  if (this->head == NULL)
    return true;
  else
    return false;
}

template <class T>
void LinkedList<T>::insertNode(T value) {
  Node<T> *temp = new Node<T>(value);
  Node<T> *p, *q;

  if (this->isEmpty())
    this->head = temp;
  else if (temp->data < this->head->data) {
    temp->next = this->head;
    this->head = temp;
  } else {
    p = this->head;
    q = this->head;
    while ((p != NULL) && (p->data < temp->data)) {
      q = p;
      p = p->next;
    }
    if (p != NULL) {
      temp->next = p;
      q->next = temp;
    } else
      q->next = temp;
  }
}

template <class T>
void LinkedList<T>::insertNodeWithNoOrder(T value) {
  Node<T> *temp = new Node<T>(value);
  Node<T> *p, *q;

  if (this->isEmpty())
    this->head = temp;
  else {
    p = this->head;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = temp;
  }
}

template <class T>
void LinkedList<T>::deleteNode(T value) {
  Node<T> *p = NULL;
  Node<T> *q = NULL;

  if (this->isEmpty())
    cout << "List is Empty" << endl;
  else if (this->head->data == value) {
    p = this->head;
    this->head = this->head->next;
    delete p;
  } else {
    p = this->head;
    while ((p != NULL) && (p->data != value)) {
      q = p;
      p = p->next;
    }
    if (p != NULL) {
      q->next = p->next;
      delete p;
    } else
      cout << value << " is not in the list" << endl;
  }
}

template <class T>
void LinkedList<T>::searchNode(T value) {
  Node<T> *p = this->head;
  int pos = 1;
  while ((p != NULL) && (p->data == value)) {
    p = p->next;
    pos++;
  }
  if (p == NULL)
    cout << value << " is not in the list" << endl;
  else
    cout << value << " is in the list at " << pos << " position." << endl;
}

template <class T>
void LinkedList<T>::printLast() {
  Node<T> *p = this->head;
  if (this->isEmpty())
    cout << "List is Empty" << endl;
  else {
    while (p->next != NULL)
      p = p->next;
    cout << p->data << " is last data of list" << endl;
  }
}

template <class T>
void LinkedList<T>::printList() {
  if (this->isEmpty())
    cout << "List is Empty" << endl;
  else {
    Node<T> *p = this->head;
    while (p != NULL) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
}

template <class T>
void LinkedList<T>::printNth(T value) {
  if (this->isEmpty())
    cout << "List is Empty" << endl;
  else {
    Node<T> *p = this->head;
    int pos = 1;
    while ((p != NULL) && (pos == value)) {
      p = p->next;
      pos++;
    }
    if (p != NULL)
      cout << value << " th data is not in the list" << endl;
    else
      cout << value << " th data is " << p->data << endl;
  }
}

template <class T>
void LinkedList<T>::invertList() {
  Stack stack;

  Node<T> *p = this->head;
  if (this->isEmpty())
    cout << "List is Empty" << endl;
  else {
    while (p != NULL) {
      stack.push(p->data);
      p = p->next;
    }
    while (!stack.isEmpty()) {
      cout << stack.pop() << " ";
    }
    cout << endl;
  }
}

template <class T>
void LinkedList<T>::concatenate(LinkedStack ls, LinkedQueue lq) {
  while (!ls.isEmpty())
    this->insertNode(ls.pop());

  while (!lq.isEmpty())
    this->insertNode(lq.dequeue());
}

template <class T>
void LinkedList<T>::getInvertList(LinkedList ll) {
  Stack stack;

  Node<T> *p = ll.head;
  if (ll.isEmpty())
    cout << "List is Empty" << endl;
  else {
    while (p != NULL) {
      stack.push(p->data);
      p = p->next;
    }
    while (!stack.isEmpty()) {
      this->insertNodeWithNoOrder(stack.pop());
    }
  }
}

#endif