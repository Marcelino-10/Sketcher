#ifndef GRAPHICSPROJECT_CARDINALSPLINE_H
#define GRAPHICSPROJECT_CARDINALSPLINE_H

#include "Shape.h"
#include "Point.h"
#include "HermiteCurve.h"
#include <vector>

using namespace std;

class CardinalSpline : public Shape {
    vector<Point> v;
    int c;
    int numPoints;

public:
    CardinalSpline(vector<Point> v, int c, int numPoints, COLORREF co);
    void draw(HDC hdc, COLORREF c);
};


#endif //GRAPHICSPROJECT_CARDINALSPLINE_H
