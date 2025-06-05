#ifndef GRAPHICSPROJECT_BEZIERCURVE_H
#define GRAPHICSPROJECT_BEZIERCURVE_H

#include "Shape.h"
#include "Point.h"
#include <vector>
#include <sstream>

using namespace std;

class BezierCurve : public Shape {
    vector<Point> v;
    int numPoints;

public:
    BezierCurve(vector<Point> &v, int numPoints, COLORREF c);
    void draw(HDC hdc, COLORREF c) override;
    Point recBezierCurve(int l, int r, vector<Point> &v, double t);

    // New methods for serialization
    string serialize() override;
    static Shape* deserialize(istream &in);
};

#endif // GRAPHICSPROJECT_BEZIERCURVE_H