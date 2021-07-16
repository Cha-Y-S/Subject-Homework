#ifndef __MYNODE_HPP__
#define __MYNODE_HPP__

#include <iostream>
#include <string>

using namespace std;

class Node {
 public:
  char name;
  int id;
  string major;
  char grade;
  Node *next;

 public:
  Node();
  Node(char value, int num, string str, char chr);
};

Node::Node() : name(0), id(0), major(NULL), grade(0), next(NULL) {}

Node::Node(char value, int num, string str, char chr) : name(value), id(num), major(str), grade(chr), next(NULL) {}

#endif