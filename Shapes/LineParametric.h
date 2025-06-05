#ifndef GRAPHICSPROJECT_LINEPARAMETRIC_H
#define GRAPHICSPROJECT_LINEPARAMETRIC_H

#include "Shape.h"
#include "Point.h"
#include <algorithm>

using namespace std;

class LineParametric : public Shape {
    Point p1, p2;
public:
    LineParametric(Point p1, Point p2, COLORREF c);
    void draw(HDC hdc, COLORREF c) override;
    std::string serialize() override;
    static Shape* deserialize(std::istream &in);
};



#endif //GRAPHICSPROJECT_LINEPARAMETRIC_H
