#include "MyTree.hpp"

int main() {
  Tree<int> tree;

  cout << "1) Delete: ";
  tree.deleteTree(20);

  cout << "2) Traverse: ";
  tree.inorder();
  cout << endl;

  cout << "3) Insert: ";
  tree.insertTree(30);
  tree.insertTree(40);
  tree.insertTree(20);
  tree.insertTree(10);
  tree.insertTree(50);
  cout << endl;
  tree.drawTree();

  cout << "4) Leaf: ";
  cout << tree.leafNode() << endl;

  cout << "5) Delete test\n"
       << endl;
  cout << " - Single Node Test -> delete 20" << endl;
  tree.deleteTree(20);
  tree.drawTree();
  cout << endl;
  cout << " - Leaf node Test -> delete 50" << endl;
  tree.deleteTree(50);
  tree.drawTree();
  cout << endl;
  cout << " - Both Side Node Test - > delete 30" << endl;
  tree.deleteTree(30);
  tree.drawTree();
  cout << endl;

  cout << "6) Search: 30\t";
  tree.searchTree(30);
  cout << "   Search: 10\t";
  tree.searchTree(10);
  cout << endl;

  cout << "7) Traverse" << endl;
  cout << " - inoder : ";
  tree.inorder();
  cout << "\t - postorder : ";
  tree.postorder();
  cout << "\t - preorder : ";
  tree.preorder();
  cout << endl;

  return 0;
}