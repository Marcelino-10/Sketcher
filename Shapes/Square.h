
#ifndef SKETCHER_SQUARE_H
#define SKETCHER_SQUARE_H
#include "Shape.h"
#include "Point.h"
#include "LinesDDA.h"

class Square : public Shape {
    Point point1;
    Point point2;
    Point vertices[4];
    bool isFilled;
    COLORREF fillColor;

    void calculateVertices();
    void hermitCurveFill(HDC hdc, COLORREF c);
    void drawHermitLine(HDC hdc, Point p0, Point p1, Point t0, Point t1, COLORREF c);
    Point hermitPoint(Point p0, Point p1, Point t0, Point t1, double t);

public:
    Square(Point p1, Point p2, COLORREF c);
    void draw(HDC hdc, COLORREF c);
    void fill(HDC hdc, COLORREF c);
    int getMinY();
    int getMaxY();
    int getLeftX(int y);
    int getRightX(int y);
    std::string serialize() override;
    static Shape* deserialize(std::istream &in);
};

#endif //SKETCHER_SQUARE_H