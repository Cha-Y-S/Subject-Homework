# Lab 7: Tree Build, Traverse and Expression

### 검사 절차

Input: 2 + 4 * 3 -> Output: (2 + (4 * 3))

1. Node Creation:
   ```cpp
   class node{
     pulibc:
     char data;   // one character input per node ex) A
     int prio;    // priority number from precedence table
     node *left   // left link
     node *right  // right link
   }
   ```

2. Precedence Table
   ```cpp
   char prec[4][2] = {'*', 2, '/', 2, '+', 1, '-', 1};
   ```
   |   *   |   /   |   +   |   -   |
   | :---: | :---: | :---: | :---: |
   |   2   |   2   |   1   |   1   |

3. Main Program

   1. Get Math expression in numbers (ex: 2 + 4 * 3)

   2. Build Tree

   3. Traverse tree(Inorder, Preorder, Postorder)

   4. Tree Expression using Parentheses

  - Details

   1. Get Math expression(수식 입력): 키보드에서 입력

   2. Build Tree
  
  ```cpp
  while(input != NULL){
    create new-node
    assign DATA-INPUT into new-node's data field & default prio '4'
    for i = 0 to 4:
      if new-node->data == prec[i][0]
      then new-node->prio = prec[i][1]
      
      if i == 5
        then call Operand(new-node)
      else call operator(new-node)
  } endwhile

  Operande(new-node){
    if HEAD==NULL then HEAD = new-node return
    P = HEAD
    while(p->right != NULL) p = p->right
    p->right = new-node
  }

  Operator(new-node){
    if(head->prio >= new-node -> prio)
      new-node->left = HEAD
      HEAD = new-node
    else
      new-node->left = head->right
      head->right = new-node
  }
  ```
  
  3. Traverse(Tree traverse algorithm 참조): Inorder, Preorder, Postorder

  4. Tree Expression using Parentheses

  ```cpp
  Procedure parentheses(node){
    if(node != NULL){
        if(!isdigit(node->data)) cout << "(";

        parentheses(node->left);
        print node->data;
        parentheses(node->right);

        if(!isdigit(node->data)) cout << ")";
    }
  }
  ```