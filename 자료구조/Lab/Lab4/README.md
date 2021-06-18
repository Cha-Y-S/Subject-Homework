# Lab 3: Stack and Queue Practice

Stack과 Queue를 함께 사용하여 "abcde"를 순서대로 입력하고 "ebcda"를 순서대로 출력하는 program을 다음 10개의 ADT를 작성하여 완성하라.

<p align="center">S: Stack,&emsp;&emsp;Q: Queue,&emsp;&emsp;ch: character</p>

### ADT
#### PUSH, POP, StackFull, StackEmpty, DisplayStack,
#### ENQUEUE, DEQUE, QueueFull, QueueEmpty, DisplayQ,
#### C-Enque, C-Deque, display-CQ
<br>
*조건: Stack size 2, Queue size 3으로 구성.

*검사: 다음 명령들을 순서대로 main 프로그램에 작성할 것

1. [push 'a' enque 'b', enque 'c', enque 'd', push 'e']

2. [push 'F', enque 'G']
   
3. display-Stack

4. display-Queue

5. [pop, deque, deque, deque, pop]

6. [pop, deque]

7. C-Enque 'A', C-Enque 'B', C-Enque 'C', C-Deque, C-Enque 'D'

8. Display CircularQueue

9. C-Deque, C-Deque, C-Deque

### <p align="center">최종 출력 내용</p>

<p align = "center">
Stack Full,&emsp;&emsp;&emsp;QueueFull,&emsp;&emsp;&emsp;&emsp;&nbsp;// 2번 수행결과<br>
Stack: e, a&emsp;&emsp;&emsp;Queue: b, c, d&emsp;&emsp;&emsp;// 3, 4번 수행 결과<br>
Output: e b c d a&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;// 5번 수행 결과<br>
StackEmpty,&emsp;&emsp;&emsp;QueueEmpty&emsp;&emsp;&ensp;// 6번 수행 결과<br>
QueueFull&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;// 7번 수행 결과<br>
B, C&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&nbsp;// 8번 수행 결과<br>
QueueEmpty&ensp;&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;// 9번 수행 결과
</p>