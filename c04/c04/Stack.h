#pragma once

#include <iostream>
using namespace std;

#define STACK_OVERFLOW 0x01
#define STACK_UNDERFLOW 0x02
#define STACK_UNDEF_ERROR 0xFF

class StackException
{
public: 
  StackException( int errCode ) { mErrCode = errCode; }
  const char* getReason();
private:
  int mErrCode;
};

inline const char* StackException::getReason() {
  switch( mErrCode )
  {
  case STACK_OVERFLOW: return "ERROR: stack overflow!\n";
  case STACK_UNDERFLOW: return "ERROR: stack underflow!\n";
  default: return "ERROR: undefined error!\n";
  }
}

template <class T> class Stack; // zapowiedz klasy Stack

template <class T> class StackItem
{
  private:
  StackItem(T key, StackItem* pNext);
  virtual ~StackItem(); 

  T getKey() const;
  StackItem* getNext() const;
  void setNext( StackItem<T>* pNext );
  void setKey( T key );

  friend class Stack; // zaprzyjazniam WSZYSTKIE METODY Stack z klasa StackItem

private:
  T mKey; // zawartosc
  StackItem<T>* m_pNext; // wskaznik
};

//---INLINE---

template <class T> StackItem<T>::StackItem(T key, StackItem<T>* pNext) {
  setKey(key);
  setNext(pNext);
}

template <class T> T StackItem<T>::getKey() const {
  return this->mKey;
}

template <class T> StackItem<T>* StackItem<T>::getNext() const {
  return this->m_pNext;
}

template <class T> void StackItem<T>::setNext( StackItem* pNext ) {
  this->m_pNext = pNext;
}

template <class T> void StackItem<T>::setKey( T key ) {
  this->mKey = key;
}

template <class T> class Stack
{
public:
  Stack();
  virtual ~Stack();

  void push( T c );	//wlozenie na stos znaku c
  T pop();	//zwraca wartosc szczytowa i ja usuwa
  T top(); //zwraca wartosc szczytowa 
  void del(); //usuwa element szczytowy
  bool isEmpty(); // zwraca 1 gdy stos pusty, else 0

  private:
    StackItem* m_pHead;

};

//--INLINE--

template <class T> bool Stack<T>::isEmpty() {
  return !m_pHead;
}

// NOTATKI 
/* template - wzorzec funkcji lub klasy, a nie konkretne funkcje */

template <class T>
StackItem<T>::StackItem(T key, StackItem* pNext) 
{
  setKey(key);
  setNext(pNext);
}

template <class T>
StackItem<T>::~StackItem() {
}

template <class T>
Stack<T>::Stack() {
  this->m_pHead = nullptr;
}

template <class T>
Stack<T>::~Stack() {
  while (!isEmpty()) {
    del();
  }
}

template <class T>
void Stack<T>::push(T c) {
  StackItem<T>* p = new (nothrow) StackItem<T>(c, m_pHead);
  if (!p) {
    throw StackException(STACK_UNDEF_ERROR);
  }
  m_pHead = p;
}

template <class T>
T Stack<T>::pop() {
  if (!isEmpty()) {
    T c = top();
    del();
    return c;
  }
  throw StackException(STACK_UNDERFLOW);
}

template <class T>
T Stack<T>::top() {
  if (!isEmpty()) {
    return m_pHead->getKey();
  }
  throw StackException(STACK_UNDERFLOW);
}

template <class T>
void Stack<T>::del() {
  if (!isEmpty()) {
    StackItem<T>* p = this->m_pHead;
    m_pHead = p->getNext();
    delete p;
  } else {
    throw StackException(STACK_UNDERFLOW);
  }
}