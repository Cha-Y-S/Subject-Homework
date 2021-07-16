#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int V = 6;
const vector<char> name = {'A', 'B', 'C', 'D', 'E', 'F'};

void printMatrix(vector<vector<int>> matrix);
bool isAllNodeVisited(vector<bool> visited);
void greedyMST(vector<vector<int>> matrix);
void primMST(vector<vector<int>> matrix);

int main() {
  vector<vector<int>> matrix;
  ifstream infile;
  infile.open("Lab10-1.dat", ios::in);

  while (!infile.eof()) {
    vector<int> input(V, -1);
    infile >> input[0] >> input[1] >> input[2] >> input[3] >> input[4] >> input[5];
    matrix.push_back(input);
  }

  cout << "1. Weighted Graph" << endl;
  printMatrix(matrix);

  cout << "2. Minimal Spanning Tree(Greedy Algorithm)" << endl;
  greedyMST(matrix);

  cout << "3. Revised Prim's Algorithm" << endl;
  primMST(matrix);

  return 0;
}

void printMatrix(vector<vector<int>> matrix) {
  cout << "\tA\tB\tC\tD\tE\tF" << endl;
  for (int i = 0; i < matrix.size(); i++) {
    cout << name[i] << "\t";
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

bool isAllNodeVisited(vector<bool> visited) {
  bool result = true;
  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      result = false;
      break;
    }
  }
  return result;
}

void greedyMST(vector<vector<int>> matrix) {
  int weight = 0;
  vector<bool> visited(V, false);
  int select = 0;
  visited[select] = true;

  cout << "MST: ";
  while (!isAllNodeVisited(visited)) {
    int sWeight = INT_MAX;
    int node = select;
    for (int i = 0; i < matrix[select].size(); i++) {
      // Find that be not visited && connective node
      if (!visited[i] && (0 < matrix[select][i] && matrix[select][i] < 100)) {
        // Greedy Choice
        if (sWeight > matrix[select][i]) {
          sWeight = matrix[select][i];
          node = i;
        }
      }
    }

    cout << "(" << name[select] << ", " << name[node] << ")";
    weight += matrix[select][node];
    select = node;
    visited[select] = true;
    if (!isAllNodeVisited(visited)) {
      cout << " -> ";
    }
  }
  cout << "\nWeight: " << weight << "\n"
       << endl;
}

void primMST(vector<vector<int>> matrix) {
  vector<bool> visited(V, false);

  visited[0] = true;

  int eCnt = 0;
  int weight = 0;

  cout << "MST: ";
  while (eCnt < V - 1) {
    int min = INT_MAX;
    int v1 = -1;
    int v2 = -1;
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if ((visited[i] && !visited[j]) || (!visited[i] && visited[j])) {
          if (0 < matrix[i][j] && matrix[i][j] < 100) {
            if (matrix[i][j] < min) {
              min = matrix[i][j];
              v1 = i;
              v2 = j;
            }
          }
        }
      }
    }

    if (v1 != -1 && v2 != -1) {
      cout << "(" << name[v1] << ", " << name[v2] << ")";
      weight += min;
      visited[v2] = visited[v1] = true;
      eCnt++;
    }

    if (eCnt < V - 1) {
      cout << " -> ";
    }
  }
  cout << "\nWeight: " << weight << "\n"
       << endl;
}