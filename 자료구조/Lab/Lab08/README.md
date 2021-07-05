# Lab 8: Binary Search Tree

### Main Program

  1. Menu 구성

    1. Insert   5. Traverse
    2. Delete   6. Leaf
    3. Search   7. Quit
    4. Print

  2. For each command:
    
     - Insert
      
      ```cpp
      "Enter number to insert: "
      insert_tree(Num)
      ```

     - Delete

     ```cpp
     if(!tree empty()) "Enter number to delete: " delete_tree(Num)
     else "Tree is empty"
     ```

     - Search

     ```cpp
     if(!tree_empty()) "Enter number to search: " temp = search_tree(root, Num)
      if(temp == NULL) "NOT found" else "number is found"
     else "Tree is empty"
     ```

     - Traverse

     ```cpp
     if(!tree_empty()) inorder/preorder/postorder();
     else "Tree is empty"
     ```

     - Leaf(node)
     
     ```cpp
     // if tree is empty then return cout 0;
     if(node->left == NULL) && (node->right == NULL) count++;
     else count = leaft(node->eft) + leaf(node->right);
     ```

     - Print

     ```cpp
     Draw_tree()
     ```

  3. 알고리즘(강의노트 참조)

     Delete -> FINDMAX 알고리즘 사용할 것

  4. 테스트 절차(예)
     
     1. Delete: Tree is empty

     2. Traverse: Tree is empty

     3. Insert: (30 40 20 10 50) 순서대로 insert 후, DRAWTREE로 트리를 보일 것

     4. Leaf: 2

     5. Delete test:

        - Single 노드 테스트 -> delete 20, DRAWTREE로 트리를 보일 것

        - Leaf 노드 테스트 -> delete 50, DRAWTREE로 트리를 보일 것

        - 양쪽 노드 테스트 -> delete 30, DRAWTREE로 트리를 보일 것

     6. Search:
      
        <pre>30   "Not Found"
        10   "Found"</pre>

     7. Traverse:

          - inroder: 10 40

          - postorder: 40 10

          - preorder: 10 40


      
