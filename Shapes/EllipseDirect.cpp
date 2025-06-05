

#include "EllipseDirect.h"
EllipseDirect::EllipseDirect(Point center, Point radiusX, Point radiusY, COLORREF c)
        : Shape(c), center(center), radiusX(radiusX), radiusY(radiusY) {}

void EllipseDirect::draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c) {
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc - x, yc - y, c);
}
void EllipseDirect::draw(HDC hdc, COLORREF c) {
    int xc = center.x;
    int yc = center.y;
    int a = static_cast<int>(sqrt(pow(radiusX.x - xc, 2) + pow(radiusX.y - yc, 2)));
    int b = static_cast<int>(sqrt(pow(radiusY.x - xc, 2) + pow(radiusY.y - yc, 2)));

    for (int x = 0; x <= a; x++) {
        double y_squared = b * b * (1.0 - (double)(x * x) / (double)(a * a));
        if (y_squared >= 0) {
            int y = static_cast<int>(round(sqrt(y_squared)));
            draw4Points(hdc,xc,yc,x,y,c);
        }
    }
    for (int y = 0; y <= b; y++) {
        double x_squared = a * a * (1.0 - (double)(y * y) / (double)(b * b));
        if (x_squared >= 0) {
            int x = static_cast<int>(round(sqrt(x_squared)));
            draw4Points(hdc,xc,yc,x,y,c);

        }
    }
}
string EllipseDirect::serialize() {
    stringstream ss;
    ss << "EllipseDirect " << color << " "
            << center.x << " " << center.y
            << radiusX.x << " " << radiusX.y
            << radiusY.y << " " << radiusY.y;
    return ss.str();
}

Shape *EllipseDirect::deserialize(istream &in) {
    COLORREF color;
    Point c,rx,ry;
    in >> color >> c.x >> c.y >> rx.x>>rx.y>>ry.x>>ry.y;
    return new EllipseDirect(c, rx,ry, color);
}
