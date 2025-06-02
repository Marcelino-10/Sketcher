#include "CircleLineFilling.h"

CircleLineFilling::CircleLineFilling(Point center, Point p, int quarter, COLORREF cf)
        : Filling(cf, cf), center(center), p(p), quarter(quarter) {}
void CircleLineFilling::fill(HDC hdc) {
    int xc = (int) center.x;
    int yc = (int) center.y;
    int R = static_cast<int>(sqrt(pow(p.x - xc, 2) + pow(p.y - yc, 2)));

    for (int y = 0; y <= R; ++y) {
        int x = static_cast<int>(sqrt(R * R - y * y));

        switch (quarter) {
            case 1:
                if (x > 0) LineeDDA(hdc, Point(xc, yc - y), Point(xc + x, yc - y), cf);
                break;
            case 2:
                if (x > 0) LineeDDA(hdc, Point(xc - x, yc - y), Point(xc, yc - y), cf);
                break;
            case 3:
                if (x > 0) LineeDDA(hdc, Point(xc - x, yc + y), Point(xc, yc + y), cf);
                break;
            case 4:
                if (x > 0) LineeDDA(hdc, Point(xc, yc + y), Point(xc + x, yc + y), cf);
                break;
        }
    }


    for (int x = 0; x <= R; ++x) {
        int y = static_cast<int>(sqrt(R * R - x * x));

        switch (quarter) {
            case 1:
                if (y > 0) LineeDDA(hdc, Point(xc + x, yc - y), Point(xc + x, yc), cf);
                break;
            case 2:
                if (y > 0) LineeDDA(hdc, Point(xc - x, yc - y), Point(xc - x, yc), cf);
                break;
            case 3:
                if (y > 0) LineeDDA(hdc, Point(xc - x, yc), Point(xc - x, yc + y), cf);
                break;
            case 4:
                if (y > 0) LineeDDA(hdc, Point(xc + x, yc), Point(xc + x, yc + y), cf);
                break;
        }
    }
}