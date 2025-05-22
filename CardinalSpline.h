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
    CardinalSpline(vector<Point> v, int c, int numPoints);
    void draw(HDC hdc);
};


#endif //GRAPHICSPROJECT_CARDINALSPLINE_H
