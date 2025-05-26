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