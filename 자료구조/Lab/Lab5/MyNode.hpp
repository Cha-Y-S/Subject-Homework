#ifndef __MYNODE_H__
#define __MYNODE_H__

template <class T>
class Node {
 public:
  T data;
  Node* next;

 public:
  Node(T value) : data(value), next(0) {}
};

#endif