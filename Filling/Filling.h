#ifndef GRAPHICSPROJECT_FILLING_H
#define GRAPHICSPROJECT_FILLING_H

#include <windows.h>
#include "../Shapes/Point.h"
#include <sstream>
using namespace std;
class Filling {
protected:
    COLORREF cf, cb;
public:
    Filling(COLORREF cf, COLORREF cb);
    virtual void fill(HDC hdc) = 0; // cf -> filling color, cb -> boundary color
    virtual string serialize() =0;
};

#endif //GRAPHICSPROJECT_FILLING_H
