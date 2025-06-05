#ifndef GRAPHICSPROJECT_CIRCLECIRCLESFILLING_H
#define GRAPHICSPROJECT_CIRCLECIRCLESFILLING_H

#include "Filling.h"
#include "../Shapes/Point.h"


class CircleCirclesFilling : public Filling {
    int step;
    Point center;
    Point p;
    int quarter;
public:
    CircleCirclesFilling(COLORREF cf, Point center, Point p, int step, int quarter);
    void fill(HDC hdc);
    string serialize() override;
    static Filling* deserialize(std::istream &in);

};


#endif //GRAPHICSPROJECT_CIRCLECIRCLESFILLING_H
