#ifndef __MYHEAP_HPP__
#define __MYHEAP_HPP__

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Heap {
 private:
  vector<int> heap;
  int size;
  int index;

 public:
  Heap();
  Heap(int size);
  bool isEmpty();
  bool isFull();
  void insertHeap(int element);
  int deleteHeap();
  int levelHeap();
  void printHeap();
};

Heap::Heap() {
  this->size = 3;
  this->index = 0;
  for (int i = 0; i < this->size; i++)
    heap.push_back(-1);
}

Heap::Heap(int size) {
  this->size = size;
  this->index = 0;
  for (int i = 0; i < this->size; i++)
    heap.push_back(-1);
}

bool Heap::isEmpty() {
  return this->index == 0 ? true : false;
}

bool Heap::isFull() {
  return this->index == this->size ? true : false;
}

void Heap::insertHeap(int element) {
  int i;
  if (isFull()) {
    cout << "Heap is Full" << endl;
    return;
  }
  i = ++index;
  while ((i != 1) && (element < heap[i / 2])) {
    heap[i] = heap[i / 2];
    i = i / 2;
  }
  heap[i] = element;
}

int Heap::deleteHeap() {
  if (isEmpty()) {
    cout << "Heap is Empty" << endl;
    return 0;
  }

  int parent, child, temp, item;

  item = heap[1];
  temp = heap[index--];
  parent = 1;
  child = 2;

  while (child <= index) {
    if ((child < index) && (heap[child] > heap[child + 1]))
      child++;
    else if (temp <= heap[child])
      break;
    heap[parent] = heap[child];
    parent = child;
    child *= 2;
  }
  heap[parent] = temp;
  return item;
}

int Heap::levelHeap() {
  return int(log2(index) + 1);
}

void Heap::printHeap() {
  cout << "( ";
  for (int i = 1; i < index + 1; i++) {
    cout << heap[i] << " ";
  }
  cout << ")" << endl;
}

#endif