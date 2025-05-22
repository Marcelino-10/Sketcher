#ifndef GRAPHICSPROJECT_BEZIERCURVEMATRIX_H
#define GRAPHICSPROJECT_BEZIERCURVEMATRIX_H

#include "Shape.h"
#include "Point.h"
#include <vector>

using namespace std;

class BezierCurveMatrix : public Shape {
    vector<Point> v;
    int numPoints;

public:
    BezierCurveMatrix(vector<Point> &v, int numPoints);
    void draw(HDC hdc);
};


#endif //GRAPHICSPROJECT_BEZIERCURVEMATRIX_H
