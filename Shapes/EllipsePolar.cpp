
#include "EllipsePolar.h"
#include <cmath>

EllipsePolar::EllipsePolar(Point center, Point radiusX, Point radiusY, COLORREF c)
        : Shape(c), center(center), radiusX(radiusX), radiusY(radiusY) {}

void EllipsePolar::draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c) {
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc - x, yc - y, c);
}

void EllipsePolar::draw(HDC hdc, COLORREF c) {
    int xc = center.x;
    int yc = center.y;
    int a = static_cast<int>(sqrt(pow(radiusX.x - xc, 2) + pow(radiusX.y - yc, 2)));
    int b = static_cast<int>(sqrt(pow(radiusY.x - xc, 2) + pow(radiusY.y - yc, 2)));

    const int n = 1000;
    double dtheta = 1.0 / n;
    double cd = cos(dtheta);
    double sd = sin(dtheta);

    double X = a;
    double Y = 0;

    draw4Points(hdc, xc, yc, (int)X, (int)Y, c);

    while (X > 0) {
        double Xtemp = X * cd - (a * Y / b) * sd;
        Y = Y * cd + (b * X / a) * sd;
        X = Xtemp;

        draw4Points(hdc, xc, yc, (int)X, (int)Y, c);
    }
}
std::string EllipsePolar::serialize() {
    std::ostringstream ss;
    ss << "EllipsePolar " << color << " "
       << center.x << " " << center.y << " "
       << radiusX.x << " " << radiusX.y << " "
       << radiusY.x << " " << radiusY.y;
    return ss.str();
}

Shape* EllipsePolar::deserialize(std::istream &in) {
    COLORREF color;
    double cx, cy, rx, ry, rxx, ryy;
    in >> color >> cx >> cy >> rx >> ry >> rxx >> ryy;
    return new EllipsePolar({cx, cy}, {rx, ry}, {rxx, ryy}, color);
}