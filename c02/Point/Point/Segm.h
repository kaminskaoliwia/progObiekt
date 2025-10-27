#ifndef SEGM_H
#define SEGM_H

#include <iostream>
#include "Point.h"
#define PI 3.14159265

class Segm {
private:
  Point mPt1;
  Point mPt2;

  double Deg2Rad(int deg) const;
  double ave(double x1, double x2) const;

public:
  Segm(double x1, double y1, double x2, double y2);
  Segm(const Point& pt1, const Point& pt2);
  Segm(const Segm& segm);

  const Point& getPt1() const;
  const Point& getPt2() const;

  void setPt1(double x, double y);
  void setPt1(const Point& pt);
  void setPt2(double x, double y);
  void setPt2(const Point& pt);

  void setSegm(const Point& pt1, const Point& pt2);
  void setSegm(double x1, double y1, double x2, double y2);
  void setSegm(const Segm& s);

  void Translate(double vx, double vy);
  void Rotate(int deg);
  double segmLen() const;

  friend ostream& operator<<(ostream& out, const Segm& s);
  friend istream& operator>>(istream& in, Segm& s);
};

// Inline funkcje
inline const Point& Segm::getPt1() const { return mPt1; }
inline const Point& Segm::getPt2() const { return mPt2; }
inline void Segm::setPt1(double x, double y) { mPt1.setPoint(x, y); }
inline void Segm::setPt2(double x, double y) { mPt2.setPoint(x, y); }
inline void Segm::setPt1(const Point& pt) { mPt1.setPoint(pt); }
inline void Segm::setPt2(const Point& pt) { mPt2.setPoint(pt); }
inline double Segm::ave(double x1, double x2) const { return (x1 + x2) / 2.0; }
inline double Segm::Deg2Rad(int deg) const { return deg * PI / 180.0; }

#endif
