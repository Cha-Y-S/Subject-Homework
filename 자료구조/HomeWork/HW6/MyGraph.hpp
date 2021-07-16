#ifndef __MYGRAPH_HPP__
#define __MYGRAPH_HPP__

#include <climits>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph {
 private:
  int MAX;
  int V;
  vector<bool> found;
  vector<int> distance;
  vector<vector<int>> matrix;

 public:
  Graph();
  void initMatrix(const string filename);
  void printMatrix();
  void printDistance();
  void setShortestPath(int v);
  int chooseVertex();
};

Graph::Graph() {
}

void Graph::initMatrix(const string filename) {
  found.clear();
  distance.clear();
  matrix.clear();

  ifstream infile;
  infile.open(filename, ios::in);

  infile >> this->V;

  int max = INT_MIN;
  for (int i = 0; i < V; i++) {
    vector<int> input(V, -1);
    for (int j = 0; j < V; j++) {
      infile >> input[j];
      max = max < input[j] ? input[j] : max;
    }
    matrix.push_back(input);
  }
  this->MAX = max;

  for (int i = 0; i < V; i++) {
    found.push_back(false);
    distance.push_back(-1);
  }

  infile.close();
}

void Graph::printMatrix() {
  cout << "\t";
  for (int i = 0; i < V; i++) {
    cout << "V" << i << "\t";
  }
  cout << endl;

  for (int i = 0; i < V; i++) {
    cout << "V" << i << "\t";
    for (int j = 0; j < V; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

void Graph::printDistance() {
  for (int i = 0; i < distance.size(); i++)
    cout << distance[i] << "\t";
}

void Graph::setShortestPath(int v) {
  int u, w;

  for (int i = 0; i < V; i++) {
    found[i] = false;
    distance[i] = matrix[v][i];
  }

  found[v] = true;
  distance[v] = 0;

  cout << "Beginning Dist: \t";
  printDistance();
  cout << endl;

  for (int i = 0; i < V - 1; i++) {
    u = chooseVertex();
    found[u] = true;

    for (w = 0; w < V; w++) {
      distance[w] = !found[w] && (distance[u] + matrix[u][w] < distance[w]) ? distance[u] + matrix[u][w] : distance[w];
    }

    cout << "Select (" << u << ") Dist: \t";
    printDistance();
    cout << endl;
  }
}

int Graph::chooseVertex() {
  int min, minNode;
  min = MAX;

  for (int i = 0; i < V; i++) {
    if (distance[i] < min && !found[i]) {
      min = distance[i];
      minNode = i;
    }
  }

  return minNode;
}

#endif