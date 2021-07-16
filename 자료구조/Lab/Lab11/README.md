# Lab 11: Hashing

  1. Data Structrue

      ```cpp
      class Node{
        private:
        int data;
        Node *link;
        friend class Htable;
      };
      ```  
  
  2. ADT 함수
     
     1. findKey

     2. insertKey

     3. deleteKey

     4. printTable
  
  3. 메뉴로 구성할 것

     1. Find

     2. Insert

     3. Delete

     4. Quit

  4. Hashing Function: division method

     ex) Print Table: table size 7
    
  5. Algorithm: Chaining Method

### Main Program

```cpp
do{Enter command(i, f, d, q): read(ch);
  if(ch != 'q'){
    print("Enter key"); read(inkey);
    switch(ch){
      case 'i':
        check = insertkey(inkey);
        if(check == false)    print("Cannot insert key")  break;
      case 'f':
        check = findKey(inkey, index);
        if(check == false)    print("key not found"); break;
      case 'd':
        check = deleteKey(inkey);
        if(check == false)    print("key not found"); break;
      default:
        print("Bad Command");
    }
  }
  printTable(); // insert, delete, find후에 매번 테이블의 내용 출력
} while(ch == 'q');
```

### FindKey

  - Get index value for Key

  - Get head node from HashTable

    ```cpp
    if (headnode != NULL){
      Search the table for the key  // q = head; q = q->link;

      if(q = NULL) return false;
      else return true
    }
    else return false;
    ```

### Insert Key

  - Get Index for the Key

  - Check = findkey(key);

    ```cpp
    if(check == true) return false;
    Get head node for the Key
    if(head node == NULL) insert new node
    else find place to insert the key   // singly linked list와 유사
    ```

### Delete Key

  - Get index for the key

  - Get head node for the Key

      ```cpp
      if(head == key) delete head node & move head = head->next; (update head node)
      else find node and delete the node for the key    // same as singly linked list
      ```

### Print Table

  ```cpp
  for(i = 0; i < maxsize; i++){
    print "Htable [i]"
    Get head node for "i"
    for(head; head != NULL; head = head->link)
      print "node"
  }
  ```

### Testing 예

  insert 7 -> insert 36 -> insert 29 -> insert 22 -> find 25 -> delete 22 -> insert 8 -> insert 17 -> insert 10 -> delete 17 -> insert 3

  Htable[0]: 7

  Htable[1]: 36 -> 29 -> 8

  Htable[2]:

  Htable[3]: 10 -> 3

  Htable[4]:

  Htable[5]:

  Htable[6]:

---

### Compile

#### Lab 11

```cmd
> g++ -o Lab11 Lab11.cpp MyHashMap.hpp MyNode.hpp
```

