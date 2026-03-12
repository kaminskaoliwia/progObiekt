
#include <iostream>
#include "FQueue.h"

int main()
{
    printf("Kolejka FIFO\n");
    // Tworzenie kolejki FIFO
    FQueue kolejka = FQueue();

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
