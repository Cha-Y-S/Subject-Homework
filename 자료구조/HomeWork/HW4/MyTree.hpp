#ifndef __MYTREE_HPP__
#define __MYTREE_HPP__

#include "MyNode.hpp"

class Tree {
 private:
  Node *root;
  const char prec[4][2] = {'*', 2, '/', 2, '+', 1, '-', 1};

 public:
  Tree();
  bool isEmpty();
  void inorder(Node *ptr);
  void postorder(Node *ptr);
  void preorder(Node *ptr);
  void buildTree(char input);
  void insertOperand(Node *ptr);
  void insertOperator(Node *ptr);
  int evalTree(Node *ptr);
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

void Tree::buildTree(char input) {
  Node *temp = new Node(input);

  for (int i = 0; i < 4; i++) {
    if (temp->data == this->prec[i][0]) {
      temp->prio = this->prec[i][1] - '0';
      break;
    } else {
      temp->prio = 4;
    }
  }

  if (temp->prio == 4) {
    insertOperand(temp);
  } else {
    insertOperator(temp);
  }
}

void Tree::insertOperand(Node *ptr) {
  Node *p = NULL;
  if (isEmpty()) {
    this->root = ptr;
  } else {
    p = root;
    while (p->right != NULL)
      p = p->right;
    p->right = ptr;
  }
}

void Tree::insertOperator(Node *ptr) {
  if (this->root->prio >= ptr->prio) {
    ptr->left = this->root;
    this->root = ptr;
  } else {
    ptr->left = this->root->right;
    this->root->right = ptr;
  }
}

int Tree::evalTree(Node *ptr) {
  int value, left, right;
  if (!isEmpty()) {
    if (ptr->left == 0 && ptr->right == 0)
      value = ptr->data - '0';
    else {
      left = evalTree(ptr->left);
      right = evalTree(ptr->right);
      switch (ptr->data) {
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
    cout << "Tree is Empty" << endl;
    return 0;
  }

  return value;
}

void Tree::drawTree(Node *ptr, int level) {
  if (ptr != NULL) {
    drawTree(ptr->right, level + 1);
    for (int i = 1; i <= level - 1; i++)
      cout << "    ";
    cout << ptr->data;
    if (ptr->left != NULL && ptr->right != NULL)
      cout << " < " << endl;
    else if (ptr->right != NULL)
      cout << " / " << endl;
    else if (ptr->left != NULL)
      cout << "\\" << endl;
    else
      cout << endl;
    drawTree(ptr->left, level + 1);
  }
}

Node *Tree::getRoot() {
  return root;
}

#endif