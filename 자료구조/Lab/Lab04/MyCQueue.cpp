#include "MyCQueue.h"

CQueue::CQueue(int value) : Queue(value) {
}

bool CQueue::isFull() {
  if (this->front == (this->rear + 1) % this->size)
    return true;
  else
    return false;
}

void CQueue::enqueue(char value) {
  if (this->isFull())
    cout << "CQueue is Full\t";
  else {
    this->rear = (this->rear + 1) % this->size;
    this->queue[this->rear] = value;
  }
}

char CQueue::dequeue() {
  if (this->isEmpty()) {
    cout << "CQueue is Empty\t";
    return -1;
  } else {
    this->front = (this->front + 1) % this->size;
    return this->queue[this->front];
  }
}

void CQueue::printCQueue() {
  if (this->isEmpty())
    cout << "Cqueue is Empty\t";
  else {
    cout << "CQueue: ";
    int i = this->front;
    while (i != this->rear) {
      i = (i + 1) % this->size;
      cout << this->queue[i] << " ";
    }
    cout << "\t";
  }
}