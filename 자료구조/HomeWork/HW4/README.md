# HW4: Tree Build, Traverse and Evaluation

### 1. Node Creation

```cpp
class node{
public:
  char data;    // one character input per node ex) A
  int prio;     // priority number from precedence table
  node *left;   // left link
  node *right;  // right link
}
```

### 2. Precedence Table

```cpp
char prec[4][2] = {'*', 2, '/', 2, '+', 1, '-', 1};
```
<div align = center>

|   *   |   /   |   +   |   -   |
| :---: | :---: | :---: | :---: |
| **2** | **2** | **1** | **1** |

</div>

### 3. Main program

  1. Get math expression in numbers (ex: 2 + 4 * 3)

  2. Build Tree ==> same as Lab#7

  3. Evaluate the expression and prints the results

  4. Draw the Tree

### 4. Details

  1. Get math expression(수식 입력): 키보드에서 입력

  2. Build Tree

      - 알고리즘: 강의노트 참조

  3. Traverse(Tree traverse algorithm 참조)

      - Inorder, Preorder, Postorder

  4. Evaluation of the expression

      - 알고리즘: 강의노트 참조

  5. Draw Tree

      ``` cpp
      Procedure DrawTree(Node *p, int level){ // start level as 1
        if (p != NULL){
          DrawTree(p->right, level + 1);

          for(i = 1; i < level - 1; i++)  print "    "; // 오른쪽으로 빈 공간 출력

          print p->data     // 데이터 출력

          if (p->left != NULL && p->right != NULL) print "    < ";

          else if (p->right != NULL) print " / ";

          else if (p->left != NULL) print " "\" ";

          DrawTree(p->left, level + 1);
        }
      }
      ```

  - 검사 절차 예시: Input - 2 + 4 * 3
  
  <div align = center>

  ![image](https://user-images.githubusercontent.com/24904962/124175141-34522a80-dae8-11eb-8e9c-e6ddd5545b41.png)

  </div>

### Compile

```cmd
> g++ -o HW3 MyNode.hpp MyList.hpp HW3.cpp
```