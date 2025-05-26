#include "RecursiveFloodFill.h"

RecursiveFloodFill::RecursiveFloodFill(COLORREF cf, COLORREF cb, Point begin) : Filling(cf, cb), begin(begin){}

void RecursiveFloodFill::fill(HDC hdc) {
    COLORREF c = GetPixel(hdc, begin.x, begin.y);
    if(c == cf || c == cb)
        return;

    begin.x--;
    fill(hdc);
    begin.y--;
    fill(hdc);
    begin.x++;
    fill(hdc);
    begin.y++;
    fill(hdc);
}