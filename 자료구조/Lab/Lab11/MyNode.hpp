#ifndef __MYNODE_HPP__
#define __MYNODE_HPP__

#include <iostream>

using namespace std;

class Node {
 public:
  int data;
  Node *next;

 public:
  Node();
  Node(int data);
};

Node::Node() : data(-1), next(NULL) {
}

Node::Node(int data) : data(data), next(NULL) {}

#endif