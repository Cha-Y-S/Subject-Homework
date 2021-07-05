#ifndef __MYNODE_HPP__
#define __MYNODE_HPP__

#include <iostream>

using namespace std;

template <typename T>
class Node {
 public:
  T data;
  Node<T> *left;
  Node<T> *right;

 public:
  Node(T value);
};

template <typename T>
Node<T>::Node(T value) : data(value), left(NULL), right(NULL) {}

#endif