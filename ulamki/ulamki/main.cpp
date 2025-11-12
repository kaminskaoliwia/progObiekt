
#include <iostream>
#include "Rational.h"

int main()
{
  Rational r1(1,3);
  Rational r2(10,3);
  cout << "Podaj licznik i mianownik = ";
  cin >> r2;

  Rational r3(4, 16);
  Rational r4(2,0);

  Rational suma  = r1 + r2;
  Rational roznica = r1 - r2;
  Rational iloczyn = r1 * r2;
  Rational iloraz = r1 / r2;

  double r1d = r1.Value();
  double r2d = r2.Value();

  cout << "r1 = " << r1 << " = " << r1d << endl;
  cout << "r2 = " << r2 << " = " << r2d << endl;
  cout << "r3 = " << r3 << " <-- redukcja z 4/16" << endl;
  cout << "r4 = " << r4 << " <-- obsluga mianownika = 0" << endl;

  cout << endl;

  cout << "r1 + r2 = " << suma  << " = " << suma.Value() << endl;
  cout << "r1 - r2 = " << roznica << " = " << roznica.Value() << endl;
  cout << "r1 * r2 = " << iloczyn << " = " << iloczyn.Value() << endl;
  cout << "r1 / r2 = " << iloraz << " = " << iloraz.Value() << endl;


  return 0;
}

// prywatna funkcja liczaca NWP i skrocic = czyli dwie funkcje do skracania i do NWP