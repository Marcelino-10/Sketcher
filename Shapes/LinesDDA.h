#ifndef GRAPHICSPROJECT_LINESDDA_H
#define GRAPHICSPROJECT_LINESDDA_H

#include "Shape.h"
#include "Point.h"
#include <vector>

using namespace std;

class LinesDDA : public Shape{
    Point p1, p2;
public:
    LinesDDA(Point p1, Point p2, COLORREF c);
    void draw(HDC hdc, COLORREF c) override;
    std::string serialize() override;
    static Shape* deserialize(std::istream &in);
};

void LineeDDA(HDC hdc, Point p1, Point p2, COLORREF c);


#endif //GRAPHICSPROJECT_LINESDDA_H
