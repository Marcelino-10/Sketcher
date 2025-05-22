#include "Point.h"

Point::Point(double x, double y): x(x), y(y) {}

Point Point::operator* (double d) const {
    return (Point(this->x * d, this->y * d));
}

Point Point::operator+(Point p) const {
    p.x += this->x;
    p.y += this->y;
    return p;
}

Point Point::operator-(Point p) const {
    p.x -= this->x;
    p.y -= this->y;
    return p;
}