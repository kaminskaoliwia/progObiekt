#pragma once

#include "global.h" // dostarczany przez uzytkownika tej kolejki

#include <stdio.h>
#include <stdlib.h>

class FQItem 
{
public:
  QINFO* pInfo;
  FQItem* pNext;
  
  FQItem(QINFO* pInfo, FQItem* pNext);
  virtual ~FQItem();
}; 


class FQueue
{
private:
  FQItem* pHead;  // ptr to the first queue item
  FQItem* pTail;  // ptr to the last queue item

public:
  int     FQEmpty();
  int     FQEnqueue(QINFO* p );
  QINFO*  FQDequeue();
  void    FQClear(void(__cdecl* freeMem)(const void*) );
  void    FQRemove( FQueue** q, void (__cdecl* freeMem)(const void*) );
  void    FQDel();
  void    FQPrint(void(__cdecl* printInfo )(const void*) );
}; 


