#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point {
public:
  double mx;
  double my;

  Point(int mx = 0, int my = 0);       // konstruktor
  Point(const Point& p);               // konstruktor kopiuj¹cy

  double getX() const;
  double getY() const;

  void setX(double x);
  void setY(double y);
  void setPoint(double x, double y);
  void setPoint(const Point& p);

  void Translate(double vx, double vy);
  void Rotate(double rad);
  void readPoint();

  friend ostream& operator<<(ostream& out, const Point& p);
  friend istream& operator>>(istream& in, Point& p);
};

inline double Point::getX() const { return mx; }
inline double Point::getY() const { return my; }
inline void Point::setX(double x) { mx = x; }
inline void Point::setY(double y) { my = y; }
inline void Point::setPoint(double x, double y) { setX(x); setY(y); }
inline void Point::setPoint(const Point& p) { setX(p.getX()); setY(p.getY()); }

#endif
