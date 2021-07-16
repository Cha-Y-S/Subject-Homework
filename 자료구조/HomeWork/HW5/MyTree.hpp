#ifndef __MYTREE_HPP__
#define __MYTREE_HPP__

#include <iostream>
#include <vector>

using namespace std;

class Tree {
 private:
  vector<int> arr;

 public:
  Tree();
  void insertTree(int value);
  void printTree();
  vector<int> getTree();
};

Tree::Tree() {
}

void Tree::insertTree(int value) {
  arr.push_back(value);
}

void Tree::printTree() {
  cout << "( ";
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << ")" << endl;
}

vector<int> Tree::getTree() {
  return arr;
}

#endif