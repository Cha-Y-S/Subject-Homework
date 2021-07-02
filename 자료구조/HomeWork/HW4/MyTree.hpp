#ifndef __MYTREE_HPP__
#define __MYTREE_HPP__

#include "MyNode.hpp"

class Tree {
 private:
  Node *root;

 public:
  Tree();
  bool isEmpty();
  void inorder(Node *ptr);
  void postorder(Node *ptr);
  void preorder(Node *ptr);
  void buildTree(char input);
  void insertOperand(Node *ptr);
  void insertOperator(Node *ptr);
  void evalTree(Node *ptr);
  void drawTree(Node *ptr, int level);
  Node *getRoot();
};

Tree::Tree() : root(NULL) {}

bool Tree::isEmpty() {
  return this->root == NULL ? true : false;
}

void Tree::inorder(Node *ptr) {
  if (ptr) {
    inorder(ptr->left);
    cout << ptr->data << " ";
    inorder(ptr->right);
  }
}

void Tree::postorder(Node *ptr) {
  if (ptr) {
    postorder(ptr->left);
    postorder(ptr->right);
    cout << ptr->data << " ";
  }
}

void Tree::preorder(Node *ptr) {
  if (ptr) {
    cout << ptr->data << " ";
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

#endif