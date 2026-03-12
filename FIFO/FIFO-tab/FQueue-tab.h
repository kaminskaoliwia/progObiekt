#pragma once
#include "global.h"

#define Qinfo QINFO

class FQueueTab
{
  private:
    QINFO** pInfo; // dynamic table of QINFO pointers
    int nNoElem; // number of elements in the queue
    int nMaxElem; // queue size

    int pHead; //index
    int pTail; //index

public:

  FQueueTab(int nMaxSize);
  ~FQueueTab();
  bool     FQEmpty();
  bool     FQEnqueue(QINFO* p);
  QINFO* FQDequeue();
  void    FQClear();
  void    FQDel();
  void    FQPrint();
};