#include "LineBresenham.h"

LineBresenham::LineBresenham(Point p1, Point p2, COLORREF c) : Shape(c), p1(p1), p2(p2){}

void LineBresenham::draw(HDC hdc, COLORREF c) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    if (dx >= dy) {
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        int sign = (y2 > y1) ? 1 : -1;
        int d = dx  - 2 * dy;
        int d1 = 2 * dx - 2 * dy;
        int d2 = -2 * dy;
        int x = x1, y = y1;
        SetPixel(hdc, x, y, c);
        while (x < x2) {
            if (d <= 0) {
                d += d1;
                y += sign;
            }
            else
                d += d2;
            x++;
            SetPixel(hdc, x, y, c);
        }
    }
    else {
        if (y1 > y2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        int sign = (x2 > x1) ? 1 : -1;
        int d = 2 * dx - dy;
        int d1 = 2 * dx - 2 * dy;
        int d2 = 2 * dx;
        int x = x1, y = y1;
        SetPixel(hdc, x, y, c);
        while (y < y2) {
            if (d >= 0) {
                d += d1;
                x += sign;
            }
            else
                d += d2;
            y++;
            SetPixel(hdc, x, y, c);
        }
    }
}

