#ifndef __MYNODE_HPP__
#define __MYNODE_HPP__

#include <iostream>

using namespace std;

class Node {
 public:
  char data;
  int prio;
  Node *left;
  Node *right;

 public:
  Node() : data(-1), prio(4), left(NULL), right(NULL) {}
  Node(char data) : data(data), prio(4), left(NULL), right(NULL) {}
};

#endif