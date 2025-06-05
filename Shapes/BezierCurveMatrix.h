#ifndef GRAPHICSPROJECT_BEZIERCURVEMATRIX_H
#define GRAPHICSPROJECT_BEZIERCURVEMATRIX_H

#include "Shape.h"
#include "Point.h"
#include <vector>
#include <sstream>
using namespace std;

class BezierCurveMatrix : public Shape {
    vector<Point> v;
    int numPoints;

public:
    BezierCurveMatrix(vector<Point> &v, int numPoints, COLORREF c);
    void draw(HDC hdc, COLORREF c);
    string serialize() override;
    static Shape* deserialize(istream &in);
};


#endif //GRAPHICSPROJECT_BEZIERCURVEMATRIX_H
