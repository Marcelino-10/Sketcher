#ifndef GRAPHICSPROJECT_SHAPE_H
#define GRAPHICSPROJECT_SHAPE_H

#include "windows.h"

class Shape {
    COLORREF c;
public:
    inline Shape(COLORREF c){
        this->c = c;
    }
    virtual void draw(HDC hdc, COLORREF c) = 0;
};

#endif //GRAPHICSPROJECT_SHAPE_H
