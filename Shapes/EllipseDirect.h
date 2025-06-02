//
// Created by Arsany on 6/2/2025.
//

#ifndef SKETCHER_ELLIPSEDIRECT_H
#define SKETCHER_ELLIPSEDIRECT_H
#include "Shape.h"
#include "Point.h"
class EllipseDirect : public Shape{
    Point center;
    Point radiusX;
    Point radiusY;
    static void draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);
public:
    EllipseDirect (Point center, Point radiusX, Point radiusY, COLORREF c);
    void draw(HDC hdc, COLORREF c);
};

#endif //SKETCHER_ELLIPSEDIRECT_H
