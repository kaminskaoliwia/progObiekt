#include "Admin.h"

Admin::Admin( string name, int age, double salary, int exp, Jobs mJob) : Worker(name, age, salary, exp) 
{
  setJob( mJob );
}

Admin::Admin( const Admin& a ) 
{
  *this = a;
}

Jobs Admin::getJobEnum() 
{
  return mJob;
}

void Admin::printRole() const 
{
  std::cout << jobsToString( mJob );
}

void Admin::setJob( Jobs job ) 
{
  mJob = job;
}

void Admin::calculateSalary() const {
  /* dla admina podatek oblicza sie ( (kwota brutto - koszty uzysku) * 18% podatku - kwota wolna), */
   /* (kwota netto to brutto minus obliczony podatek). W kwocie brutto wysluge lat ( */
   /* w zakresie od 5 do 20 lat pracy doliczac do kwoty brutto odpowiednio od 5 do 20% kwoty brutto) */
  /* Jesli podatek wychodzi ujemny to go wyzerowac */

  double salary = getSalary();
  double totalBrutto = salary + calculateBonus(salary);

  /*double baseTax = totalBrutto - KOSZTY_UZYSKANIA;
  double tax = (baseTax * STAWKA_PODATKU) - KWOTA_WOLNA_MIESIECZNA;
  */

  double wolna = KWOTA_WOLNA_MIESIECZNA;
  double koszty = KOSZTY_UZYSKANIA;
  double tax = calculateTax(totalBrutto, koszty, wolna);

  double salaryNetto = totalBrutto - tax;

  std::cout << " Brutto: " << totalBrutto << " zl";
  std::cout << " Podatek: " << tax << " zl";
  std::cout << " Netto: " << salaryNetto << " zl";
}

string Admin::jobsToString( Jobs job ) {
  switch ( job ) {
    case MLODSZY_SPECJALISTA: return "Mlodszy specjalista";
    case SPECJALISTA: return "Specjalista";
    case STARSZY_SPECJALISTA: return "Starszy specjalista";
    default: return "Admin";
}
}