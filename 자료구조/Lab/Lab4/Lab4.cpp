// Stack and Queue Practice - 20163162, Cha Yoonsung, Lab4
#include <iostream>

#include "MyCQueue.h"
#include "MyQueue.h"
#include "MyStack.h"

using namespace std;

int main() {
  Stack stack(2);
  Queue queue(3);
  CQueue cqueue(3);

  stack.push('a');
  queue.enqueue('b');
  queue.enqueue('c');
  queue.enqueue('d');
  stack.push('e');

  stack.push('F');
  queue.enqueue('G');
  cout << endl;

  stack.printStack();
  queue.printQueue();
  cout << endl;

  cout << "Output : ";
  cout << stack.pop() << " ";
  cout << queue.dequeue() << " ";
  cout << queue.dequeue() << " ";
  cout << queue.dequeue() << " ";
  cout << stack.pop() << " ";
  cout << endl;

  stack.pop();
  queue.dequeue();
  cout << endl;

  cqueue.enqueue('A');
  cqueue.enqueue('B');
  cqueue.enqueue('C');
  cqueue.dequeue();
  cqueue.enqueue('D');
  cout << endl;

  cqueue.printCQueue();
  cout << endl;

  cqueue.dequeue();
  cqueue.dequeue();
  cqueue.dequeue();
  cout << endl;

  return 0;
}