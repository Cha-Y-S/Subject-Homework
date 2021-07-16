#include <sstream>

#include "MyHeap.hpp"
#include "MyTree.hpp"

using namespace std;

int main() {
  int numInput;
  int value;
  Tree tree;

  cout << "Enter amount of input: ";

  cin >> numInput;

  cout << "Enter " << numInput << " data: ";

  for (int i = 0; i < numInput; i++) {
    cin >> value;
    tree.insertTree(value);
  }

  cout << "Print Tree:";
  tree.printTree();

  vector<int> tTree = tree.getTree();
  Heap heap(7);

  for (int i = 0; i < tTree.size(); i++) {
    heap.insertHeap(tTree[i]);
  }

  cout << "Min Heap: ";

  heap.printHeap();

  cout << "-----------------" << endl;
  cout << "| Menu\t\t|" << endl;
  cout << "| 1.Insert\t|" << endl;
  cout << "| 2.Delete\t|" << endl;
  cout << "| 3.Empty-test\t|" << endl;
  cout << "| 4.Full-test\t|" << endl;
  cout << "| 5.Level-test\t|" << endl;
  cout << "| 6.Exit Program|" << endl;
  cout << "-----------------" << endl;

  while (1) {
    cout << "Select Menu: ";
    cin >> value;

    switch (value) {
      case 1:
        cin >> value;
        heap.insertHeap(value);
        cout << "Insert: " << value << "\t\t";
        heap.printHeap();
        break;
      case 2:
        heap.deleteHeap();
        cout << "Delete\t\t\t: ";
        heap.printHeap();
        break;
      case 3:
        cout << "Empty test\t\t: ";
        if (heap.isEmpty())
          cout << "Heap is Empty" << endl;
        else
          cout << "Heap is not Empty" << endl;
        break;
      case 4:
        cout << "Full test\t\t :";
        if (heap.isFull())
          cout << "Heap is Full" << endl;
        else
          cout << "Heap is not Full" << endl;
        break;
      case 5:
        cout << "Level test\t\t: ";
        cout << heap.levelHeap() << endl;
        break;
      default:
        cout << "Exit Program" << endl;
        return 0;
        break;
    }
  }
  cout << endl;
}