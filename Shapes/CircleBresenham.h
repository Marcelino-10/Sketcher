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
    string serialize() override;
    static Shape* deserialize(istream &in);
};

inline void draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c){
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc + y, yc + x, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc + y, yc - x, c);
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc - y, yc + x, c);
    SetPixel(hdc, xc - x, yc - y, c);
    SetPixel(hdc, xc - y, yc - x, c);
}

#endif //GRAPHICSPROJECT_CIRCLEBRESENHAM_H
