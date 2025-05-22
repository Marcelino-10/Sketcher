#ifndef GRAPHICSPROJECT_BEZIERCURVEMIDPOINT_H
#define GRAPHICSPROJECT_BEZIERCURVEMIDPOINT_H

#include "Shape.h"
#include "Point.h"
#include <vector>

using namespace std;

class BezierCurveMidpoint : public Shape {
    vector<Point> v;
    int numPoints;

public:
    BezierCurveMidpoint(vector<Point> &v, int numPoints);
    void draw(HDC hdc);
    void BezierCurveDrawing(HDC hdc, vector<Point> p, COLORREF c);
};


#endif //GRAPHICSPROJECT_BEZIERCURVEMIDPOINT_H
