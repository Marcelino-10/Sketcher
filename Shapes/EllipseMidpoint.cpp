
#include "EllipseMidpoint.h"
#include <cmath>

EllipseMidpoint::EllipseMidpoint(Point center, Point radiusX, Point radiusY, COLORREF c)
        : Shape(c), center(center), radiusX(radiusX), radiusY(radiusY) {}

void EllipseMidpoint::draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c) {
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc - x, yc - y, c);
}

void EllipseMidpoint::draw(HDC hdc, COLORREF c) {
    int xc = center.x;
    int yc = center.y;
    int a = static_cast<int>(sqrt(pow(radiusX.x - xc, 2) + pow(radiusX.y - yc, 2)));
    int b = static_cast<int>(sqrt(pow(radiusY.x - xc, 2) + pow(radiusY.y - yc, 2)));


    int a2 = a * a;
    int b2 = b * b;

    int x = 0;
    int y = b;
    int px = 0;
    int py = 2 * a2 * y;

    draw4Points(hdc, xc, yc, x, y, c);

    int p1 = b2 - (a2 * b) + (a2 * 0.25);
    while (px < py) {
        x++;
        px += 2 * b2;

        if (p1 < 0) {
            p1 += b2 + px;
        } else {
            y--;
            py -= 2 * a2;
            p1 += b2 + px - py;
        }
        draw4Points(hdc, xc, yc, x, y, c);
    }

    int p2 = b2 * (x - 0.5) * (x - 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y > 0) {
        y--;
        py -= 2 * a2;

        if (p2 > 0) {
            p2 += a2 - py;
        } else {
            x++;
            px += 2 * b2;
            p2 += a2 - py + px;
        }
        draw4Points(hdc, xc, yc, x, y, c);
    }
}
std::string EllipseMidpoint::serialize() {
    std::ostringstream ss;
    ss << "EllipseMidpoint " << color << " "
       << center.x << " " << center.y << " "
       << radiusX.x << " " << radiusX.y << " "
       << radiusY.x << " " << radiusY.y;
    return ss.str();
}

Shape* EllipseMidpoint::deserialize(std::istream &in) {
    COLORREF color;
    double cx, cy, rx, ry, rxx, ryy;
    in >> color >> cx >> cy >> rx >> ry >> rxx >> ryy;
    return new EllipseMidpoint({cx, cy}, {rx, ry}, {rxx, ryy}, color);
}