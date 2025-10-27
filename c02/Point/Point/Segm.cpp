#include "Segm.h"
#include <cmath>
#include <iostream>
using namespace std;

// Konstruktorzy
Segm::Segm(double x1, double y1, double x2, double y2) : mPt1(x1, y1), mPt2(x2, y2) {}
Segm::Segm(const Point& pt1, const Point& pt2) : mPt1(pt1), mPt2(pt2) {}
Segm::Segm(const Segm& s) : mPt1(s.mPt1), mPt2(s.mPt2) {}

// Funkcje
void Segm::Translate(double vx, double vy) {
  mPt1.Translate(vx, vy);
  mPt2.Translate(vx, vy);
}

void Segm::Rotate(int deg) {
  double rad = Deg2Rad(deg);
  Point mid(ave(mPt1.getX(), mPt2.getX()), ave(mPt1.getY(), mPt2.getY()));
  Translate(-mid.getX(), -mid.getY());
  mPt1.Rotate(rad);
  mPt2.Rotate(rad);
  Translate(mid.getX(), mid.getY());
}

double Segm::segmLen() const {
  double dx = mPt2.getX() - mPt1.getX();
  double dy = mPt2.getY() - mPt1.getY();
  return sqrt(dx*dx + dy*dy);
}

// SetSegm
void Segm::setSegm(const Point& pt1, const Point& pt2) {
  mPt1 = pt1;
  mPt2 = pt2;
}

void Segm::setSegm(double x1, double y1, double x2, double y2) {
  mPt1.setPoint(x1, y1);
  mPt2.setPoint(x2, y2);
}

void Segm::setSegm(const Segm& s) {
  mPt1 = s.mPt1;
  mPt2 = s.mPt2;
}

// Operatory
ostream& operator<<(ostream& out, const Segm& s) {
  out << "[" << s.getPt1() << " - " << s.getPt2() << "]";
  return out;
}

istream& operator>>(istream& in, Segm& s) {
  in >> s.mPt1 >> s.mPt2;
  return in;
}
