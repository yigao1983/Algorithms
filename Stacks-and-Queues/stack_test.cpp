#include <iostream>
#include "LinkedStack.hpp"

using namespace std;

int main(int argc, char **argv)
{
  LinkedStack<int> stack;
  
  stack.push(1);
  stack.push(5);
  stack.push(7);
  stack.push(2);
  stack.push(4);
  stack.push(0);
  
  while (!stack.isEmpty()) {
    cout << stack.pop() << endl;
  }
  
  try {
    stack.pop();
  } catch (exception &e) {
    cout << "under flow" << endl;
  }
  
  return 0;
}
