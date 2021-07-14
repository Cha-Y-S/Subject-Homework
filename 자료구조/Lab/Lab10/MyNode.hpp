#ifndef __MYNODE_HPP__
#define __MYNODE_HPP__

#include <iostream>

using namespace std;

class Node {
 public:
  char v1;
  char v2;
  int cost;
  Node *next;

 public:
  Node();
  Node(char v1, char v2, int cost);
};

Node::Node() : v1(-1), v2(-1), cost(-1), next(NULL) {}

Node::Node(char v1, char v2, int cost) : v1(v1), v2(v2), cost(cost), next(NULL) {}

#endif