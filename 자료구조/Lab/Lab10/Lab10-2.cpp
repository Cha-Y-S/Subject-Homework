#include <fstream>
#include <iostream>

#include "MyGraph.hpp"
#include "MyNode.hpp"

using namespace std;

int main() {
  ifstream infile;
  infile.open("Lab10-2.dat", ios::in);

  int nEdge, nVertex;

  infile >> nEdge >> nVertex;

  Graph graph(nEdge, nVertex);
  Node *arr = new Node[nEdge];

  for (int i = 0; i < nEdge; i++)
    infile >> arr[i].v1 >> arr[i].cost >> arr[i].v2;

  graph.insert(arr);

  cout << "Original Data" << endl;
  graph.display();
  cout << endl;

  graph.kruskal();

  cout << "Sorted Data" << endl;
  graph.display();
  cout << endl;

  cout << "Kruskal's MST" << endl;
  graph.printKruskal();
  cout << endl;

  int cost = graph.sumOfCost();

  cout << "Total Cost: " << cost << endl;

  return 0;
}