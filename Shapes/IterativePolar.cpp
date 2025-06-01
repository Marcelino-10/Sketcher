#include "IterativePolar.h"
#include <cmath>

IterativePolar::IterativePolar(Point center, Point p, COLORREF c): Shape(c), center(center), p(p) {}

void IterativePolar::draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c) {
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc + y, yc + x, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc + y, yc - x, c);
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc - y, yc + x, c);
    SetPixel(hdc, xc - x, yc - y, c);
    SetPixel(hdc, xc - y, yc - x, c);
}

void IterativePolar::draw(HDC hdc, COLORREF c) {
    int xc = center.x;
    int yc = center.y;
    int r = static_cast<int>(sqrt(pow(p.x - xc, 2) + pow(p.y - yc, 2)));

    double dtheta = 1.0 / r;
    double ct = cos(dtheta);
    double st = sin(dtheta);

    double x = r, y = 0;
    while (x >= y) {
        draw8Points(hdc, xc, yc, round(x), round(y), c);
        double x1 = x * ct - y * st;
        y = x * st + y * ct;
        x = x1;
    }
}
