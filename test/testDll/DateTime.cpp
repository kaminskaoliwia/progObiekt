
#include "pch.h"
#include "testDll.h"
#include "DateTime.h"

DateTime::DateTime(int D, int M, int Y, int h, int m, int s)
  : Date(D, M, Y), Time(h,m,s) {

}
DateTime::DateTime(const Date& d, const Time& t)
  : Date(d), Time(t) {}

DateTime::DateTime(const DateTime& dt) {
  *this = dt; // wywoluje operator podstawienia
}

DateTime& DateTime::operator = ( const DateTime& dt ) {
  (Date&)*this = (const Date&)dt;
  *(Time*)this = (Time&)dt;
  return *this;
}

istream& operator >> (istream& in, DateTime& dt ) {
  in >> (Date&)dt;
  in >> (Time&)dt;
  return in;
}
ostream& operator << (ostream& out, const DateTime& dt) {
  out << (const Date&)dt << " ---- ";
  out << (const Time&)dt;
  return out;
}

void DateTime::setDateTime( int D, int M, int Y, int h, int m, int s) {
  setDate( D, M, Y );
  setTime( h, m, s );
}
