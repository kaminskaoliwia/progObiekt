#include <iostream>
#include "data.h"
#include "time.h"
#include "DateTime.h"

using namespace std;

int main() {
    /*
     referencja - inna nazwa tej samej zmiennej
     referencja musi być zainicjowana, nie mozna pozniej zmienic jej wartosci w sensie ref jest zawsze
     referencja do x, zmiana ref to zmiana x !
     nie mozna zrobic referencji do stalej

     int y = 4;
     int& f() (return y; )
     f()++; f() = 10;

     //-------------------------------

     PersonType* pOsoba = new PersonType(); // wywoluje konstruktor domyślny
     PersonType* pOsoba = new PersonType("Kowalski", "Jan");
     delete pOsoba; // wywołuje destruktor

     //--------------------------------

     int* pTab = new int [20];
     pTab[2] = 3;
     delete [] pTab; //!!!!!!!!!!!!!

     //---------------------------------

    NULL = nullptr

    //------------------------------

     */

    //-----------------------------
    Date d2(22, 12, 2025);
    cout << "d2 = ";
    Date d3( d2 );
    {
        Date d4( d3 ); // wywolanie destruktora automatyczne
    }

    Date d1;
    d1.setDate( 1, 10, 2025);
    cout << "d1 = "; d1.printDate();
    cout << endl;

    d1.setDay(6);
    cout << "d1 = "; d1.printDate();
    cout << endl;

    cout << "Podaj date w formacie dd/mm/yyyy: ";
    d1.readDate();
    cout << "d1 = "; d1.printDate();
    cout << endl;
    return 0;
}