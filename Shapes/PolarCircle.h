#ifndef SKETCHER_POLARCIRCLE_H
#define SKETCHER_POLARCIRCLE_H

#include "Shape.h"
#include "Point.h"

class PolarCircle : public Shape {
    Point center;
    Point p;

    static void draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);

public:
    PolarCircle(Point center, Point p, COLORREF c);

    void draw(HDC hdc, COLORREF c) override;

    std::string serialize() override;

    static Shape *deserialize(std::istream &in);
};

#endif //SKETCHER_POLARCIRCLE_H
