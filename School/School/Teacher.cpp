#include "Teacher.h"

Teacher::Teacher( string name, int age, double salary, int exp, Subjects subject, string mclass) : Worker( name, age, salary, exp )
{
  setSubject( subject );
  setClass( mclass );
}

Teacher::Teacher( const Teacher& t ) 
{
 *this = t;
}

Subjects Teacher::getSubjectEnum() const {
  return this->mSubject;
}

void Teacher::printRole() const {
  std::cout << subjectToString(mSubject);
}


string Teacher::getClass() const {
  if( this->mClass == "" )
    return "Nie jest wychowawc¹";
  return mClass;
}

bool Teacher::isWychowawca() const {
  if( this->mClass == "" )
    return 0;
  return 1;
}

void Teacher::setSubject(Subjects subject) {
  mSubject = subject;
}

 void Teacher::setClass( string mclass ) {
  mClass = mclass;
 }

 void Teacher::calculateSalary() const {
   /* dla nauczycieli od 80% pensji naliczac 50% koszty uzysku a od reszty tak jak dla admina przy czym 
   uwzglednic w kwocie brutto wysluge lat (w zakresie od 5 do 20 lat pracy doliczac do kwoty brutto 
   odpowiednio od 5 do 20% kwoty brutto) oraz jesli jest wychowawca
   dodac dodatek 400 zl */

  /* wyliczenie brutto */
  double salary = getSalary();
  double bonus = calculateBonus(salary);
  double totalBrutto = salary + bonus;
  if (isWychowawca()) {
    totalBrutto += 400.0;
  }

  /* 80% pensji zasadniczej = 50% kosztów */
  double base50 = (salary * 0.80); 
  double wolna = KWOTA_WOLNA_MIESIECZNA * 0.5;
  double tax = calculateTax(salary, base50, wolna);

  /* 20% */
  double bruttoRest = (salary * 0.2) + calculateBonus(salary);
  if ( isWychowawca() ) bruttoRest+=DODATEK_WYCHOWAWCY;
  double koszty = KOSZTY_UZYSKANIA;
  double taxRest = calculateTax(bruttoRest, koszty, 0.0);

  double salaryNetto = totalBrutto - tax - taxRest;

  std::cout << " Brutto: " << totalBrutto << " zl";
  std::cout << " Podatek: " << tax << " zl";
  std::cout << " Netto: " << salaryNetto << " zl";
 }
 
 string Teacher::subjectToString(Subjects subject) {
   switch (subject) {
   case POLSKI: return "Polski";
   case MATEMATYKA: return "Matematyka";
   case FIZYKA: return "Fizyka";
   case CHEMIA: return "Chemia";
   case INFORMATYKA: return "Informatyka";
   case ANGIELSKI: return "Angielski";
   case NIEMIECKI: return "Niemiecki";
   default: return "Nauczyciel";
   }
 }


