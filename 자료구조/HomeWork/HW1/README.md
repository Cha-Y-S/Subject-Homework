# HW1: Array Exercise

## HW1-1 Problem: Sparse Matrix transpose

  - Read matrix A from datafile(hw1-1.txt) and store into array.

  - Transpose Matrix A into Matrix B

  - Printout Matrix B from the Array

  - 알고리즘: 강의노트 "Fast Transpose Algorithm" 사용할 것

### Input data: Matrix A

|       |  row  |  col  | value |
| :---: | :---: | :---: | :---: |
| total |   6   |   6   |   8   |
|       |   0   |   0   |  15   |
|       |   0   |   3   |  22   |
|       |   0   |   5   |  -15  |
|       |   1   |   1   |  11   |
|       |   1   |   2   |   3   |
|       |   2   |   3   |  -6   |
|       |   4   |   0   |  91   |
|       |   5   |   2   |  28   |

### Output: Matrix B

|       |  row  |  col  | value |
| :---: | :---: | :---: | :---: |
| total |   6   |   6   |   8   |
|       |   0   |   0   |  15   |
|       |   0   |   4   |  91   |
|       |   1   |   1   |  11   |
|       |   2   |   1   |   3   |
|       |   2   |   5   |  28   |
|       |   3   |   0   |  22   |
|       |   3   |   2   |  -6   |
|       |   5   |   0   |  -15  |

---

## HW1-2 Problem

  1. triangle, rectangle, circle의 각 제원을 데이터 파일로 받아, 구조체 배열에 저장

  2. 각 도형의 면적을 계산하여 구조체 배열에 저장

  3. 각 도형의 제원 및 면적 출력

### Data File: HW1-2.txt

  - 첫 번째 단어는 triangle, rectangle, circle 중 하나

  - 두 번째, 세 번째 단어는 각 도형의 제원

    - triangle: base, height(2개)

    - rectangle: side1, side2(2개)

    - circle: radius(1개)

  - 데이터 파일 hw1-2.txt

        triangle 20 40      
        rectangle 40 80
        circle 50
        rectangle 30 60
        triangle 10 20
        triangle 50 30
        circle 20

### Output

<pre>
triangle 20.00 40.00    400.00
rectangle 40.00 80.00   3200.00
circle 50.00            7850.00
rectangle 30.00 60.00   1800.00
triangle 10.00 20.00    100.00
triangle 50.00 30.00    750.00
circle 20.00            1256.00
</pre>

---

### Compile

  1. `g++ -o HW1-1 HW1-1.cpp`

  2. `g++ -o HW1-2 HW1-2.cpp`