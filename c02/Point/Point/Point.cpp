#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;

// Konstruktory
Point::Point(int x, int y) : mx(x), my(y) {}
Point::Point(const Point& p) : mx(p.mx), my(p.my) {}

// Funkcje
void Point::Translate(double vx, double vy) {
  mx += vx;
  my += vy;
}

void Point::Rotate(double rad) {
  double tempX = round(mx * cos(rad) - my * sin(rad));
  double tempY = round(mx * sin(rad) + my * cos(rad));
  mx = tempX;
  my = tempY;
}

void Point::readPoint() {
  double x, y;
  cin >> x >> y;
  setPoint(x, y);
}

// Operatory
ostream& operator<<(ostream& out, const Point& p) {
  out << "(" << p.mx << ", " << p.my << ")";
  return out;
}

istream& operator>>(istream& in, Point& p) {
  in >> p.mx >> p.my;
  return in;
}
