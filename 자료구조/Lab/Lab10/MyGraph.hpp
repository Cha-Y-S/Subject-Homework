#ifndef __MYGRAPH_HPP__
#define __MYGRAPH_HPP__

#include <iostream>

#include "MyNode.hpp"

using namespace std;

class Graph {
 private:
  Node *head;
  Node *list;
  int size;
  int nVertex;
  int *parent;

 public:
  Graph(int size, int num);
  void initParent();
  void insert(Node *arr);
  void display();
  void sorting();
  bool checkContain();
  void kruskal();
  void printKruskal();
  int sumOfCost();
};

Graph::Graph(int size, int num) : head(NULL), size(size), list(new Node[size]), nVertex(num), parent(new int[nVertex]) {
}

void Graph::initParent() {
  for (int i = 0; i < nVertex; i++)
    parent[i] = i;
}

void Graph::insert(Node *arr) {
  for (int i = 0; i < size; i++)
    list[i] = arr[i];
}

void Graph::display() {
  for (int i = 0; i < size; i++)
    cout << list[i].v1 << " " << list[i].cost << " " << list[i].v2 << endl;
}

void Graph::sorting() {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (list[j].cost > list[j + 1].cost) {
        Node temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }
}

bool Graph::checkContain() {
  Node *p = head;
  int cnt = 0;
  while (p != NULL) {
    p = p->next;
    cnt++;
  }
  return cnt == nVertex - 1 ? true : false;
}

void Graph::kruskal() {
  sorting();
  initParent();
  int i = 0;

  while (!checkContain()) {
    if (parent[list[i].v1 - 65] < parent[list[i].v2 - 65]) {
      int find = parent[list[i].v2 - 65];
      for (int j = 0; j < size; j++) {
        if (parent[j] == find)
          parent[j] = parent[list[i].v1 - 65];
      }
      Node *temp = new Node(list[i].v1, list[i].v2, list[i].cost);
      if (head == NULL)
        head = temp;
      else {
        Node *p = head;
        while (p->next != NULL)
          p = p->next;
        p->next = temp;
      }
      i++;
    } else if (parent[list[i].v1 - 65] > parent[list[i].v2 - 65]) {
      int find = parent[list[i].v2 - 65];
      for (int j = 0; j < size; j++) {
        if (parent[j] == find)
          parent[j] = parent[list[i].v2 - 65];
      }
      Node *temp = new Node(list[i].v1, list[i].v2, list[i].cost);
      if (head == NULL)
        head = temp;
      else {
        Node *p = head;
        while (p->next != NULL)
          p = p->next;
        p->next = temp;
      }
      i++;
    } else
      i++;
  }
}

void Graph::printKruskal() {
  Node *p = head;
  if (!p)
    cout << "Empty" << endl;
  else {
    int i = 0;
    while (p != NULL) {
      cout << "Edge " << i + 1 << ": ";
      cout << p->v1 << " ";
      cout << p->cost << " ";
      cout << p->v2 << endl;

      p = p->next;
      i++;
    }
  }
}

int Graph::sumOfCost() {
  int sum = 0;
  Node *p = head;
  while (p != NULL) {
    sum += p->cost;
    p = p->next;
  }
  return sum;
}

#endif