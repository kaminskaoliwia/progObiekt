//
// Created by Oliwia Kamińska on 13/10/2025.
//

#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    int mHour;
    int mMinute;
    int mSecond;
public:
    //Time();
    Time(int h = 12, int m = 00, int s = 00);
    Time( const Time& t );
    Time& operator = (const Time& t );

    friend istream& operator >> (istream& in, Time& t );
    friend ostream& operator << ( ostream& out, const Time& t );

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void setTime(int h, int m, int s);
    void setHour(int d);
    void setMinute(int m);
    void setSecond(int y);

    void printTime();
    void readTime();
};

inline int Time::getHour() const{
    return mHour;
}
inline int Time::getMinute() const{
    return mMinute;
}

inline int Time::getSecond() const{
    return mSecond;
}
#endif TIME_H