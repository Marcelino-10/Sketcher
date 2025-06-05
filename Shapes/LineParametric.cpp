#include "LineParametric.h"

LineParametric::LineParametric(Point p1, Point p2, COLORREF c) : Shape(c), p1(p1), p2(p2){}

void LineParametric::draw(HDC hdc, COLORREF c) {
    int mx = max(abs(p2.x - p1.x), abs(p2.y - p1.y));
    double step = 1.0 / mx;
    int alpha1 = p2.x - p1.x, beta1 = p1.x, alpha2 = p2.y - p1.y, beta2 = p1.y;
    double t;
    for(t = 0; t < 1; t += step){
        double x = alpha1 * t + beta1;
        double y = alpha2 * t + beta2;
        SetPixel(hdc, Round(x), Round(y), c);
    }
}
string LineParametric::serialize() {
    stringstream ss;
    ss << "LineParametric " << color << " "
            << p1.x << " " << p1.y
            <<" "<< p2.x << " " << p2.y;
    return ss.str();
}

Shape *LineParametric::deserialize(istream &in) {
    COLORREF color;
    Point p1,p2;
    in >> color >> p1.x >> p1.y >> p2.x>>p2.y;
    return new LineParametric(p1, p2, color);
}