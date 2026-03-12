
#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class TESTDLL_API Time {
private:
  int mHour;
  int mMinute;
  int mSecond;
public:
  Time(int h = 0, int m = 0, int s = 0);
  Time( const Time& t );
  Time& operator = (const Time& t );

  friend TESTDLL_API istream& operator >> (istream& in, Time& t );
  friend TESTDLL_API ostream& operator << ( ostream& out, const Time& t );

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