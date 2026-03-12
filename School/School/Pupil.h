#pragma once
#include "Person.h"
#include <iostream>
using namespace std;
#include <string>

class Pupil : public Person
{
public:
    Pupil( string name="", int age=0, string className="" );
    Pupil( const Pupil& p );
    virtual ~Pupil() {}
    //defaultowy operator =

    string getClassName() const;
    string getID() const;
    double getAve() const;

    void setClassName( string newClassName );
    void setNote( Subjects subj, double note );
    void clearNotes();
    double calcAve();
    void printPupil();

    virtual void printOutfit() = 0; /*{ cerr << "Blad uzycia funkcji"; }
        - teraz to jest tzw. funkcja czysta (abstrakcyjna) => klasa tez jest czysta(apbstrakcyjna
        => nie wolno tworzyc obiektow tej klasy */

protected:
    string mID;
private:
    string mClassNme;
    double mAve; 
    double mNotes[ MAXSUBJECTS ];
    static int baseID;

};

