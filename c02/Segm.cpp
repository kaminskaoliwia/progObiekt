#include "Segm.h"

void Segm::Translate(double vx, double vy) {
    mPt1.setX(mPt1.getX() + vx);
    mPt1.setY(mPt1.getY() + vy);
    mPt2.setX(mPt2.getX() + vx);
    mPt2.setY(mPt2.getY() + vy);
}

void Segm::Rotate(int deg) {
    // konwersja stopni do radianow
    double rad = Deg2Rad(deg);

    // obliczyc wspolrzedne srodka odcinka
    int tempX;
    int tempY;
    tempX = ave(mPt1.getX(), mPt2.getX());
    tempY = ave(mPt1.getY(), mPt2.getY());
    Point mid = Point(tempX, tempY);

    // translacja o wektor [-vx, -vy]
    Translate(-mid.getX(), -mid.getY());
    // obrot konxow odcinka o kat w radianach
    mPt1.Rotate(rad);
    mPt2.Rotate(rad);
    // translacja obroconego odcinka o wektor [vx, vy]
    Translate(mid.getX(), mid.getY());
}

double Segm::segmLen() const {
    double dx = mPt2.getX() - mPt1.getX();
    double dy = mPt2.getY() - mPt1.getY();
    return sqrt(dx * dx + dy * dy);
}
