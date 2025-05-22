#ifndef GRAPHICSPROJECT_SHAPE_H
#define GRAPHICSPROJECT_SHAPE_H

#include "windows.h"

class Shape {
public:
    virtual void draw(HDC hdc) = 0;
};

#endif //GRAPHICSPROJECT_SHAPE_H
