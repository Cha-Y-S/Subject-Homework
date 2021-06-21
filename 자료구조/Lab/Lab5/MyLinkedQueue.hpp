#ifndef __MYLINKEDQUEUE_HPP__
#define __MYLINKEDQUEUE_HPP__

#include <iostream>

#include "MyNode.hpp"

using namespace std;

class LinkedQueue {
 private:
  Node<char> *front;
  Node<char> *rear;

 public:
  LinkedQueue();
  bool isEmpty();
  void enqueue(char value);
  char dequeue();
  void displayQueue();
};

LinkedQueue::LinkedQueue() {
  this->front = NULL;
  this->rear = NULL;
}

bool LinkedQueue::isEmpty() {
  if (this->front == NULL)
    return true;
  else
    return false;
}

void LinkedQueue::enqueue(char value) {
  Node<char> *temp = new Node<char>(value);

  if (this->isEmpty()) {
    this->front = temp;
    this->rear = temp;
  } else {
    this->rear->next = temp;
    this->rear = temp;
  }
}

char LinkedQueue::dequeue() {
  Node<char> *p;
  char a;
  if (this->isEmpty())
    a = -1;
  else {
    a = this->front->data;
    p = this->front;

    if (this->front == this->rear) {
      this->front = NULL;
      this->rear = NULL;
    } else
      this->front = this->front->next;

    delete p;
  }
  return a;
}

void LinkedQueue::displayQueue() {
  Node<char> *p;

  if (this->isEmpty())
    cout << "Queue is Empty" << endl;
  else {
    p = this->front;
    while (p != NULL) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
}

#endif