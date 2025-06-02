//
// Created by Arsany on 6/2/2025.
//

#ifndef SKETCHER_ELLIPSEMIDPOINT_H
#define SKETCHER_ELLIPSEMIDPOINT_H
#include "Shape.h"
#include "Point.h"

class EllipseMidpoint : public Shape {
    Point center;
    Point radiusX;
    Point radiusY;
    static void draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);
public:
    EllipseMidpoint(Point center, Point radiusX, Point radiusY, COLORREF c);
    void draw(HDC hdc, COLORREF c);
};
#endif //SKETCHER_ELLIPSEMIDPOINT_H
