//
// Created by Arsany on 6/2/2025.
//
#ifndef SKETCHER_ELLIPSEPOLAR_H
#define SKETCHER_ELLIPSEPOLAR_H
#include "Shape.h"
#include "Point.h"

class EllipsePolar : public Shape {
    Point center;
    Point radiusX;
    Point radiusY;
    static void draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);
public:
    EllipsePolar(Point center, Point radiusX, Point radiusY, COLORREF c);
    void draw(HDC hdc, COLORREF c);
    std::string serialize() override;
    static Shape* deserialize(std::istream &in);
};
#endif //SKETCHER_ELLIPSEPOLAR_H
