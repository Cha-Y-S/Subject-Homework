#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <iostream>

using namespace std;

class Queue {
 protected:
  int rear;
  int front;
  int size;
  char* queue;

 public:
  Queue(int value);
  bool isEmpty();
  bool isFull();
  void enqueue(char value);
  char dequeue();
  void printQueue();
};

#endif
