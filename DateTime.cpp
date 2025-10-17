#include "DateTime.h"

#include "data.h"
#include "time.h"

DateTime::DateTime(int D, int M, int Y, int h, int m, int s)
        : Date(D, M, Y), Time(h,m,s) {

}

DateTime( const DateTime& dt ) : Date( (const Date&)dt ), Time(dt.Time()) {

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
    out << (Date&)dt << " ---- ";
    out << (Time&)dt;
    return out;
}

void setDateTime( int D, int M, int Y, int h, int m, int s) {
    setDate( D, M, Y );
    setTime( h, m, s );
}
