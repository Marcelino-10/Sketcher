#ifndef GRAPHICSPROJECT_HERMITECURVE_H
#define GRAPHICSPROJECT_HERMITECURVE_H

#include "Shape.h"
#include "../Point.h"
#include <vector>

using namespace std;

class HermiteCurve : public Shape {
    vector<Point> v;
    int numPoints;

public:
    HermiteCurve(vector<Point> &v, int numPoints, COLORREF c);
    void draw(HDC hdc, COLORREF c);
};


#endif //GRAPHICSPROJECT_HERMITECURVE_H
