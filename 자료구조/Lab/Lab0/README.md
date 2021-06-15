# LAB 0: Basic Exercise

${*}$주의: program에 "이름, 학번, 프로그램ID(ex. Lab0) 표기할 것.

---

## << Lab0-1: File I/O 연습 >>

다음 데이터 파일에서 한 line씩 읽고 각 Line의 단어 개수를 출력하는 프로그램을 작성하시오

예) [Data File] 다음 데이터 파일 이름을 "lab0-1.dat"로 저장.

A program that translate a high level language to a machine language<br>
is called a compiler. A compiler is thus a somewhat peculiar sort<br>
of program and its output is yes another program. To avoid confusion,

[출력] 실행했을 경우, 다음과 같은 결과를 출력한다.

```sh
  /* 다음은 실행 결과임 */
  A program that translate a high level language to a machine language
    The number of words : 12
  is called a compiler. A compiler is thus a somewhat peculiar sort
    The number of words : 12
  of program and its ouput is yes another program. To avoid confusion,
    The number of words : 12
  
   Total Number of Word : 36
```

${*}$참조: Word Count 알고리즘

```c
  While(buffer is not empty) {
    Print One Line;
    WordCount(buffer, WC);
    Print Count(WC);
  }
  Print TotalWordCount;

  WordCount(buffer, WC){
    // Initialize pointer IN = 1, OUT = 0;  // 단어가 시작 시, state = IN
    int i = 0; int state = OUT;

    while(buffer[i] != '\0'){ // Until End of Line
      if(isalpha(buffer[i])){
          if(state == OUT){
            ++wc;
            state = IN;
          }  // 문자이고 state = IN이면 do nothing
      }
      else if(buffer[i] == '')
        state = OUT;
      i++;
    }
  }
```

  - C++ File IO 참조

```cpp
#include <iostream>
#include <fstream>    // for ifstream, open
#include <stdlib.h>   // for exit

using namespace std;

void main(){
  ifstream infile;
  char buffer[80];
  infile.open("lab1.txt", ios::in);
  if(infile.fail()){ cout << "can't open the input file" << endl; exit(1); }
  ...
  while(infile.getline(buffer, 80)){
    ...
  }
}
```

---

## << Lab 0-2: Find Min and Max numbers >>

  1) Data file: 10개의 정수로 구성한다.

    ex) // 프로그램 내 고정, file IO 필요없음.
    
        int data[] = {90, 40, 60, 10, 50, 80, 20, 70};
  
  2) Output

      Minimum number is 10 at position 4,

      Maximum number is 90 at position 1
      
  3) 알고리즘 참조
  
  ```cpp
    int min = data[0];

    for(int i = 1; i < n ; i++)
      if (data[i] < min)  min = data[i];
      if (data[i] > max)  max = data[i];
    
    return min;
  ```