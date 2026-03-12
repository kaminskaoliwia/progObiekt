
#include "FQueue-tab.h"
#include <iostream>

 FQueueTab::FQueueTab(int maxSize) {
   
   if (maxSize < 2)
   {
     cerr << "ERROR FQueueTab: maxSize mniejszy od 2"; 
     return;
   }

   nMaxElem = maxSize;
   pInfo = new QINFO*[nMaxElem]; 
    
   if ( !pInfo )
   {
      cerr << "ERROR FQueueTab: b³¹d alokacji";
      return;
   }

   pHead = pTail = nNoElem = 0;
 }

 FQueueTab::~FQueueTab() {
   FQClear();    
   delete[] pInfo;
 }

 bool FQueueTab::FQEmpty() {
   return nNoElem == 0;
 }

 bool FQueueTab::FQEnqueue(QINFO* p) {

  if (nNoElem == nMaxElem) {
    cerr << "ERROR FQueueTab: Kolejka jest pe³na";
    return false;
  }

  pInfo[pTail] = p;

  pTail = (pTail+1)  % nMaxElem;
//  if (pTail >= nMaxElem) {
  //  pTail = 0;
  //}

  nNoElem++;
  return true;
 }
 
 QINFO* FQueueTab::FQDequeue() {
   if ( FQEmpty() ) {
     cerr << "\nERROR FQDequeue: Kolejka jest pusta\n";
     return nullptr;
   }

   QINFO* value = pInfo[pHead];
   FQDel();
   return value;
 }
 
 void FQueueTab::FQClear() {
   while (!FQEmpty()) {
     FQDel();
   }

   pHead = 0;
   pTail = 0;
   nNoElem = 0;
 }
 void    FQueueTab::FQDel() {

   if( FQEmpty() )
   {
     cerr << "\nERROR FQDEL: Kolejka jest pusta lub nie istnieje.\n";
     return;
   }

   delete pInfo[pHead];
   pInfo[pHead] = nullptr;

   pHead = (pHead + 1) % nMaxElem;
   nNoElem--;

 }
 
 void    FQueueTab::FQPrint() {
   if ( FQEmpty() ) {
     cerr << "\nFQPrint: Kolejka jest pusta.\n";
     return;
   }

   int current = pHead;
   for (int i = 0; i < nNoElem; ++i) {
     QINFO* info = pInfo[current];
     if (info != nullptr) {
        std::cout << *info << std::endl; 
     }

     current++;
      if (current >= nMaxElem) {
        current = 0;
      }
   } }