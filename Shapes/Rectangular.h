
#ifndef SKETCHER_RECTANGULAR_H
#define SKETCHER_RECTANGULAR_H

#include "Shape.h"
#include "Point.h"

class Rectangular : public Shape {
    Point point1;
    Point point2;
    Point vertices[4];
    bool isFilled;
    COLORREF fillColor;

    void calculateVertices();

    void bezierCurveFill(HDC hdc, COLORREF c);

    int getMinY();

    int getMaxY();

    int getLeftX(int y);

    int getRightX(int y);

public:
    Rectangular(Point first, Point second, COLORREF c);

    void draw(HDC hdc, COLORREF c);

    void fill(HDC hdc, COLORREF c);
    std::string serialize() override;
    static Shape* deserialize(std::istream &in);
};

#endif //SKETCHER_RECTANGULAR_H
