#include "FQueue.h"

FQItem::FQItem(QINFO* info, FQItem* next) : pInfo(info) {
  pNext = nullptr;
}

FQItem::~FQItem() {

}

FQueue::FQueue() /*: pHead(nullptr), pTail(nullptr) */
{
  pHead = nullptr;
  pTail = nullptr;
}

FQueue::~FQueue() {
  FQClear();
}

bool FQueue::FQEmpty() {
  return !pHead;
}

bool FQueue::FQEnqueue(QINFO* p ) {

  FQItem* pNew = new FQItem(p, nullptr);
  
  if (!pNew) {
    cerr << "\nERROR FQItem: b³¹d alokacji\n";
    return false; 
  }

  if( pHead == nullptr )
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

QINFO* FQueue::FQDequeue() {
  if ( FQEmpty() ) 
  {
    cerr << "\nERROR FQDEqueue: Kolejka jest pusta\n";
    return nullptr;
  }

  QINFO* value = pHead->pInfo;

  FQDel();

  return value;
}

void FQueue::FQClear() {

  while ( !FQEmpty() ) 
  {
    QINFO* element = FQDequeue();

    if (element != nullptr) {
      delete element;
    }
  }
}

void FQueue::FQDel() {

  if( FQEmpty() )
  {
    cerr << "\nFQDEL: Kolejka jest pusta lub nie istnieje.\n";
    return;
}
  FQItem* temp = pHead;
  pHead = temp->pNext;

  delete temp; 

  if ( FQEmpty() )
  {
    pTail = nullptr;
  }
}

void  FQueue::FQPrint() {
  if ( FQEmpty() ) {
    cerr << "\nKolejka jest pusta.\n";
    return; }

  FQItem* p = pHead;
  while (p != NULL) {
    printf("%d ", p->pInfo->key);
    p = p->pNext;
  }
}