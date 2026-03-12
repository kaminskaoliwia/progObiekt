#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "global.h"

template <class T> class FQItem 
{
public:
  T* pInfo;
  FQItem<T>* pNext;

  FQItem(T* pInfo, FQItem<T>* pNext);
  virtual ~FQItem();
}; 


template <class T> class FQueue
{
private:
  FQItem<T>* pHead;  // ptr to the first queue item
  FQItem<T>* pTail;  // ptr to the last queue item

public:
  FQueue();
  ~FQueue();
  bool FQEmpty();
  bool FQEnqueue(T* p);
  T* FQDequeue();
  void FQClear();
  void FQDel();
  void FQPrint();
};

template <class T> FQItem<T>::FQItem(T* info, FQItem<T>* next)
  : pInfo(info), pNext(next)
{}

template <class T> FQItem<T>::~FQItem()
{}


template <class T> FQueue<T>::FQueue()
  : pHead(nullptr), pTail(nullptr)
{}

template <class T> FQueue<T>::~FQueue()
{
  FQClear();
}


template <class T> bool FQueue<T>::FQEmpty()
{
  return !pHead;
}


template <class T> bool FQueue<T>::FQEnqueue(T* p)
{
  FQItem<T>* pNew = new FQItem<T>(p, nullptr);

  if (!pNew) {
    return false;
  }

  if ( pHead == nullptr )
  {
    pHead = pNew;
  }
  else
  {
    pTail->pNext = pNew;
  }
  pTail = pNew;

  return true;
}


template <class T> T* FQueue<T>::FQDequeue()
{
  if ( FQEmpty() ) return nullptr;

  T* value = pHead->pInfo;
  FQDel();

  return value;
}


template <class T> void FQueue<T>::FQClear()
{
  while (!FQEmpty())
  {
    T* element = FQDequeue();
    if ( element != nullptr )
      delete element;
  }
}


template <class T> void FQueue<T>::FQDel()
{
  if (FQEmpty())
  {
    printf("\nFQDEL: Kolejka jest pusta lub nie istnieje.\n");
    return;
  }

  FQItem<T>* temp = pHead;
  pHead = temp->pNext;

  delete temp;

  if ( FQEmpty() ) 
  {
    pTail = nullptr;
  }
}

template <class T> void FQueue<T>::FQPrint()
{
  if ( FQEmpty() ) {
    printf("\nKolejka jest pusta.");
    return;
  }

  FQItem<T>* p = pHead;
  while (p != nullptr)
  {
    printf("%p ", p->pInfo->key);
    p = p->pNext;
  }
}