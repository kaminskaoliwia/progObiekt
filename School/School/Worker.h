#pragma once
#include "Person.h"
#include <iostream>
using namespace std;
#include <string>

/* WYMAGANIA: */
/* Dla kazdego pracownika pamietac: nawisko i imie, */
/* wiek oraz pensja brutto, sta¿ pracy w latach. */

enum Jobs{ MLODSZY_SPECJALISTA, SPECJALISTA, STARSZY_SPECJALISTA };

const double KOSZTY_UZYSKANIA = 111.25; 
const double KWOTA_WOLNA_MIESIECZNA = 46.34; 
const double STAWKA_PODATKU = 0.18; 
const double DODATEK_WYCHOWAWCY = 400.00;

class Worker : public Person
{
public:
  Worker(string name = "", int age = 0, double salary = 0, int exp = 0);
  Worker(const Worker& w);
  virtual ~Worker() {}

  /*? FUNKCJE ABSTRAKCYJNE */
  virtual void printRole() const = 0; 
  virtual void calculateSalary() const = 0;

  double getSalary() const;
  int getExp() const;
  string getName() const;
  int getAge() const;

  void setSalary( double salary );
  void setExp( int exp );

  void printWorker();
  double calculateBonus( double salary ) const;
  double calculateTax( double brutto, double koszty, double wolna ) const;

private:
  string mName;
  int mAge;
  double mSalary; /* BRUTTO */
  int mExp; /* mExp = experience = sta¿ */

};


