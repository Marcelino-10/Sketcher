
#ifndef SKETCHER_DIRECTCIRCLE_H
#define SKETCHER_DIRECTCIRCLE_H
#include "Shape.h"
#include "Point.h"
class DirectCircle : public Shape {
    Point center;
    Point p;
    static void draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);
public:
    DirectCircle(Point center, Point p, COLORREF c);
    void draw(HDC hdc, COLORREF c);
    string serialize() override;
    static Shape* deserialize(istream &in);
};


#endif //SKETCHER_DIRECTCIRCLE_H
