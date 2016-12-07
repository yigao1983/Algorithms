#ifndef LINKEDSTACK
#define LINKEDSTACK

#include <stdexcept>

template<class T>
class LinkedStack
{
public:
  
  LinkedStack() : first(NULL) {}
  
  virtual ~LinkedStack()
  {
    while (first) {
      pop();
    }
  }
  
  void push(const T &src)
  {
    Node *oldfirst = first;
    first = new Node(src);
    first->next = oldfirst;
  }
  
  T pop()
  {
    if (!isEmpty()) {
      Node *oldfirst = first;
      T item = oldfirst->item;
      first = first->next;
      delete oldfirst;
      return item;
    } else {
      throw std::underflow_error("Stack is empty\n");
    }
  }
  
  bool isEmpty()
  { return !first; }
  
protected:
  
  class Node
  {
  public:
    Node(const T &src) : item(src), next(NULL)
    {}
    virtual ~Node() {}
  protected:
    T item;
    Node *next;
    
    friend class LinkedStack<T>;
  };
  
  Node *first;
};

#endif
