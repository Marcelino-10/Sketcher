#ifndef GRAPHICSPROJECT_CIRCLEBRESENHAM_H
#define GRAPHICSPROJECT_CIRCLEBRESENHAM_H

#include "Shape.h"
#include "Point.h"


class CircleBresenham : public Shape {
    Point center;
    Point p;
public:
    CircleBresenham(Point center, Point p, COLORREF c);
    void draw(HDC hdc, COLORREF c);
};


#endif //GRAPHICSPROJECT_CIRCLEBRESENHAM_H
