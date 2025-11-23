#include "Stack.h"
/*
StackItem::StackItem(char key, StackItem* pNext) {
    setKey(key);
    setNext(pNext);
}

StackItem:: ~StackItem() {
 
} 

Stack::Stack() {
  this->m_pHead = nullptr;
}

Stack::~Stack() {
  while( !isEmpty()) {
    del();
  }
}

void Stack::push( char c ) {
  StackItem* p = new ( nothrow ) StackItem(c, m_pHead); // jesli blad = null
  if (!p) {
  throw StackException(STACK_UNDEF_ERROR);
  }

  m_pHead = p;
  }

char Stack::pop() {
  if (!isEmpty()) {
  char c = top();
  del();
  return c;
  }
  throw StackException(STACK_UNDERFLOW);
}

char Stack::top() {
  if (!isEmpty()) {
  return m_pHead->getKey();
  }
  throw StackException(STACK_UNDERFLOW);
}

void Stack::del() {
  if (!isEmpty()) {
  StackItem* p = this->m_pHead;
  m_pHead = p->getNext();
  delete p;
  }
  else
    throw StackException(STACK_UNDERFLOW);
}
*/