#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;

void Point::Translate(double vx, double vy) {
    setX(mx += vx);
    setY(my += vy);
}

void Point::Rotate(double rad) {
    double tempX;
    double tempY;
    tempX = round(mx * cos(rad) - my * sin(rad));
    tempY = round(mx * sin(rad) + my * cos(rad));
    mx = tempX;
    my = tempY;

}

void Point::readPoint() {

    double tempX, tempY;
    cin >> tempX >> tempY;
    setX(tempX);
    setY(tempY );

}