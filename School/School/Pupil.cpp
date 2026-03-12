#include "Pupil.h"

int Pupil::baseID = 10000;


Pupil::Pupil( string name /*= ""*/, int age/* = 0*/, string className /*= "" */ )
{
	setClassName( className );
	clearNotes();
	mID = to_string( baseID++ );
}

Pupil::Pupil( const Pupil& p )
{
	*this = p;
}

string Pupil::getClassName() const
{
	return this->mClassNme;
}

string Pupil::getID() const
{
	return this->mID;
}

double Pupil::getAve() const
{
	return this->mAve;
}

void Pupil::setClassName( string newClassName )
{
	mClassNme = newClassName;
}

void Pupil::setNote( Subjects subj, double note )
{
	if( subj >= POLSKI && subj < MAXSUBJECTS )
		if( note >= 2 && note <= 5 )
			mNotes[ subj ] = note;
	//else wyjatek albo wydruk na cerr
}

void Pupil::clearNotes()
{
	memset( mNotes, 0, MAXSUBJECTS*sizeof(double) );
	mAve = 0;
}

double Pupil::calcAve()
{
	double sum = 0;
	int noteNo = 0;

	for( int subj = POLSKI; subj < MAXSUBJECTS; subj++ )
	{
		if( mNotes[ subj ] > 1 )
		{ 
			sum += mNotes[ subj ];
			noteNo++;
		}
	}
	return mAve = ( noteNo )? sum/noteNo : 0;
}

void Pupil::printPupil()
{
	cout << getID() << " " << getName() << " (" << getClassName() << ") srednia = " << getAve();
	cout << "\t";
	printOutfit();
	cout << endl;
}
