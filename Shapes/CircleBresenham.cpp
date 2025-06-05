#include "CircleBresenham.h"
#include <cmath>

CircleBresenham::CircleBresenham(Point center, Point p, COLORREF c) : Shape(c), center(center), p(p) {}

void CircleBresenham::draw(HDC hdc, COLORREF c) {
    auto [xc, yc] = center;
    double r = distance(p, center);
    int x = 0, y = (int)r, d = 1 - r;
    int d1 = 3, d2 = 5 - (2 * r);

    draw8Points(hdc, (int)xc, (int)yc, x, y, c);
    while (x < y) {
        x++;
        d1 += 2;
        if (d < 0) {
            d += d1;
            d2 += 2;
        } else {
            d += d2;
            d2 += 4;
            y--;
        }
        draw8Points(hdc, (int)xc, (int)yc, x, y, c);
    }
}

std::string CircleBresenham::serialize()  {
    std::ostringstream ss;
    ss << "CircleBresenham " << color << " "
       << center.x << " " << center.y << " "
       << p.x << " " << p.y;
    return ss.str();
}

Shape* CircleBresenham::deserialize(std::istream &in) {
    COLORREF color;
    double cx, cy, px, py;
    in >> color >> cx >> cy >> px >> py;
    return new CircleBresenham(Point{cx, cy}, Point{px, py}, color);
}
