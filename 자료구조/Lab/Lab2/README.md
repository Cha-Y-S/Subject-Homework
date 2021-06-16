# Lab 1: Magic Square problem

magic square란, 1에서 n<sup>2</sup>까지의 정수로된 `n x n` 행렬로서, 각행의 합, 열의 합, 주 대각선의 합이 모두 같다. 또한 크기가 n이고, n은 홀수이다.

EX) Magic Square 3: 열, 행 및 주 대각선의 합이 15
|       |       |       |
| :---: | :---: | :---: |
|   6   |   1   |   8   |
|   7   |   5   |   3   |
|   2   |   9   |   4   |

  - 알고리즘

  ```cpp
  procedure magic(){
    int square[max][max], k, l;

    // sqaure를 0으로 초기화    // n = size of the square
    ...
    // i와 j는 현재 위치
    int key = 2;  // key값은 2부터 nxn까지 1씩 증가
    i = 0;  int j = n / 2;
    sqaure[i][j] = 1; // 첫 행의 중간에서 시작

    while(key <= n * n) { // 왼쪽 위방향, 대각선으로 이동
      if(i - 1 < 0) row = n - 1; else row = i - 1;
      if(j - 1 < 0) col = n - 1; else col = j - 1;

      if(sqare[row][col]) i = (i + 1) % n;  // square full, move down

      else{ i = row;  j = col;}

      square[i][j] = key++;
    } // end while

    // Print Magic Square
  }
  ```

### 조건

  1) 데이터 n: 키보드 입력 - 예) 크기가 5인 매직스퀘어

  2) 첫 번째 행의 중앙에 1을 넣는다

  3) 출력은 크기가 5일 경우 아래 테이블처럼 출력할 것

---

## << Extra Points >>

  1) 다항식의 표현:
  ```c
  typedef struct{
    float coef;
    int expon;
  } Polynomial;
  ```
  2) 테스트 데이터<br>
    
  -  A(X): 3x<sup>4</sup> + 5x<sup>2</sup> + 6x + 4

  |       |       |       |       |
  | :---: | :---: | :---: | :---: |
  |   3   |   5   |   6   |   4   |
  |   4   |   2   |   1   |   0   |
  
  - B(X): 5x<sup>3</sup> + 4<sup>2</sup> - 6x + 1

  |       |       |       |       |
  | :---: | :---: | :---: | :---: |
  |   5   |   4   |  -6   |   1   |
  |   3   |   2   |   1   |   0   |

  3) 출력: C(X): 3x<sup>4</sup> + 5x<sup>3</sup> + 9x<sup>2</sup> + 5

  |       |       |       |       |
  | :---: | :---: | :---: | :---: |
  |   3   |   5   |   9   |   5   |
  |   4   |   3   |   2   |   0   |