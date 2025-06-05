#ifndef SKETCHER_ITERATIVEPOLAR_H
#define SKETCHER_ITERATIVEPOLAR_H
#include "Shape.h"
#include "Point.h"
class IterativePolar : public Shape {
Point center;
Point p;

static void draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);

public:
IterativePolar(Point center, Point p, COLORREF c);
void draw(HDC hdc, COLORREF c) override;
std::string serialize() override;
static Shape* deserialize(std::istream &in);
};

#endif //SKETCHER_ITERATIVEPOLAR_H
