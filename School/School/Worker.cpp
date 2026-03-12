#include "Worker.h"

Worker::Worker( string name, int age, double salary, int exp )
{
  mName = name;
  mAge = age;
  mSalary = salary;
  mExp = exp;
}

Worker::Worker(const Worker& w)
{
  *this = w;
}

string Worker::getName() const {
  return this->mName;
}

int Worker::getAge() const {
  return this->mAge;
}

double Worker::getSalary() const {
  return this->mSalary;
}

int Worker::getExp() const {
  return this->mExp;
}

void Worker::setSalary( double salary ) {
  mSalary = salary;
}

void Worker::setExp( int exp ) {
  mExp = exp;
}

double Worker::calculateBonus( double salary ) const {
  int bonusPercent = 0;
  if (mExp >= 5) {
    bonusPercent = (mExp > 20) ? 20 : mExp; 
  }
  return mSalary * (bonusPercent / 100.0);
}

double Worker::calculateTax(double brutto, double koszty, double wolna) const
{
  double tax =  (brutto - koszty)  * STAWKA_PODATKU - wolna;
  if( tax < 0 ) tax = 0.0;
  return tax;
}


void Worker::printWorker() {
  cout << "Imie i nazwisko: " << getName() << " ";
  cout << "Wiek: " << getAge() << " ";
  cout << "Pensja brutto: " << mSalary << " ";
  cout << "Staz pracy (lata): " << mExp << endl;
}

