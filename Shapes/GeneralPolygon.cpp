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
string GeneralPolygon::serialize() {
    stringstream ss;
    ss << "GeneralPolygon " << this->color << " " << v.size();
    for (const Point &p : v)
        ss << " " << p.x << " " << p.y;
    return ss.str();
}

Shape* GeneralPolygon::deserialize(istream &in) {
    COLORREF color;
    int  vecSize;
    in >> color >> vecSize;
    vector<Point> vec(vecSize);
    for (int i = 0; i < vecSize; ++i) {
        in >> vec[i].x >> vec[i].y;
    }
    return new GeneralPolygon(vec, color);
}