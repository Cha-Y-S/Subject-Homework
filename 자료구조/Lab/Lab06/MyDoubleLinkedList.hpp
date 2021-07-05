#ifndef __MYDOUBLELINKEDLIST_HPP__
#define __MYDOUBLELINKEDLIST_HPP__

#include "MyNode.hpp"

using namespace std;

class Dll {
 private:
  Node* head;

 public:
  Dll();
  ~Dll();
  bool isEmpty();
  void insertNode(string n, int w, int h);
  void insertAfter(string n, int w, int h, int value);
  void deleteNode(string n);
  void forward();
  void backward();
  void searchNode(string n);
  void findNth(int n);
};

Dll::Dll() {
  this->head = NULL;
}

Dll::~Dll() {
  while (head != NULL) {
    Node* p = this->head;
    this->head = this->head->next;
    delete p;
  }
}

bool Dll::isEmpty() {
  if (this->head == NULL)
    return true;
  else
    return false;
}

void Dll::insertNode(string n, int w, int h) {
  Node* temp = new Node(n, w, h);

  if (this->head == NULL)
    this->head = temp;
  else if (temp->name < this->head->name) {
    temp->next = this->head;
    this->head->prev = temp;
    this->head = temp;
  } else {
    Node *p, *q;
    p = this->head;
    q = NULL;
    while ((p != NULL) && (temp->name > this->head->name)) {
      q = p;
      p = p->next;
    }
    if (p == NULL) {
      q->next = temp;
      temp->prev = q;
    } else {
      q->next = temp;
      temp->prev = q;
      temp->next = p;
      p->prev = temp;
    }
  }
}

void Dll::insertAfter(string n, int w, int h, int value) {
  Node* temp = new Node(n, w, h);
  Node *p, *q;
  int cnt = 0;
  p = this->head;
  q = NULL;

  while ((p != NULL) && (cnt != value)) {
    q = p;
    p = p->next;
    cnt++;
  }
  if (p == NULL || value < 0)
    cout << "Cannot insert" << endl;
  else {
    q->next = temp;
    temp->prev = q;
    temp->next = p;
    p->prev = temp;
  }
}

void Dll::deleteNode(string n) {
  Node *p, *q;
  p = this->head;
  q = NULL;

  if (this->isEmpty())
    cout << "List is empty" << endl;
  else {
    if (this->head->name == n) {
      if (this->head->next == NULL) {
        delete p;
      } else {
        this->head = this->head->next;
        this->head->prev = NULL;
        delete p;
      }
    } else {
      while ((p != NULL) && (p->name != n)) {
        q = p;
        p = p->next;
      }
      if (p->name == n) {
        if (p->next == NULL) {
          q->next = NULL;
          delete p;
        } else {
          q->next = p->next;
          p->next->prev = q;
          delete p;
        }
      } else
        cout << n << " is not in the list" << endl;
    }
  }
}

void Dll::forward() {
  Node* p = this->head;

  if (this->isEmpty()) {
    cout << "List is empty" << endl;
    return;
  }

  cout << "Name\tWeight\tHeight" << endl;
  cout << "-----------------------" << endl;
  while (p != NULL) {
    cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
    p = p->next;
  }
}

void Dll::backward() {
  Node* p;
  p = this->head;

  if (this->isEmpty()) {
    cout << "List is empty" << endl;
    return;
  }

  while (p->next != NULL)
    p = p->next;

  cout << "Name\tWeight\tHeight" << endl;
  cout << "-----------------------" << endl;
  while (p != NULL) {
    cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
    p = p->prev;
  }
}

void Dll::searchNode(string n) {
  Node* p;
  p = this->head;

  if (this->isEmpty()) {
    cout << "List is empty" << endl;
    return;
  }

  while ((p != NULL) && (p->name != n))
    p = p->next;

  if (p == NULL)
    cout << n << " is not in the list" << endl;
  else
    cout << n << " is in the list" << endl;
}

void Dll::findNth(int n) {
  Node* p = this->head;
  int cnt = 1;

  while ((p != NULL) && (cnt != n)) {
    p = p->next;
    cnt++;
  }

  if (p == NULL) {
    switch (n) {
      case 1:
        cout << n << "st Node is not in the list" << endl;
        break;
      case 2:
        cout << n << "nd Node is not in the list" << endl;
        break;
      case 3:
        cout << n << "rd Node is not in the list" << endl;
        break;
      default:
        cout << n << "th Node is not in the list" << endl;
        break;
    }
  } else {
    cout << "Name\tWeight\tHeight" << endl;
    cout << "-----------------------" << endl;
    cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
  }
}

#endif