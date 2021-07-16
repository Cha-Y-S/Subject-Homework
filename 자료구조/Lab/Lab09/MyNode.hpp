#ifndef __MYNODE_HPP__
#define __MYNODE_HPP__

#include <iostream>

using namespace std;

class Node {
 private:
  int vertex;
  Node* next;

 public:
  Node();
  Node(int num);
  friend class Graph;
};

Node::Node() : vertex(0), next(NULL) {}

Node::Node(int num) : vertex(num), next(NULL) {}

#endif