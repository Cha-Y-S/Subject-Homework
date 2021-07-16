#ifndef __MYNODE_HPP__
#define __MYNODE_HPP__

#include <iostream>
#include <string>

using namespace std;

class Node {
 public:
  string name;
  int weight;
  int height;
  Node* prev;
  Node* next;

 public:
  Node() : name(NULL), weight(-1), height(-1) {
    this->prev = NULL;
    this->next = NULL;
  }
  Node(string name, int weight, int height) : name(name), weight(weight), height(height) {
    this->prev = NULL;
    this->next = NULL;
  }
};

#endif