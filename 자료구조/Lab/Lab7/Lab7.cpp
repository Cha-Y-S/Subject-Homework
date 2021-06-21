// Tree Build, Traverse and Expression - 20163162, Cha Yoonsung, Lab7
#include <fstream>

#include "MyTree.hpp"

using namespace std;

int main() {
  Tree tree;
  ifstream input;
  input.open("lab7.dat", ios::in);

  cout << "Math expression: ";
  while (true) {
    char value;
    input >> value;
    if (input.eof())
      break;
    tree.buildTree(value);
    cout << value << " ";
  }
  cout << endl;

  cout << "Preorder: ";
  tree.preorder();
  cout << endl;

  cout << "Inorder: ";
  tree.inorder();
  cout << endl;

  cout << "Postorder: ";
  tree.postorder();
  cout << endl;

  cout << "Expression: ";
  tree.expression();
  cout << endl;

  cout << "Evaluation: ";
  cout << tree.evaluation();
  cout << endl;

  return 0;
}