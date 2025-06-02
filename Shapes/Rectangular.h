//
// Created by Arsany on 6/2/2025.
//

#ifndef SKETCHER_RECTANGULAR_H
#define SKETCHER_RECTANGULAR_H
#include "Shape.h"
#include "Point.h"
class Rectangular : public Shape {
    Point point1;
    Point point2;
    Point point3;
    Point vertices[4];
    void calculateVertices();
public:
    Rectangular(Point start, Point width, Point height, COLORREF c);
    void draw(HDC hdc, COLORREF c);
};
#endif //SKETCHER_RECTANGULAR_H
