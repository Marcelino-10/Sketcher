#include "CardinalSpline.h"

CardinalSpline::CardinalSpline(vector<Point> v, int c, int numPoints, COLORREF co) : Shape(co), v(v), c(c), numPoints(numPoints){}

void CardinalSpline::draw(HDC hdc, COLORREF co) {
    vector<Point> q;
    for (int i = 1; i < v.size() - 1; ++i) {
        q.emplace_back((v[i + 1] - v[i - 1]) * (c / 2));
    }
    for (int i = 0; i < q.size() - 1; ++i) {
        vector<Point> arr = {v[i + 1], q[i], v[i + 2], q[i + 1]};
        HermiteCurve h(arr, numPoints, co);
        h.draw(hdc, co);
    }
}
string CardinalSpline::serialize() {
    stringstream ss;
    ss << "CardinalSpline " << this->color << " " << numPoints <<" "<<c << " " << v.size();
    for (const Point &p : v)
        ss << " " << p.x << " " << p.y;
    return ss.str();
}

Shape* CardinalSpline::deserialize(istream &in) {
    COLORREF color;
    int numPts, vecSize,c;
    in >> color >> numPts>> c >> vecSize;
    vector<Point> vec(vecSize);
    for (int i = 0; i < vecSize; ++i) {
        in >> vec[i].x >> vec[i].y;
    }
    return new CardinalSpline(vec,c, numPts, color);
}