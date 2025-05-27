#ifndef GRAPHICSPROJECT_LINEBRESENHAM_H
#define GRAPHICSPROJECT_LINEBRESENHAM_H

#include "Shape.h"
#include "Point.h"
#include <algorithm>

using namespace std;

class LineBresenham : public Shape {
    Point p1, p2;
public:
    LineBresenham(Point p1, Point p2, COLORREF c);
    void draw(HDC hdc, COLORREF c);
};


#endif //GRAPHICSPROJECT_LINEBRESENHAM_H
