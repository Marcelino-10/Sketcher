#include "GeneralPolygon.h"

GeneralPolygon::GeneralPolygon(vector<Point> &v) : v(v){}

void GeneralPolygon::draw(HDC hdc) {
    Point p = v[v.size() - 1];
    for (int i = 0; i < v.size(); ++i) {
        LinesDDA l(p, v[i]);
        l.draw(hdc);
        p = v[i];
    }
}