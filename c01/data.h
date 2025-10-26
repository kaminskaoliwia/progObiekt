#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {

private:
    int mDay; // m = member
    int mMonth;
    int mYear;

public:
    /* Date(); // konstruktor domyślny
    nie ma typu, moze byc kilka konstruktorow, nazywa sie tak jak klasa
    automatycznie wywolywana podczas tworzenia nowego obiektu tej klasy
    i sluzy do inicjalizacji jego skladowych */
    Date(int d=1, int m=1, int y=1990); // nowy konstruktor domyślny
    Date( const Date& d ); // konstruktor kopiujący
    Date& operator = (const Date& d );
    ~Date(); // destruktor
    friend istream& operator >> (istream& in, Date& d ); // wejściowy, d oraz in to parametry wejsc/wyjsc
    friend ostream& operator << ( ostream& out, const Date& d );
    /*
     friend = metody zaprzyjaznione z ta klasa
     "koledzy jezeli chca miec dostep do prywatnego interfejsu kolezanki to
     musza sie najpierw zaprzyjaznic"
     */
public:
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDate(int d, int m, int y);
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    void printDate();
    void readDate();

}; //! istotny srednik

inline int Date::getDay() const {
    return mDay;
}
inline int Date::getMonth() const {
    return mMonth;
}

inline int Date::getYear() const {
    return mYear;
}
#endif