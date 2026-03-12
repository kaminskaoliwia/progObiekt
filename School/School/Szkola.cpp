#include <iostream>
#include "SchoolGirl.h"
#include "SchoolBoy.h"
#include "Teacher.h"
#include "Admin.h"

void printAllPupils( Pupil* pupils[], int PupilNo );
void printAllWorkers( Worker* workers[], int WorkerNo );

//w worker licznie pensji 2 parametry - u admina liczenie na podstawie lat a u nauczyciela z odliczeniem tego od czego nie liczymy podatku

int main()
{
	/*
	SchoolGirl g1( "Nowak Agnieszka", 17, "3A" );
	g1.setNote( POLSKI, 3.5 );
	g1.setNote( MATEMATYKA, 4.5 );
	g1.setNote( INFORMATYKA, 4.5 );
	g1.setNote( FIZYKA, 4.0 );
	g1.setNote( NIEMIECKI, 4.5 );

	SchoolGirl g2( "Sobota Alicja", 18, "4B" );
	g2.setNote( POLSKI, 3 );
	g2.setNote( MATEMATYKA, 3.5 );
	g2.setNote( INFORMATYKA, 4.5 );

	SchoolGirl g3( "Lewandowska Beata", 17, "3B" );
	g3.setNote( POLSKI, 3.5 );
	g3.setNote( MATEMATYKA, 3.0 );
	g3.setNote( INFORMATYKA, 4.0 );
	g3.setNote( FIZYKA, 4.0 );
	g3.setNote( CHEMIA, 4.0 );

	SchoolBoy b1( "Kowalski Jakub", 17, "3B" );
	b1.setNote( ANGIELSKI, 5.0 );
	b1.setNote( INFORMATYKA, 5.0 );
	b1.setNote( FIZYKA, 4.0 );

	SchoolBoy b2( "Wiktor Kazimierz", 17, "3B" );
	b2.setNote( CHEMIA, 3.0 );
	b2.setNote( FIZYKA, 3.0 );
	b2.setNote( POLSKI, 4.5 );
	g3.setNote( MATEMATYKA, 3.0 );
	g3.setNote( NIEMIECKI, 4.0 );

	Pupil* pupils[] = { &g1, &g2, &g3, &b1, &b2 };

	printAllPupils( pupils, sizeof(pupils)/sizeof(Pupil*) );
	*/

	Teacher t1("Adam Adam", 35, 5000, 10, ANGIELSKI);
	Teacher t2("Barbara Barbara", 42, 6000, 17, INFORMATYKA, "4a");
	Teacher t3("Czeslaw Czeslaw", 58, 5500, 23, CHEMIA, "3c");
	Teacher t4("Dorota Dorota", 27, 5000, 2, FIZYKA, "1b");
	Teacher t5("Elzbieta Elzbieta", 41, 5500, 1, NIEMIECKI);

	Admin a1("Franciszek Franciszek", 67, 6000, 25, SPECJALISTA);
	Admin a2("Grzegorz Grzegorz", 34, 4000, 3, MLODSZY_SPECJALISTA);

	Worker* workers[] = {&t1, &t2, &t3, &t4, &t5, &a1, &a2};

	printAllWorkers(workers, sizeof(workers)/sizeof(Worker*));

	return 0;
}

void printAllPupils( Pupil* pupils[], int PupilNo )
{
	for( int i = 0; i < PupilNo; i++ )
	{
		pupils[ i ]->calcAve();
		pupils[ i ]->printPupil();
		cout << endl;
	}
}

void printAllWorkers( Worker* workers[], int WorkerNo )
{
	Worker* workersSorted[100];

	for (int i = 0; i < WorkerNo; i++)
		workersSorted[i] = workers[i];

	for (int i = 0; i < WorkerNo - 1; i++)
	{
		for (int j = 0; j < WorkerNo - 1 - i; j++)
		{
			if (workersSorted[j]->getSalary() < workersSorted[j + 1]->getSalary())
			{
				Worker* temp = workersSorted[j];
				workersSorted[j] = workersSorted[j + 1];
				workersSorted[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < WorkerNo; i++)
	{
		cout << workersSorted[i]->getName() << " " << workersSorted[i]->getAge() << " ";
		workersSorted[i]->printRole();
		workersSorted[i]->calculateSalary(); 
		cout << endl;

	}

}