#include "BezierCurveMidpoint.h"

BezierCurveMidpoint::BezierCurveMidpoint(vector<Point> &v, int numPoints, COLORREF c) : Shape(c), v(v), numPoints(numPoints){}

void BezierCurveMidpoint::draw(HDC hdc, COLORREF c) {
    this->BezierCurveDrawing(hdc, v, c);
}

void BezierCurveMidpoint::BezierCurveDrawing(HDC hdc, vector<Point> p, COLORREF c) {
    if(distance(p[0], p[3]) <= 1)
        return;
    Point q1 = (p[0] + p[1]) * 0.5;
    Point q2 = (p[1] + p[2]) * 0.5;
    Point q3 = (p[2] + p[3]) * 0.5;
    Point r1 = (q1 + q2) * 0.5;
    Point r2 = (q2 + q3) * 0.5;
    Point mid = (r1 + r2) * 0.5;
    SetPixel(hdc, mid.x, mid.y, c);

    vector<Point> left, right;
    left.push_back(p[0]);
    left.push_back(q1);
    left.push_back(r1);
    left.push_back(mid);

    right.push_back(mid);
    right.push_back(r2);
    right.push_back(q3);
    right.push_back(p[3]);
    BezierCurveDrawing(hdc, left, c);
    BezierCurveDrawing(hdc, right, c);
}
string BezierCurveMidpoint::serialize() {
    stringstream ss;
    ss << "BezierCurveMidpoint " << this->color << " " << numPoints << " " << v.size();
    for (const Point &p : v)
        ss << " " << p.x << " " << p.y;
    return ss.str();
}

Shape* BezierCurveMidpoint::deserialize(istream &in) {
    COLORREF color;
    int numPts, vecSize;
    in >> color >> numPts >> vecSize;
    vector<Point> vec(vecSize);
    for (int i = 0; i < vecSize; ++i) {
        in >> vec[i].x >> vec[i].y;
    }
    return new BezierCurveMidpoint(vec, numPts, color);
}