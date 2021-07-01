#include <fstream>

#include "MyList.hpp"

using namespace std;

int main() {
  char name, grade;
  int id;
  string major;
  List a;
  List b;
  List c;

  ifstream infile;
  infile.open("HW3-1.dat", ios::in);

  if (infile.fail()) {
    cout << "Cannot open the input file" << endl;
    exit(1);
  }

  while (infile >> name >> id >> major >> grade) {
    a.insertList(name, id, major, grade);
  }

  infile.close();

  infile.open("HW3-2.dat", ios::in);

  if (infile.fail()) {
    cout << "Cannot open the input file" << endl;
    exit(1);
  }

  while (infile >> name >> id >> major >> grade) {
    b.insertList(name, id, major, grade);
  }

  cout << "----- Solution 1 -----" << endl;
  a.displayList();
  cout << endl;

  cout << "----- Solution 2 -----" << endl;
  a.searchGrade('A');
  cout << endl;

  cout << "----- Solution 3 -----" << endl;
  c = c.mergeList(a, b);
  c.searchMajor("CS");
  cout << endl;

  return 0;
}