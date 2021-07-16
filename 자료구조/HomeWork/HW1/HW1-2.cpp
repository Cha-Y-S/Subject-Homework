/*
* Name: Cha Yoonsung
* Student Id: 20163162
* Program Id: Hw 1-2
* Description: 도형의 이름과 변의 길이 or 반지름을 데이터로 가지는 파일을 입력 받아 각 도형의 넓이를 구하는 프로그램
* Algorithm
*   - Data를 불러와 circle일 경우 2, triangle인 경우 1, rectangle인 경우 0을 반환하도록 하여
*     각 case별로 변의 길이 or 반지름을 구조체 변수에 대입한 후 area 산출
* Variables
*   - fig: 구조체 벡터
*   - name: 도형의 이름           - radius: 원의 반지름
*   - aSide, bSide: 두 변의 길이  - area: 도형의 넓이
*/
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Figure {
  string name;
  double aSide;
  double bSide;
  double radius;
  double area;
  Figure(string n, double a, double b) : name(n), aSide(a), bSide(b) {}
  Figure(string n, double r) : name(n), radius(r) {}
};

int main() {
  vector<Figure> fig;

  ifstream infile;
  infile.open("HW1-2.dat", ios::in);

  if (infile.fail()) {
    cout << "Cannot open the input file" << endl;
    exit(1);
  }

  cout << fixed;
  cout.precision(2);

  while (!infile.eof()) {
    string name;
    infile >> name;
    switch (name == "circle" ? 2 : (name == "triangle" ? 1 : 0)) {
      case 2: {
        double radius;
        infile >> radius;
        Figure temp(name, radius);
        temp.area = pow(temp.radius, 2) * 3.14;
        fig.push_back(temp);
        break;
      }
      case 1: {
        double a, b;
        infile >> a >> b;
        Figure temp(name, a, b);
        temp.area = (temp.aSide * temp.bSide) / 2;
        fig.push_back(temp);
        break;
      }
      case 0: {
        double a, b;
        infile >> a >> b;
        Figure temp(name, a, b);
        temp.area = temp.aSide * temp.bSide;
        fig.push_back(temp);
        break;
      }
    }
  }

  infile.close();

  for (int i = 0; i < fig.size(); i++) {
    if (fig[i].name == "circle")
      cout << fig[i].name << " " << fig[i].radius << "\t\t" << fig[i].area << endl;
    else
      cout << fig[i].name << " " << fig[i].aSide << " " << fig[i].bSide << "\t" << fig[i].area << endl;
  }

  return 0;
}