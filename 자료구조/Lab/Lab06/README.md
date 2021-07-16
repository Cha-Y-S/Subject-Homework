# Lab 6: Doubly Linked List Exercise

### Requirement

  1. Menu
  <pre>
   1. Insert-after(n<sup>th</sup>)    2. Delete
   2. Forward              4. Backward
   3. Search               6. Find-n<sup>th</sup>
  </pre>

  2. Insert-after는 Find-n<sup>th</sup>를 먼저 한 다음 실행됨
    
     - n번째 노드 다음에 insert

  3. 입력데이터는 이름 오름차순으로 리스트 만들어서 저장 (key: name)

### Input Data

| name  | weight | height |
| :---: | :----: | :----: |
|  kim  |   72   |  185   |
|  lee  |   75   |  175   |
| choi  |   69   |  178   |
| song  |   51   |  162   |

 - 위의 데이터를 파일로 저장하여 사용

### <<검사 절차(Tesing procedure)>>

1. Forward List

| name  | weight | height |
| :---: | :----: | :----: |
| choi  |   69   |  178   |
|  kim  |   72   |  185   |
|  lee  |   75   |  175   |
| song  |   51   |  162   |

2. Search "Lee" -> Found

3. Delete "Lee"

| name  | weight | height |
| :---: | :----: | :----: |
| choi  |   69   |  178   |
|  kim  |   72   |  185   |
| song  |   51   |  162   |

4. Insert-after(2<sup>nd</sup>) data: Park 73 176

| name  | weight | height |
| :---: | :----: | :----: |
| choi  |   69   |  178   |
|  kim  |   72   |  185   |
| park  |   73   |  176   |
| song  |   51   |  162   |

5. Find 2<sup>nd</sup>

| name  | weight | height |
| :---: | :----: | :----: |
|  kim  |   72   |  185   |

6. Backward List

| name  | weight | height |
| :---: | :----: | :----: |
| song  |   51   |  162   |
| park  |   73   |  176   |
|  kim  |   72   |  185   |
| choi  |   69   |  178   |

### Compile Command

g++ -o Lab6 MyNode.hpp MyDoubleLinkedList.hpp Lab6.cpp