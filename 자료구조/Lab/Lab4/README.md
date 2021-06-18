# Lab 3: Stack and Queue Practice

Stack과 Queue를 함께 사용하여 "abcde"를 순서대로 입력하고 "ebcda"를 순서대로 출력하는 program을 다음 10개의 ADT를 작성하여 완성하라.

<p align="center">S: Stack,&emsp;&emsp;Q: Queue,&emsp;&emsp;ch: character</p>

### ADT
<p font-weight="bold">PUSH, POP, StackFull, StackEmpty, DisplayStack, </p>
<p font-weight="bold">ENQUEUE, DEQUE, QueueFull, QueueEmpty, DisplayQ, </p>
<p font-weight="bold">C-Enque, C-Deque, display-CQ</p>

Output:

1. ( A * B ) + ( C * D )&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;Valid
2. ( A * ( B + ( C * D + E ) ) )&emsp;&emsp;&emsp;&emsp;Valid
3. ( A + B ) - { C + D } - [ F + G ]&emsp;&emsp;&nbsp;Valid
4. ( ( A + B )&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Invalid(Unbalanced parentheses)
5. ) A + B ( - C&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Invalid(Unbalanced parentheses)
6. ( A + B )) - ( C + D&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;Invalid(Unbalanced parentheses)
7. { [ A + B ] - [ ( C - D ) ]&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;Invalid(Unbalanced parentheses)
8. ( A + B } )&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Invalid(Mismatched parentheses)
9. { [ A + B ) - [ ( C - D ) ] }&emsp;&emsp;&emsp;&emsp;&emsp;Invalid(Mismatched parentheses)

  - Algorithm 참조

  ```cpp
  int check() {
    for(i = 0; i < strlen(exp); i++){
      if(exp[i] =='(' || exp[i] == '{' || exp[i] == '[') push(exp[i]);
      if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        if(stack empty) print("UnBalanced");
        else {
          temp = pop();
          if(!match(temp, exp[i])){ 
            // match(a, b) if(a == b) {return true else return false}
            prit("Mismatched" temp, "and" exp[i])
          }
        }
    } // end of for
    if(stack empty) return true
    else { print("Unbalanced"); return false; }
  }

  void main(){
    open data file  // check file open error
    while(infile.getline(buffer, 80)){ 
      validity = check_paranthesis();
      if(validity is true) print "valid" else print "Invalid"
    }
  }
  ```

---

## << Extra Points >>

### STACK - Palindrome

Write a program to read a text fiel and print whether or not a line is a palindrome.

1. palindrome: A palindrome is a string that reads the same forward and backward.
  - ex) radar &emsp;&emsp; 0 &emsp;&emsp; 1 &emsp;&emsp; 00 &emsp;&emsp; 11 &emsp;&emsp; aba &emsp;&emsp; 1101011 등

2. data file: abccba&emsp;&emsp;abckcba&emsp;&emsp;abbc&emsp;&emsp;abbacd

3. Output:

&emsp;&emsp;&emsp;abccba &emsp;&emsp;&emsp; a palindrome

&emsp;&emsp;&emsp;abckcba&emsp;&emsp;&emsp; a palindrome

&emsp;&emsp;&emsp;abbc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&emsp;&emsp;&emsp; not a palindrome

&emsp;&emsp;&emsp;abbacd &emsp;&emsp;&emsp; not a palindrome

4. Algorithm
  ```cpp
  while(!EOLN){
    length = strlen(buffer);  // string의 길이, 글자 수
    if length is EVEN{  // (len % 2 ) == 0
      while(i < (len / 2))  // length의 반만큼 push, 'abccba'의 경우 push a, push b, push c.
        push(buffer[i]);
    }
    else if len is ODD {  // (len % 2) != 0,
      while(i < (len / 2))  // length의 반만큼 push, 'abckcba'의 경우 push a, push b, push c.
        push(buffer[i]);    // buffer에 kcba 남음
          i++;              // k를 건너 뜀
    }
    compare(buffer[i] andpop(ch))
    // if same compare next, if not SAME, then BREAK;

    if(buffer[i] = "empty") then print "PALINDROME"
  }
  ```