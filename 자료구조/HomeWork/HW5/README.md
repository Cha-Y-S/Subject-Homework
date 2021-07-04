# HW5: MIN HEAP implementation

### ADT:

  - insert HEAP: 데이터 삽입

  - delete HEAP: 데이터 삭제(top element만 삭제)

  - Empty HEAP: Boolean 함수

  - Full HEAP: Boolean 함수

  - Print HEAP: Heap의 내용을 출력
    
    (배열의 크기는 7)

### 1. Main Program

  - Menu 구성(1. Insert, 2. Delete, 3. Empty, 4. Full, 5. Quit)

  1. 임의의 5숫자 (예: 9 2 5 3 8)를 사용하여, binray tree 구성 후 출력할 것

      -> **(9 2 5 3 8)**
  
  2. Binary Tree의 데이터를 한 개씩 insert 하여 MINHEAP 구성 후 출력할 것

      -> **(2 3 5 9 7)**

  3. MINHEAP 구성 후에는 다음과 같이 테스트 할 것

  <div align = center>

  |    command     |       출력        |
  | :------------: | :---------------: |
  | 4) Empty test  | Heap is not Empty |
  |  5) Insert 1   |   (1 3 2 9 8 5)   |
  |  6) Insert 7   |  (1 3 2 9 8 5 7)  |
  | 7) Full 테스트 |   Heap is full    |
  |   8) Delete    |   (2 3 5 9 8 7)   |
  | 9) Level test  |         3         |

  </div>

### 2. Algorithm(See lectrue Note)

<br />

### Compile

```cmd
> g++ -o HW3 MyNode.hpp MyList.hpp HW3.cpp
```