#include "Clipping.h"

Clipping::Clipping(vector<Point> v, int xLeft, int xRight, int yTop, int yBottom) : v(v),
    xLeft(xLeft), xRight(xRight),yTop(yTop), yBottom(yBottom){}