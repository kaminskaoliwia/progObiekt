// c05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <class T1, typename T2> int howMany( T1* arr, int size, T2 min, T2 max)
{
  int count = 0;
  for( int i=0; i<size; i++, arr++)
    if( (*arr > min) && (*arr < max ) ) count++;

    // if( (arr[i] > min) && (arr[i] < max ) ) count++;
    // if( (*arr > min) && (*arr < max ) ) count++; = nie dziala bo jezeli pierwszy warunek jest spelniony, to nie sprawdza drugiego i nie inkrementuje

  // test
  cout << "T1=" << typeid(T1).name() << " "
    << "T2 = " << typeid(T2).name() << " ";

  return count;
}

int main()
{
  double mnd = 0;
  double mxd = 10;
  double tabd[] = { -2, -1, 2, 5, 7, 11, 5, -5 };
  int tabdSize = sizeof( tabd ) / sizeof( double );

  int mni = 0;
  int mxi = 10;
  int tabi[] = { -2, -1, 2, 5, 7, 11, 5, -5 };
  int tabiSize = sizeof( tabi ) / sizeof( int );

  int res = howMany( tabi, tabiSize, mni, mxi ); // nastepuje konkretyzacja T1 = int, T2 = int
  cout << "res = " << res << endl;

  res = howMany( tabd, tabdSize, mnd, mxd ); // nastepuje konkretyzacja T1 = double, T2 = double
  cout << "res = " << res << endl;

  return 0;
}

