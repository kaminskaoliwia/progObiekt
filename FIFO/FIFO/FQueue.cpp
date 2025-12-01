
#include "FQueue.h"

int FQueue::FQEmpty() {
  return !pHead;
}

int FQueue::FQEnqueue(QINFO* p ) {

  FQItem* pNew = new FQItem(p, nullptr);
  
  if (!pNew) {
    return 0; 
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

  return 1;
}

QINFO* FQueue::FQDequeue() {
  if ( FQEmpty() ) return 0;

  QINFO* value = pHead->pInfo;

  FQDel();

  return value;
}

void FQueue::FQClear(void(__cdecl* freeMem)(const void*) ) {
  
  if (!freeMem) {
    printf("FQCLEAR: Funkcja freeMem jest NULL\n");
    return;
  }

  while ( !FQEmpty() ) 
  {
    freeMem( FQDequeue() );
  }

  pHead = pTail = NULL;
}

void FQueue::FQRemove( FQueue** q, void (__cdecl* freeMem)(const void*) ) {
  FQClear( freeMem );
  free( *q ); 
  *q = NULL;
}

void FQueue::FQDel() {

  if( FQEmpty )
  {
    printf("\nFQDEL: Kolejka jest pusta lub nie istnieje.\n");
    return;
}
  FQItem* temp = pHead;
  pHead = temp->pNext;

  free(temp); 

  if ( FQEmpty() )
  {
    pTail = NULL;
  }
}


void  FQueue::FQPrint(void(__cdecl* printInfo )(const void*) ) {
  FQItem* p = pHead;

  while (p != NULL) {
    printInfo(p->pInfo);
    p = p->pNext;

}