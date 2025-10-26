#include "../time.h"

Time::Time() {
    setDate(12,00,00);
}

Time::Time(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    this->mHour = h;
}

void Time::setMinute(int m) {
    this->mMinute = m;
}

void Time::setSecond(int s) {
    this->mSecond = s;
}

void Time::printTime() {
    cout << getHour() << ':' << getMinute() << ':' << getSecond();
}

void Time::readTime() {
    int temp;
    char c; // separator daty
    cin >> temp >> c; setHour(temp);
    cin >> temp >> c; setMinute(temp);
    cin >> temp >> c; setSecond(temp);
}
Time::Time( const Time& t ) {
    *this = t;
}
Time& Time::operator = (const Time& t ) {
    setTime(t.getHour(), t.getMinute(), t.getSecond());
}

istream& operator >> (istream& in, Time& t ) {
    int temp;
    char c; // separator daty
    cin >> temp >> c; t.setHour(temp);
    cin >> temp >> c; t.setMinute(temp);
    cin >> temp >> c; t.setSecond(temp);
}
ostream& operator << ( ostream& out, const Time& t ) {
    out << t.getHour() << ':' << t.getMinute() << ':' << t.getSecond();
}
