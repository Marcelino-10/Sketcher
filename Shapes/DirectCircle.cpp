#include "DirectCircle.h"
DirectCircle::DirectCircle(Point center, Point p, COLORREF c): Shape(c), center(center), p(p) {}

void DirectCircle::draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c) {
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc + y, yc + x, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc + y, yc - x, c);
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc - y, yc + x, c);
    SetPixel(hdc, xc - x, yc - y, c);
    SetPixel(hdc, xc - y, yc - x, c);
}

void DirectCircle::draw(HDC hdc, COLORREF c) {
    int xc = center.x;
    int yc = center.y;
    int R = static_cast<int>(sqrt(pow(p.x - xc, 2) + pow(p.y - yc, 2)));

    int x = 0, y=R;
    while (x <y) {
        y = round(sqrt(R * R - x * x));
        draw8Points(hdc, xc, yc, x, y, c);
        x++;
    }
}
std::string DirectCircle::serialize()  {
    std::ostringstream ss;
    ss << "DirectCircle " << color << " "
       << center.x << " " << center.y << " "
       << p.x << " " << p.y;
    return ss.str();
}

Shape* DirectCircle::deserialize(std::istream &in) {
    COLORREF color;
    double cx, cy, px, py;
    in >> color >> cx >> cy >> px >> py;
    return new DirectCircle(Point{cx, cy}, Point{px, py}, color);
}