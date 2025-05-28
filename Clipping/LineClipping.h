#ifndef GRAPHICSPROJECT_LINECLIPPING_H
#define GRAPHICSPROJECT_LINECLIPPING_H

#include "Clipping.h"

class LineClipping : public Clipping{
    vector<Point> v;
    int xLeft, xRight, yTop, yBottom;
public:
    LineClipping(vector<Point> v, int xLeft, int xRight, int yTop, int yBottom);
    void clip(HDC hdc, vector<Point> &p);
};


#endif //GRAPHICSPROJECT_LINECLIPPING_H
