# HW3: Singly Linked List Exercise

### purpose: To manipulate an ordered Signly linked list

### Tast: Write a program tath creates student roster list

&nbsp;&nbsp;&nbsp;&nbsp;Each student record in the roster list contains the **"student's name, ID number, major, grade"**

### Data 1

| Name  |  ID   | Major | Grade |
| :---: | :---: | :---: | :---: |
|   H   |  152  |  CS   |   B   |
|   C   |  182  |  EE   |   A   |
|   B   |  195  |  CS   |   A   |
|   G   |  250  |  HI   |   C   |
|   A   |  590  |  EE   |   A   |
|   D   |  812  |  CH   |   B   |
|   J   |  610  |  CS   |   A   |

### Data 2

| Name  |  ID   | Major | Grade |
| :---: | :---: | :---: | :---: |
|   F   |  150  |  EE   |   B   |
|   I   |  480  |  CS   |   A   |
|   K   |  100  |  EE   |   A   |

#### 문제:

  1. data1 파일을 읽어서, "이름(Name)"의 알파벳 오름차순(assending ordeR)으로 리스트를 만들어 출력하라.
    
      출력

      | Name  |  ID   | Major | Grade |
      | :---: | :---: | :---: | :---: |
      |   A   |  590  |  EE   |   A   |
      |   B   |  195  |  CS   |   A   |
      |   C   |  182  |  EE   |   A   |
      |   D   |  812  |  CH   |   B   |
      |   G   |  250  |  HI   |   C   |
      |   H   |  152  |  CS   |   B   |
      |   J   |  610  |  CS   |   A   |

  2. **1**에서 "A"성적을 받은 사람만 출력하라.

      출력

      | Name  |  ID   | Major | Grade |
      | :---: | :---: | :---: | :---: |
      |   A   |  590  |  EE   |   A   |
      |   B   |  195  |  CS   |   A   |
      |   C   |  182  |  EE   |   A   |
      |   J   |  610  |  CS   |   A   |

  3. data1 파일에 data2 파일을 합쳐서 이름의 알파벳순으로 새로운 리스트를 만들고, 그 중 <u>CS전공</u> 학생들만 출력하라.