#ifndef SKETCHER_CIRCLELINEFILLING_H
#define SKETCHER_CIRCLELINEFILLING_H
#include "Filling.h"
#include "../Shapes/LinesDDA.h"
#include <cmath>

class CircleLineFilling : public Filling {
    Point center;
    Point p;
    int quarter;
public:
    CircleLineFilling(Point center, Point p, int quarter, COLORREF cf);
    void fill(HDC hdc) override;
    string serialize() override;
    static Filling* deserialize(std::istream &in);
};
#endif //SKETCHER_CIRCLELINEFILLING_H
