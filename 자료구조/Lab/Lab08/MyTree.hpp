#ifndef __MYTREE_HPP__
#define __MYTREE_HPP__

#include "MyNode.hpp"

template <typename T>
class Tree {
 private:
  Node<T>* root;

 private:
  Node<T>* insertTree(Node<T>* node, T value);
  Node<T>* deleteTree(Node<T>* node, T value);
  Node<T>* searchTree(Node<T>* node, T value);
  void preorder(Node<T>* node);
  void postorder(Node<T>* node);
  void inorder(Node<T>* node);
  int leafNode(Node<T>* node);
  void drawTree(Node<T>* node, int level);
  Node<T>* findMax(Node<T>* node);

 public:
  Tree();
  bool isEmpty();
  void insertTree(T value);
  void deleteTree(T value);
  void searchTree(T value);
  void preorder();
  void postorder();
  void inorder();
  int leafNode();
  void drawTree();
};

template <typename T>
Tree<T>::Tree() {
  cout << "Create Tree Instance with root NULL" << endl;
  this->root = NULL;
}

template <typename T>
bool Tree<T>::isEmpty() {
  return this->root == NULL ? true : false;
}

template <typename T>
Node<T>* Tree<T>::insertTree(Node<T>* node, T value) {
  if (node == NULL) {
    Node<T>* temp = new Node<T>(value);
    node = temp;
  } else if (value < node->data) {
    node->left = insertTree(node->left, value);
  } else {
    node->right = insertTree(node->right, value);
  }
  return node;
}

template <typename T>
Node<T>* Tree<T>::deleteTree(Node<T>* node, T value) {
  if (node != NULL) {
    if (value < node->data)
      node->left = deleteTree(node->left, value);
    else if (value > node->data)
      node->right = deleteTree(node->right, value);
    else if ((node->left == NULL) && (node->right == NULL))
      node = NULL;
    else if (node->left == NULL) {
      Node<T>* p = node;
      node = node->right;
      delete p;
    } else if (node->right == NULL) {
      Node<T>* p = node;
      node = node->left;
      delete p;
    } else {
      Node<T>* p = findMax(node->right);
      node->data = p->data;
      node->right = deleteTree(node->right, node->data);
    }
  } else {
    cout << "Not Found" << endl;
  }
  return node;
}

template <typename T>
Node<T>* Tree<T>::searchTree(Node<T>* node, T value) {
  if (node == NULL)
    return NULL;
  else {
    if (value == node->data)
      return node;
    else if (value < node->data)
      node = searchTree(node->left, value);
    else if (value > node->data)
      node = searchTree(node->right, value);
  }
  return node;
}

template <typename T>
void Tree<T>::preorder(Node<T>* node) {
  if (node) {
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }
}

template <typename T>
void Tree<T>::postorder(Node<T>* node) {
  if (node) {
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
  }
}

template <typename T>
void Tree<T>::inorder(Node<T>* node) {
  if (node) {
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }
}

template <typename T>
int Tree<T>::leafNode(Node<T>* node) {
  int count = 0;
  if (node == NULL)
    return count;
  else {
    if ((node->left == NULL) && (node->right == NULL))
      count++;
    else
      count = leafNode(node->left) + leafNode(node->right);
  }
  return count;
}

template <typename T>
void Tree<T>::drawTree(Node<T>* node, int level) {
  if ((node != NULL) && level <= 7) {
    drawTree(node->right, level + 1);
    for (int i = 1; i <= (level - 1); i++)
      cout << "    ";
    cout << node->data;
    if ((node->left != NULL) && (node->right != NULL))
      cout << "<" << endl;
    else if (node->right != NULL)
      cout << " / " << endl;
    else if (node->left != NULL)
      cout << "\\" << endl;
    else
      cout << endl;
    drawTree(node->left, level + 1);
  }
}

template <typename T>
Node<T>* Tree<T>::findMax(Node<T>* node) {
  if (node->right == NULL)
    return node;
  else
    findMax(node->right);
}

template <typename T>
void Tree<T>::insertTree(T value) {
  this->root = insertTree(this->root, value);
}

template <typename T>
void Tree<T>::deleteTree(T value) {
  this->root = deleteTree(this->root, value);
}

template <typename T>
void Tree<T>::searchTree(T value) {
  Node<T>* node = searchTree(this->root, value);
  if (node)
    cout << "Found" << endl;
  else
    cout << "Not Found" << endl;
}

template <typename T>
void Tree<T>::preorder() {
  preorder(this->root);
}

template <typename T>
void Tree<T>::inorder() {
  inorder(this->root);
}

template <typename T>
void Tree<T>::postorder() {
  postorder(this->root);
}

template <typename T>
int Tree<T>::leafNode() {
  return leafNode(this->root);
}

template <typename T>
void Tree<T>::drawTree() {
  drawTree(this->root, 1);
}

#endif