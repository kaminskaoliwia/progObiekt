
#ifndef SEGM_H
#define SEGM_H

#include <iostream>
#include "Point.h"

#define PI 3.14159265

class Segm {
private:
    Point& mPt1;
    Point& mPt2;
public:
    Segm(double x1, double y1, double x2, double y2);
    Segm(const Point& mPt1 = 0, const Point& mPt2 = 0);
    Segm( const Segm& segm );

    const Point& getPt1() const;
    const Point& getPt2() const;

    void setPt1(double x, double y);
    void setPt1(const Point& pt);
    void setPt2(double x, double y);
    void setPt2(const Point& pt);

    void setSegm(const Point& pt1=Point(), const Point& pt2=Point());
    void setSegm(double x1, double y1, double x2, double y2);
    void setSegm(const Segm& s);

    friend istream& operator >> (istream& in, Segm& pt );
    friend ostream& operator << ( ostream& out, const Segm& pt );

    void Translate(double vx, double vy);
    void Rotate(int deg);
    double segmLen() const;

private:
    double Deg2Rad( int deg ) const;
    double ave(double x1, double x2);


};

inline const Point& Segm::getPt1() const {
    return mPt1;
}

inline const Point& Segm::getPt2() const {
    return mPt2;
}

inline void Segm::setPt1(double x, double y) {
    mPt1.setX(x);
    mPt1.setY(y);
}

inline void Segm::setPt2(double x, double y) {
    mPt2.setX(x);
    mPt2.setY(y);
}
inline void Segm::setPt1(const Point& pt) {
    mPt1.setX(pt.getX());
    mPt1.setY(pt.getY());
}

inline void Segm::setPt2(const Point& pt) {
    mPt2.setX(pt.getX());
    mPt2.setY(pt.getY());
}

void Segm::setSegm(const Point& pt1, const Point& pt2) {
    setPt1(pt1);
    setPt2(pt2);
}
void Segm::setSegm(double x1, double y1, double x2, double y2) {
    setPt1(x1, y1);
    setPt2(x2, y2);
}
void Segm::setSegm(const Segm& segm) {
    mPt1 = segm.mPt1;
    mPt2 = segm.mPt2;
}

inline double Segm::ave(double x1, double x2)  {
    return (x1 + x2) / 2.0;
}

inline double Segm::Deg2Rad(int deg) const {
    return deg * PI / 180.0;
}

#endif