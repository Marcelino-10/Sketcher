#ifndef GRAPHICSPROJECT_RECURSIVEFLOODFILL_H
#define GRAPHICSPROJECT_RECURSIVEFLOODFILL_H

#include "Filling.h"

class RecursiveFloodFill : public Filling {
    Point begin;
public:
    RecursiveFloodFill(COLORREF cf, COLORREF cb, Point begin);
    void fill(HDC hdc);
    void recFill(HDC hdc, int x, int y);
    std::string serialize() override;
    static Filling* deserialize(std::istream &in);
};


#endif //GRAPHICSPROJECT_RECURSIVEFLOODFILL_H
