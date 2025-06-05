#ifndef GRAPHICSPROJECT_GENERALPOLYGON_H
#define GRAPHICSPROJECT_GENERALPOLYGON_H

#include "Shape.h"
#include "Point.h"
#include "LinesDDA.h"
#include <vector>

using namespace std;

class GeneralPolygon : public Shape {
    vector<Point> v;
public:
    GeneralPolygon(vector<Point> &v, COLORREF c);
    void draw(HDC hdc, COLORREF c);
    std::string serialize() override;
    static Shape* deserialize(std::istream &in);
};

#endif //GRAPHICSPROJECT_GENERALPOLYGON_H
