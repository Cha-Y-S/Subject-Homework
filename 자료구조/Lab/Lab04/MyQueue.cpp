#include "MyQueue.h"

Queue::Queue(int value) {
  this->front = this->rear = -1;
  this->size = value;
  this->queue = new char[this->size];
}

bool Queue::isEmpty() {
  if (this->front == this->rear)
    return true;
  else
    return false;
}

bool Queue::isFull() {
  if (this->rear == this->size - 1)
    return true;
  else
    return false;
}

void Queue::enqueue(char value) {
  if (this->isFull())
    cout << "Queue is Full\t";
  else
    this->queue[++this->rear] = value;
}

char Queue::dequeue() {
  if (this->isEmpty()) {
    cout << "Queue is Empty\t";
    return -1;
  } else
    return this->queue[++this->front];
}

void Queue::printQueue() {
  if (this->isEmpty())
    cout << "Queue is empty\t";
  else {
    cout << "Queue: ";
    for (int i = this->front + 1; i <= this->rear; i++) {
      cout << this->queue[i] << " ";
    }
    cout << "\t";
  }
}