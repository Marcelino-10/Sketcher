#include "BezierCurve.h"

BezierCurve::BezierCurve(vector<Point> &v, int numPoints, COLORREF c) : Shape(c), v(v), numPoints(numPoints) {}

void BezierCurve::draw(HDC hdc, COLORREF c) {
    double step = 1.0 / numPoints;
    for(double t = 0; t < 1; t += step){
        Point pi = recBezierCurve(0, v.size() - 1, v, t);
        SetPixel(hdc, Round(pi.x), Round(pi.y), c);
    }
}

Point BezierCurve::recBezierCurve(int l, int r, vector<Point> &v, double t) {
    if(l == r)
        return v[l];
    return (recBezierCurve(l, r - 1, v, t)) * (1 - t) + (recBezierCurve(l + 1, r, v, t) * t);
}