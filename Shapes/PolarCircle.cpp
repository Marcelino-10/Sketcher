#include "PolarCircle.h"

PolarCircle::PolarCircle(Point center, Point p, COLORREF c): Shape(c), center(center), p(p) {}

void PolarCircle::draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c) {
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc + y, yc + x, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc + y, yc - x, c);
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc - y, yc + x, c);
    SetPixel(hdc, xc - x, yc - y, c);
    SetPixel(hdc, xc - y, yc - x, c);
}

void PolarCircle::draw(HDC hdc, COLORREF c) {
    int xc = center.x;
    int yc = center.y;
    int R = static_cast<int>(sqrt(pow(p.x - xc, 2) + pow(p.y - yc, 2)));

    double theta = 0;
    double dtheta = 1.0 / R;

    while (theta <= 3.14159 / 4) {
        int x = round(R * cos(theta));
        int y = round(R * sin(theta));
        draw8Points(hdc, xc, yc, x, y, c);
        theta += dtheta;
    }
}
