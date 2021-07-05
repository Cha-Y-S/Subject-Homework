#ifndef __MYGRAPH_HPP__
#define __MYGRAPH_HPP__

#include "MyNode.hpp"

class Graph {
 private:
  const static int MAX = 8;
  Node* graph[MAX];
  bool visited[MAX];
  Node* front;
  Node* rear;

 public:
  Graph();
  void initGraph();
  void initVisited();
  void insert(int num1, int num2);
  void display();
  void enqueue(int v);
  int dequeue();
  void bfs(int v);
  void dfs(int v);
  int getMax();
};

Graph::Graph() : front(NULL), rear(NULL) {}

void Graph::initGraph() {
  for (int i = 0; i < MAX; i++)
    graph[i] = NULL;
}

void Graph::initVisited() {
  for (int i = 0; i < MAX; i++)
    visited[i] = 0;
}

void Graph::insert(int num1, int num2) {
  if (graph[num1] == NULL) {
    Node* temp = new Node(num1);
    graph[num1] = temp;
  }
  if (graph[num2] == NULL) {
    Node* temp = new Node(num2);
    graph[num2] = temp;
  }

  Node* p = graph[num1];
  Node* temp = new Node(num2);
  while (p->next != NULL)
    p = p->next;
  p->next = temp;

  p = graph[num2];
  temp = new Node(num1);
  while (p->next != NULL)
    p = p->next;
  p->next = temp;
}

void Graph::display() {
  for (int i = 0; i < MAX; i++) {
    if (graph[i] != NULL) {
      Node* p = graph[i];
      cout << "V" << i << ":\t";
      p = p->next;
      while (p->next != NULL) {
        cout << p->vertex << " -> ";
        p = p->next;
      }
      cout << p->vertex << endl;
    } else {
      cout << "V" << i << ":" << endl;
    }
  }
}

void Graph::enqueue(int v) {
  Node* temp = new Node(v);
  if (front == NULL) {
    front = temp;
    rear = temp;
  } else {
    rear->next = temp;
    rear = temp;
  }
}

int Graph::dequeue() {
  Node* p;
  int v;
  front = p->next;
  v = p->vertex;
  delete (p);
  return v;
}

void Graph::bfs(int v) {
  Node* p;
  enqueue(v);
  visited[v] = 1;
  cout << v << " ";

  while (front) {
    v = dequeue();
    for (p = graph[v]; p; p = p->next) {
      if (!visited[p->vertex]) {
        enqueue(p->vertex);
        visited[p->vertex] = 1;
        cout << p->vertex << " ";
      }
    }
  }
}

void Graph::dfs(int v) {
  Node* p;
  visited[v] = 1;
  cout << "v" << v;

  for (p = graph[v]; p; p = p->next) {
    if (!visited[p->vertex]) {
      cout << " -> ";
      dfs(p->vertex);
    }
  }
}

int Graph::getMax() {
  return MAX;
}

#endif