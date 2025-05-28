#ifndef GRAPHICSPROJECT_POLYGONCLIPPING_H
#define GRAPHICSPROJECT_POLYGONCLIPPING_H

#include "Clipping.h"

class PolygonClipping : public Clipping {
    vector<Point> v;
    int xLeft, xRight, yTop, yBottom;
public:
    PolygonClipping(vector<Point> v, int xLeft, int xRight, int yTop, int yBottom);
    void clip(HDC hdc, vector<Point> &v);
};


#endif //GRAPHICSPROJECT_POLYGONCLIPPING_H
