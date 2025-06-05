#ifndef SKETCHER_ELLIPSEMIDPOINT_H
#define SKETCHER_ELLIPSEMIDPOINT_H

#include "Shape.h"
#include "Point.h"
#include <sstream>

class EllipseMidpoint : public Shape {
    Point center;
    Point radiusX;
    Point radiusY;
    static void draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);

public:
    EllipseMidpoint(Point center, Point radiusX, Point radiusY, COLORREF c);
    void draw(HDC hdc, COLORREF c) override;

    // Serialization
    std::string serialize() override;
    static Shape* deserialize(std::istream &in);
};

#endif //SKETCHER_ELLIPSEMIDPOINT_H