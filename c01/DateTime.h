#ifndef DATETIME_H
#define DATETIME_H
#include <iosfwd>


class DateTime: public Date, public Time {
public:
    DateTime(int D=1, int M=1, int Y=1990, int h=0, int m=0, int s=0);
    DateTime( const DateTime& dt );
    DateTime& operator = ( const DateTime& dt );

    friend istream& operator >> (istream& in, DateTime& dt );
    friend ostream& operator << (ostream& out, const DateTime& dt);

    void setDateTime( int D, int M, int Y, int h, int m, int s);

};


#endif