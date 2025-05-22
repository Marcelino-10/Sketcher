//
// Created by Marcelino on 5/23/2025.
//

#ifndef GRAPHICSPROJECT_FLOODFILL_H
#define GRAPHICSPROJECT_FLOODFILL_H

#include "Filling.h"
#include <stack>

using namespace std;

class FloodFill : public Filling{
    Point begin;
public:
    FloodFill(COLORREF cf, COLORREF cb, Point begin);
    void fill(HDC hdc);
};


#endif //GRAPHICSPROJECT_FLOODFILL_H
