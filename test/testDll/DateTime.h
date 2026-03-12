#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"
#include "CTime.h"
#include <iosfwd>

class TESTDLL_API DateTime: public Date, public Time {
public:
  DateTime(int D=1, int M=1, int Y=1990, int h=0, int m=0, int s=0);
  
  DateTime(const Date& d, const Time& t);

  DateTime( const DateTime& dt );
  DateTime& operator = ( const DateTime& dt );

  friend TESTDLL_API istream& operator >> (istream& in, DateTime& dt );
  friend TESTDLL_API ostream& operator << (ostream& out, const DateTime& dt);

  void setDateTime( int D, int M, int Y, int h, int m, int s);

};


#endif