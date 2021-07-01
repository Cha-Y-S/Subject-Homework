#ifndef __MYLIST_HPP__
#define __MYLIST_HPP__

#include "MyNode.hpp"

using namespace std;

class List {
 private:
  Node* head;

 public:
  List();
  bool isEmpty();
  void insertList(char name, int id, string major, char grade);
  void displayList();
  void searchMajor(string major);
  void searchGrade(char grade);
  List mergeList(List a, List b);
};

List::List() {
  this->head = NULL;
}

bool List::isEmpty() {
  return this->head == NULL ? true : false;
}

void List::insertList(char name, int id, string major, char grade) {
  Node* temp = new Node(name, id, major, grade);
  Node* p = this->head;
  Node* q = NULL;

  if (isEmpty()) {
    this->head = temp;
  } else if (temp->name < this->head->name) {
    temp->next = head;
    head = temp;
  } else {
    p = head;
    while ((p != NULL) && p->name < temp->name) {
      q = p;
      p = p->next;
    }
    if (p != NULL) {
      temp->next = p;
      q->next = temp;
    } else {
      q->next = temp;
    }
  }
}

void List::displayList() {
  Node* p = NULL;
  if (!isEmpty()) {
    p = head;
    cout << "Name\tID\tMajor\tGrade" << endl;
    while (p) {
      cout << p->name << "\t";
      cout << p->id << "\t";
      cout << p->major << "\t";
      cout << p->grade << endl;
      p = p->next;
    }
  } else {
    cout << "List is Empty" << endl;
  }
}

void List::searchMajor(string major) {
  Node* p = NULL;
  if (!isEmpty()) {
    p = head;
    cout << "Name\tID\tMajor\tGrade" << endl;
    while (p) {
      if (p->major == major) {
        cout << p->name << "\t";
        cout << p->id << "\t";
        cout << p->major << "\t";
        cout << p->grade << endl;
      }
      p = p->next;
    }
  } else {
    cout << "List is Empty" << endl;
  }
}

void List::searchGrade(char grade) {
  Node* p = NULL;
  if (!isEmpty()) {
    p = head;
    cout << "Name\tID\tMajor\tGrade" << endl;
    while (p) {
      if (p->grade == grade) {
        cout << p->name << "\t";
        cout << p->id << "\t";
        cout << p->major << "\t";
        cout << p->grade << endl;
      }
      p = p->next;
    }
  } else {
    cout << "List is Empty" << endl;
  }
}

List List::mergeList(List a, List b) {
  List c;
  Node* p = a.head;
  Node* q = b.head;
  if (!a.isEmpty() || !b.isEmpty()) {
    while (p != NULL) {
      c.insertList(p->name, p->id, p->major, p->grade);
      p = p->next;
    }
    while (q != NULL) {
      c.insertList(q->name, q->id, q->major, q->grade);
      q = q->next;
    }
  }

  return c;
}

#endif