#include "MyTree.hpp"

int main() {
  Tree tree;
  char input[100] = {0};

  cout << "Enter expression: ";

  cin >> input;

  int i = 0;
  while (input[i] != 0) {
    tree.buildTree(input[i]);
    i++;
  }

  cout << endl;
  cout << "  Inorder: ";
  tree.inorder(tree.getRoot());
  cout << endl;

  cout << endl;
  cout << "  Postorder: ";
  tree.postorder(tree.getRoot());
  cout << endl;

  cout << endl;
  cout << "  Preorder: ";
  tree.preorder(tree.getRoot());
  cout << endl;

  cout << endl;
  cout << "  Evaluation: ";
  cout << tree.evalTree(tree.getRoot()) << endl;

  cout << endl;
  cout << "  Tree Structure" << endl;
  cout << endl;
  tree.drawTree(tree.getRoot(), 1);
  cout << endl;

  return 0;
}