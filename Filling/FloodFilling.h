#ifndef GRAPHICSPROJECT_FLOODFILLING_H
#define GRAPHICSPROJECT_FLOODFILLING_H

#include "Filling.h"
#include <stack>

using namespace std;

class FloodFilling : public Filling{
    Point begin;
public:
    FloodFilling(COLORREF cf, COLORREF cb, Point begin);
    void fill(HDC hdc);
    std::string serialize() override;
    static Filling* deserialize(std::istream &in);
};


#endif //GRAPHICSPROJECT_FLOODFILLING_H
