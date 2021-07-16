# Lab 1: Recursion Test

## << Lab1-1: Binary Search(이진 탐색) >>

다음 2가지 조건으로 구하시오

조건:   1) Iterative version    2) Recursive version

  - 10개 데이터는 프로그램에서 다음과 같이 설정

    ex) int list[] = {10, 20, 30, 40, 50, 60, 70, 80, 90,100};

  - Search Number: 키보드 입력

  - 알고리즘: 강의노트

출력 예)
```cmd
Enter an integer to search: 30
Enter method of search: (1. Binary Search   2. Recursive binary search): 1
30 is at position 2

Enter an integer to search: 30
Enter method of search: (1. Binary Search   2. Recursive binary search): 2
30 is at position 2

Enter an integer to search: 33
Enter method of search: (1. Binary Search   2. Recursive binary search): 2
33 is NOT FOUND
```

---

## << Lab 1-2: Recursive 알고리즘으로만 구현할 것>>

Recursive Addition, Difference & Sum of a number 구하기

  - Addition:   N + M = (N - 1) + (M + 1) :
  
    At each step, subtract 1 from N

    And Add 1 to M, until N is 0,   then return M

<pre>
  예) 입력: 임의의 두 숫자 3, 4
  add(3, 4) -> add(2, 5) -> add(1, 6) -> add(0, 7)    Result = 7
</pre>

  - Difference:   N - M = (N - 1),  (M - 1)

    At each step, subtract 1 from both N & M

    until N is 0,   then return M

<pre>
  예) 입력: 임의의 두 숫자 3, 4
  Diff(3, 4) -> Diff(2, 3) -> Diff(1, 2) -> Diff(0, 1)    Result = 1
</pre>

  - Sum of a number

    Hint: Factorial의 순환 알고리즘을 덧셈으로 변환

<pre>
  예) 입력: 임의의 숫자 3 -> 출력: 3 + 2 + 1 = 6
</pre>


출력 예)
```cmd
Enter number 1: 3
Enter number 2: 4
  Addition Result is: 7
  Difference Result: 1

Enter a number: 3
  Result is:  3 + 2 + 1 = 6
```