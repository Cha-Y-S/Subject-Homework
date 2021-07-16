#include <iostream>
#include <string>

#include "MyGraph.hpp"

using namespace std;

int main() {
  Graph g;

  cout << "Test case 1" << endl;
  g.initMatrix("HW6_1.dat");

  cout << "1) Print Cost Matrix" << endl;
  g.printMatrix();

  cout << "2) Shortest Path" << endl;
  g.setShortestPath(0);

  cout << endl;

  cout << "Test case 2" << endl;
  g.initMatrix("HW6_2.dat");

  cout << "1) Print Cost Matrix" << endl;
  g.printMatrix();

  cout << "2) Shortest Path" << endl;
  g.setShortestPath(4);

  return 0;
}