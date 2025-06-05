#include "HermiteCurve.h"

HermiteCurve::HermiteCurve(vector<Point> &v, int numPoints, COLORREF c) : Shape(c), v(v), numPoints(numPoints) {}

void HermiteCurve::draw(HDC hdc, COLORREF c) {
    int mat[][4] = {{2, 1, -2, 1}, {-3, -2, 3, -1}, {0, 1, 0, 0}, {1, 0, 0, 0}};
    double step = 1.0 / numPoints;
    for (double t = 0; t < 1; t += step) {
        Point p;
        for (int i = 0; i < 5; ++i) {
            int par[4];
            double sum = 0;
            double current = t * t * t;
            for (int j = 0; j < 4; ++j) {
                par[j] = 0;
                for (int k = 0; k < 4; ++k) {
                    if (i == 0) {
                        par[j] += mat[j][k] * (int) v[k].x;
                    }
                    else if(i == 1) {
                        par[j] += mat[j][k] * (int) v[k].y;
                    }
                }
                sum += par[j] * current;
                current /= t;
            }
            if (i == 0)
                p.x = sum;
            else if(i == 1)
                p.y = sum;
        }
        SetPixel(hdc, Round(p.x), Round(p.y), c);
    }
}
string HermiteCurve::serialize() {
    stringstream ss;
    ss << "HermiteCurve " << this->color << " " << numPoints << " " << v.size();
    for (const Point &p : v)
        ss << " " << p.x << " " << p.y;
    return ss.str();
}

Shape* HermiteCurve::deserialize(istream &in) {
    COLORREF color;
    int numPts, vecSize;
    in >> color >> numPts >> vecSize;
    vector<Point> vec(vecSize);
    for (int i = 0; i < vecSize; ++i) {
        in >> vec[i].x >> vec[i].y;
    }
    return new HermiteCurve(vec, numPts, color);
}