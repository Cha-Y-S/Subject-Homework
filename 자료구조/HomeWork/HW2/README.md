# HW2: Infix-to-Postfix conversion & Evaluation

## Step

  1. 데이터 파일에서 입력 받은 수식을 화면에 다시 한번 출력

  2. infix-to-postfix algorithm에 의해 conversion한 후 postfix form을 출력

  3. postfix evalutation algorithm을 이용하여 최종값 출력

### Output Sample

  1. Echo data  (infix form): 3 + 2

  2. Conversion (postfix form): 3 2 +

  3. Result: 5

### Hint

  - infix form은 9미만의 십진수를 infix 형태로 표현한 것을 이용(ex. 3 + 2)

  - 사칙연산만을 사용(ex. +, -, /, *)

  - Operator는 "(", "-", "+", "/", "*", ")"로 한정

    - 알고리즘 강의노트 참조

---

### Compile

  1. `g++ -o HW1-1 HW1-1.cpp`

  2. `g++ -o HW1-2 HW1-2.cpp`