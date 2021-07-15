#ifndef __MYHASHMAP_HPP__
#define __MYHASHMAP_HPP__

#include "MyNode.hpp"

#define MAXSIZE 7

class HashTable {
 private:
  Node *head[MAXSIZE];

 public:
  HashTable();
  void findKey(int value);
  void deleteKey(int value);
  void insertKey(int value);
  void printTable();
};

HashTable::HashTable() {
  for (int i = 0; i < MAXSIZE; i++) {
    head[i] = NULL;
  }
}

void HashTable::findKey(int value) {
  int key = value % MAXSIZE;
  Node *p;
  if (head[key] != NULL) {
    p = head[key];
    while (p->next != NULL && p->data != value)
      p = p->next;
    if (p->data == value)
      cout << p->data << "'s key is " << key << endl;
    else
      cout << p->data << " is not in table" << endl;
  } else {
    cout << "Table don't have key about" << value << endl;
  }
}

void HashTable::deleteKey(int value) {
  Node *p = NULL;
  Node *q = NULL;
  int key = value % MAXSIZE;

  if (head[key]->data == value) {
    p = head[key];
    head[key] = head[key]->next;
    delete p;
  } else {
    p = head[key];
    while (p != NULL && p->data != value) {
      q = p;
      p = p->next;
    }
    if (p->data == value) {
      q->next = p->next;
      delete p;
    } else {
      cout << value << "is not in table" << endl;
    }
  }
}

void HashTable::insertKey(int value) {
  Node *temp = new Node(value);
  Node *p;
  int key = value % MAXSIZE;

  if (head[key] == NULL)
    head[key] = temp;
  else {
    p = head[key];
    while (p->next != NULL)
      p = p->next;
    p->next = temp;
  }
}

void HashTable::printTable() {
  Node *p;
  for (int i = 0; i < MAXSIZE; i++) {
    cout << "Hash Table[" << i << "]:\t";
    if (head[i] != NULL) {
      p = head[i];
      while (p != NULL) {
        cout << p->data;
        if (p->next != NULL)
          cout << " -> ";
        p = p->next;
      }
    }
    cout << endl;
  }
}

#endif