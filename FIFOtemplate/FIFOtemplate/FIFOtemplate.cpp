
#include <iostream>
#include "FQueue.h"
#include "global.h"

int main()
{
  // Tworzenie kolejki FIFO
  FQueue<QINFO> kolejka;

  // Dodanie elementow
  kolejka.FQEnqueue(new QInfo(1));
  kolejka.FQEnqueue(new QInfo(2));
  kolejka.FQEnqueue(new QInfo(3));

  // Wydrukowanie kolejki 
  kolejka.FQPrint();

  // Usuniecie elementu
  kolejka.FQDequeue();
  printf("\nPo usunieciu elementu: ");
  kolejka.FQPrint();

  // Czyszczenie kolejki
  kolejka.FQClear();
  kolejka.FQPrint();
  return 0;
}
