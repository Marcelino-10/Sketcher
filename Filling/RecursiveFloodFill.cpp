#include "RecursiveFloodFill.h"

RecursiveFloodFill::RecursiveFloodFill(COLORREF cf, COLORREF cb, Point begin) : Filling(cf, cb), begin(begin){}

void RecursiveFloodFill::fill(HDC hdc) {
    recFill(hdc, (int) begin.x, (int) begin.y);
}

void RecursiveFloodFill::recFill(HDC hdc, int x, int y) {
    COLORREF c = GetPixel(hdc, x, y);
    if(c == cf || c == cb)
        return;

    SetPixel(hdc, x, y, cf);
    recFill(hdc, x + 1, y);
    recFill(hdc, x - 1, y);
    recFill(hdc, x, y + 1);
    recFill(hdc, x, y - 1);
}

string RecursiveFloodFill::serialize() {
    stringstream ss;

    ss << "RecursiveFloodFill " << cf << " " << cb
            << " " << begin.x << " " << begin.y;
    return ss.str();
}

Filling *RecursiveFloodFill::deserialize(std::istream &in) {
    COLORREF cf, cb;
    Point begin;
    in >> cf >> cb >> begin.x >> begin.y;
    return new RecursiveFloodFill(cf, cb, begin);
}
