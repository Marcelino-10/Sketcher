#ifndef GRAPHICSPROJECT_BEZIERCURVE_H
#define GRAPHICSPROJECT_BEZIERCURVE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

using namespace std;

class BezierCurve : public Shape {
    vector<Point> v;
    int numPoints;

public:
    BezierCurve(vector<Point> &v, int numPoints);
    void draw(HDC hdc) override;
    Point recBezierCurve(int l, int r, vector<Point> &v, double t);
};


#endif //GRAPHICSPROJECT_BEZIERCURVE_H
