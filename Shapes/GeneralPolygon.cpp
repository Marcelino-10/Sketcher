#include "GeneralPolygon.h"

GeneralPolygon::GeneralPolygon(vector<Point> &v, COLORREF c) : Shape(c), v(v){}

void GeneralPolygon::draw(HDC hdc, COLORREF c) {
    Point p = v[v.size() - 1];
    for (int i = 0; i < v.size(); ++i) {
        LinesDDA l(p, v[i], c);
        l.draw(hdc, c);
        p = v[i];
    }
}