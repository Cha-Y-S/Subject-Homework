// File I/O practice - Cha Yoonsung, 20163162, Lab0-1
#include <fstream>
#include <iostream>

using namespace std;

int wordCount(char *buffer);

int main() {
  ifstream infile;
  char buffer[80];
  int total = 0;
  infile.open("lab0-1.dat", ios::in);
  if (infile.fail()) {
    cout << "can't open the input file" << endl;
    exit(1);
  }

  while (infile.getline(buffer, 80)) {
    total += wordCount(buffer);
    int i = 0;

    while (buffer[i] != '\0') {
      cout << buffer[i];
      i++;
    }

    cout << "\n\tThe number of words  " << wordCount(buffer) << endl;
  }

  cout << "Total Number of Words : " << total << endl;
}

int wordCount(char *buffer) {
  int i = 0;
  int wc = 0;
  bool state = false;
  // if word start, state = IN

  while (buffer[i] != '\0') {  // Until end of Line
    if (buffer[i]) {
      if (!state) {
        ++wc;
        state = true;
      }  // if buffer[i] is text and state is true, do nothing
      else if (buffer[i] == ' ')
        state = false;
    }
    i++;
  }
  return wc;
}