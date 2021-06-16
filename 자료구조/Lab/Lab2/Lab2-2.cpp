// Polynomial Expression - 20163162, Cha Yoonsung, Lab2-2
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Poly {
  float coef;
  int expon;
};

class MyPoly {
 private:
  vector<Poly> terms;

 public:
  MyPoly(vector<Poly> term);
  MyPoly addPoly(MyPoly a);
  int compare(int x, int y);
  void printMyPoly();
};

MyPoly::MyPoly(vector<Poly> term) {
  this->terms = term;
}

MyPoly MyPoly::addPoly(MyPoly a) {
  vector<Poly> result;
  int i = 0;
  int j = 0;
  while (!(i == this->terms.size() || j == a.terms.size())) {
    int tExpon = this->terms[i].expon;
    int aExpon = a.terms[j].expon;
    switch (compare(tExpon, aExpon)) {
      case 1:
        result.push_back(this->terms[i]);
        i++;
        break;
      case -1:
        result.push_back(a.terms[j]);
        j++;
        break;
      case 0:
        float coefficient = this->terms[i].coef + a.terms[j].coef;
        Poly temp;
        temp.coef = coefficient;
        temp.expon = this->terms[i].expon;
        result.push_back(temp);
        i++;
        j++;
        break;
    }
  }
  return MyPoly(result);
}

int MyPoly::compare(int x, int y) {
  if (x > y)
    return 1;
  else if (x == y)
    return 0;
  else
    return -1;
}

void MyPoly::printMyPoly() {
  for (int i = 0; i < this->terms.size(); i++) {
    if (this->terms[i].coef != 0) {
      if (this->terms[i].expon == 0) {
        cout << this->terms[i].coef;
      } else {
        cout << this->terms[i].coef << "x^" << this->terms[i].expon;
      }
      if (i + 1 != this->terms.size()) cout << " + ";
    }
  }
  cout << endl;
}

int main() {
  ifstream input;
  input.open("lab2-2.dat", ios::in);

  vector<vector<Poly>> data;
  vector<Poly> aData;
  vector<Poly> bData;
  int i = 0;
  char escape;

  while (!input.eof()) {
    Poly temp;
    input >> temp.coef >> temp.expon;
    if (i == 0)
      aData.push_back(temp);
    else
      bData.push_back(temp);
    input.get(escape);
    if (escape == '\n') {
      i++;
      data.push_back(aData);
    }
  }

  data.push_back(bData);

  MyPoly a(data[0]);
  MyPoly b(data[1]);
  MyPoly result(a.addPoly(b));

  result.printMyPoly();

  return 0;
}