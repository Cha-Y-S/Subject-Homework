#include <fstream>

#include "MyGraph.hpp"

int main() {
  Graph g;
  g.initGraph();
  g.initVisited();

  ifstream infile;
  infile.open("Lab9-1.dat");

  int num1, num2;

  for (int i = 0; i < g.getMax(); i++) {
    infile >> num1 >> num2;
    g.insert(num1, num2);
  }

  cout << "Graph data" << endl;

  g.display();
  cout << endl;
  cout << "Depth First Search Output(starting from v0)" << endl;
  g.dfs(0);
  cout << endl;

  infile.close();
  return 0;
}