#ifndef GRAPHICSPROJECT_RECURSIVEFLOODFILL_H
#define GRAPHICSPROJECT_RECURSIVEFLOODFILL_H

#include "Filling.h"

class RecursiveFloodFill : public Filling {
    Point begin;
public:
    RecursiveFloodFill(COLORREF cf, COLORREF cb, Point begin);
    void fill(HDC hdc);
};


#endif //GRAPHICSPROJECT_RECURSIVEFLOODFILL_H
