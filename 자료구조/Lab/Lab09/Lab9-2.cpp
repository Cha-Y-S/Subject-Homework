#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int V = 6;

void printMatrix(vector<vector<int>> matrix);
void bfs(vector<vector<int>> matrix, int v);

int main() {
  vector<vector<int>> matrix;
  ifstream infile;
  infile.open("Lab9-2.dat", ios::in);

  // Initialize matrix with data file
  while (!infile.eof()) {
    vector<int> temp(6, -1);
    for (int i = 0; i < V; i++) {
      infile >> temp[i];
    }
    matrix.push_back(temp);
  }

  printMatrix(matrix);

  cout << endl;

  bfs(matrix, 0);

  return 0;
}

void printMatrix(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    cout << "\t";
    cout << "V" << i;
  }
  cout << endl;

  for (int i = 0; i < matrix.size(); i++) {
    cout << "V" << i << "\t";
    for (int j = 0; j < matrix.size(); j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void bfs(vector<vector<int>> matrix, int v) {
  vector<bool> visited(matrix.size(), false);
  queue<int> q;

  q.push(v);
  visited[v] = true;

  cout << "Breadth First Search(BFS): ";

  while (!q.empty()) {
    int front = q.front();
    q.pop();

    cout << "V" << front;

    if (!q.empty() || front == v) {
      cout << " -> ";
    }

    for (int i = 0; i < matrix.size(); i++) {
      if (!visited[i] && matrix[front][i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
  cout << endl;
}