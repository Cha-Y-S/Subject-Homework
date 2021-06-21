#ifndef __MYCQUEUE_H__
#define __MYCQUEUE_H__

#include <iostream>

#include "MYQueue.h"

using namespace std;

class CQueue : public Queue {
 public:
  CQueue(int value);
  bool isFull();
  void enqueue(char value);
  char dequeue();
  void printCQueue();
};

#endif