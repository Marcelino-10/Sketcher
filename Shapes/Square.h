//
// Created by Arsany on 6/2/2025.
//

#ifndef SKETCHER_SQUARE_H
#define SKETCHER_SQUARE_H
#include "Shape.h"
#include "Point.h"
#include "LinesDDA.h"

class Square : public Shape {
    Point point1;
    Point point2;
    Point vertices[4];
    void calculateVertices();
public:
    Square(Point p1, Point p2, COLORREF c);
    void draw(HDC hdc, COLORREF c);
};
#endif //SKETCHER_SQUARE_H
