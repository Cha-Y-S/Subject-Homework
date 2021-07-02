#ifndef __MYNODE_HPP__
#define __MYNODE_HPP__

#include <iostream>

using namespace std;

class Node {
 public:
  char data;
  int prio;
  Node* left;
  Node* right;

 public:
  Node();
  Node(char value);
};

Node::Node() : data(0), prio(0), left(NULL), right(NULL) {}

Node::Node(char value) : data(value), prio(4), left(NULL), right(NULL) {}

#endif