#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int V = 6;
const vector<char> name = {'A', 'B', 'C', 'D', 'E', 'F'};

void printMatrix(vector<vector<int>> matrix);
int greedyMST(vector<vector<int>> matrix);
int primMST(vector<vector<int>> matrix);

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
}

int greedyMST(vector<vector<int>> matrix) {
}

int primMST(vector<vector<int>> matrix) {
}