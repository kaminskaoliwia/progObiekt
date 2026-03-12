
#include "FQueue-tab.h"
#include <iostream>

int main()
{
  printf("Kolejka FIFO (tablicowa)\n");

  // Tworzenie kolejki FIFO tablicowej
  FQueueTab kolejka = FQueueTab(5);

  // Dodanie elementow
  kolejka.FQEnqueue(new QInfo(1));
  kolejka.FQEnqueue(new QInfo(2));
  kolejka.FQEnqueue(new QInfo(3));
  kolejka.FQEnqueue(new QInfo(4));
  kolejka.FQEnqueue(new QInfo(5));

  // Wydrukowanie kolejki 
  kolejka.FQPrint();

  // Usuniecie elementu
  kolejka.FQDequeue();
  printf("\nPo usunieciu elementu: \n");
  kolejka.FQPrint();

  // Czyszczenie kolejki
  kolejka.FQClear();
  kolejka.FQPrint();

  return 0;
}


