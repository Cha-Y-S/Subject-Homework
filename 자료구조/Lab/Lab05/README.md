# Lab 5-1: Singly Linked List 연습

### Main Program:

1. 메뉴

       1. insert        2. delete       3. list       4. search
       2. PrintLast     6. PrintNth     7. InvertList 8. Quit

2. Quit 선택할 때까지 계속할 것

3. Node의 구성(2개의 filed: data, link)

### Singly Linked-List ADT

1. Insert: 새로운 숫자 입력 시, 숫자값에 따라 오름차순으로 list에 삽입

    1. head == NULL => 새로운 노드 생성
     
    2. (head != NULL & new number < head->num) => head 이동

    3. (head != NULL & new number > head->num) => 전체리스트 검색 후 적합한 장소에 삽입

2. Delete: delete할 노드의 number 값으로 해당 노드를 찾아서 삭제할 것

    1. head == NULL => "리스트 empty"출력

    2. (head != NULL & (number == head->num)) => head 이동

    3. (head != NULL & (number != head->num)) => 전체리스트 검색 후 해당노드를 삭제. 못 찾을 경우 "not found" 출력.

3. List: head노드가 NULL이면, print "List empty" 아니면, 리스트의 전체 노드들을 출력(p->num)

4. Search: 찾고 싶은 노드의 숫자를 입력 받음. 해당 숫자의 리스트에 존재 여부를 출력

    ex) 10 is in the list 또는 10 is not in the list

5. PrintLast: Head가 NULL이면 print "List Empty"아니면, 리스트의 마지막 노드만 출력

6. PrintNth: Head가 NULL이면 print "List Empty"아니면, 리스트의 N번째 노드만 출력

7. InverList: Head가 NULL이면 print "List Empty" 아니면, 리스트의 마지막 노드부터 처음 노드까지 출력

8. Quit: 리스트의 모든 노드들을 free 시켜야 함

#### << TEST 예 >>

|                             입력 | 출력             |
| -------------------------------: | :--------------- |
|                        Delete 10 | not found        |
| -> insert 10 -> insert 5 -> list | list: 5 10       |
|         -> insert 30 -> search 5 | 5 is in the list |
|              -> delete 5 -> list | list: 10 30      |
|                    -> Find3rd -> | not found        |
|                  -> PrintLast -> | 30               |
|       -> insert 40 -> invertList | List: 40 30 10   |
|                          ->quit; |                  |


# Lab 5-2: Linked Stack and Queue

  1. 문제: Stack과 Queue를 함께 사용하여 "abcde"를 입력하고, "ebcda"를 출력하는 program을 Linked List로 구현하시오

  2. ADT: PUSH, POP, ENQUEUE, DEQUE, Display(), Concatenate(head1, head2), INVERT(head)

  3. 수행순서:
  
     - List1: push 'a' -> push 'e'하여 List1 생성 후 출력

     - List 2: enque 'b' -> enque 'c' -> enque 'd'하여 List2 생성 후 출력

     - List1과 List2를 합쳐 오름차순의 리스트 List3생성 후 출력할 것(concatenate 함수 사용할 것)

     - List3를 역순으로 만들어 List4생성 후 출력할 것 (Invert함수 사용)

*검사: 다음 순서대로 실행한 후 결과를 검사.

  1. Display List1(Linked Stack의 내용을 출력)

  2. Display List2(Linked Queue의 내용을 출력)

  3. Display List3(List1과 List2가 합쳐진 새로운 리스트 출력)

  4. Display List4(List3를 역으로 만든 Invert List인 List4를 출력 - Linked Stack 사용)

*출력)
     
  - List1: e a

  - List2: b c d

  - List3: a b c d e

  - List4: e d b c a


### 컴파일

```cmd
// Lab5-1
g++ -o Lab5-1 MyNode.hpp MyStack.hpp  MyLinkedList.hpp Lab5-1.cpp

// Lab5-2
g++ -o Lab5-2 Lab5-2.cpp MyLinkedList.hpp MyLinkedQueue.hpp MyLinkedStack.hpp MyNode.hpp MyStack.hpp
```