
#include "pch.h"
#include "testDll.h"
#include "Date.h"

//Date::Date() {
//   setDate(1,1,1990);
//}

Date::Date(int d, int m, int y) {
  setDay(d);
  setMonth(m);
  setYear(y);
}

void Date::setDay(int d) {
  this->mDay = d;
}

void Date::setMonth(int m) {
  this->mMonth = m;
}

void Date::setYear(int y) {
  this->mYear = y;
}

void Date::setDate(int d, int m, int y) {
  setDay(d);
  setMonth(m);
  setYear(y);
}

void Date::printDate() {
  cout << getDay() << '/' << getMonth() << '/' << getYear();
}

void Date::readDate() {
  int temp;
  char c; // separator daty
  cin >> temp >> c; setDay(temp);
  cin >> temp >> c; setMonth(temp);
  cin >> temp >> c; setYear(temp);
}
//! konstruktor kopiuj¹cy i podstawienia dzia³a tak samo

Date::Date( const Date& d ) {
  // mozna setDate uzyc do kopiowania, ale my robimy cos innego
  *this = d;
}

Date& Date::operator = (const Date& d ) {
  setDate(d.getDay(), d.getMonth(),d.getYear());
  return *this;
}

Date::~Date() {

}

istream& operator >> (istream& in, Date& d ) {
  int temp;
  char c; // separator daty
  cin >> temp >> c; d.setDay(temp);
  cin >> temp >> c; d.setMonth(temp);
  cin >> temp >> c; d.setYear(temp);
  return in;
}

ostream& operator << ( ostream& out, const Date& d ) {
  out << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
  return out;
}
