#ifndef GRAPHICSPROJECT_SHAPE_H
#define GRAPHICSPROJECT_SHAPE_H

#include <vector>
#include "windows.h"
#include <vector>
#include <sstream>
using namespace std;
class Shape {
public:
    COLORREF color;
    inline Shape(COLORREF c){
        this->color = c;
    }
    virtual void draw(HDC hdc, COLORREF c) = 0;
    virtual std::string serialize()=0;
};
#endif //GRAPHICSPROJECT_SHAPE_H
