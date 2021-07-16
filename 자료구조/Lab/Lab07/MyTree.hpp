#ifndef __MYTREE_HPP__
#define __MYTREE_HPP__

#include "MyNode.hpp"

class Tree {
 private:
  Node *root;
  char prec[4][2] = {'*', 2, '/', 2, '+', 1, '-', 1};

 private:
  void inorder(Node *node);
  void preorder(Node *node);
  void postorder(Node *node);
  void expression(Node *node);
  int evaluation(Node *node);

 public:
  Tree();
  ~Tree();
  bool isDigit(int value);
  bool isEmpty();
  void buildTree(char value);
  void insertOperand(Node *node);
  void insertOperator(Node *node);
  void inorder();
  void preorder();
  void postorder();
  void expression();
  int evaluation();
};

Tree::Tree() {
  this->root = NULL;
}

Tree::~Tree() {
  delete this->root;
}

bool Tree::isDigit(int value) {
  if (value == 4)
    return true;
  else
    return false;
}

bool Tree::isEmpty() {
  if (this->root == NULL)
    return true;
  else
    return false;
}

void Tree::buildTree(char value) {
  Node *temp = new Node(value);

  for (int i = 0; i < 4; i++) {
    if (temp->data == this->prec[i][0]) {
      temp->prio = this->prec[i][1] - '0';
      break;
    } else
      temp->prio = 4;
  }

  if (this->isDigit(temp->prio))
    insertOperand(temp);
  else
    insertOperator(temp);
}

void Tree::insertOperand(Node *node) {
  if (this->isEmpty())
    this->root = node;
  else {
    Node *p = this->root;
    while (p->right != NULL)
      p = p->right;
    p->right = node;
  }
}

void Tree::insertOperator(Node *node) {
  if (this->root->prio >= node->prio) {
    node->left = this->root;
    this->root = node;
  } else {
    node->left = this->root->right;
    this->root->right = node;
  }
}

void Tree::inorder(Node *node) {
  if (node) {
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }
}

void Tree::preorder(Node *node) {
  if (node) {
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }
}

void Tree::postorder(Node *node) {
  if (node) {
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
  }
}

void Tree::expression(Node *node) {
  if (node) {
    if (!this->isDigit(node->prio))
      cout << "( ";

    expression(node->left);
    cout << node->data << " ";
    expression(node->right);

    if (!this->isDigit(node->prio))
      cout << ") ";
  }
}

int32_t Tree::evaluation(Node *node) {
  int value, left, right;
  if (node) {
    if (this->isDigit(node->prio))
      value = node->data - '0';
    else {
      left = evaluation(node->left);
      right = evaluation(node->right);
      switch (node->data) {
        case '+':
          value = left + right;
          break;
        case '-':
          value = left - right;
          break;
        case '*':
          value = left * right;
          break;
        case '/':
          value = left / right;
          break;
      }
    }
  } else {
    cout << "Tree is empty" << endl;
    return 0;
  }
  return value;
}

void Tree::inorder() {
  this->inorder(this->root);
}

void Tree::preorder() {
  this->preorder(this->root);
}

void Tree::postorder() {
  this->postorder(this->root);
}

void Tree::expression() {
  this->expression(this->root);
}

int Tree::evaluation() {
  return this->evaluation(this->root);
}

#endif