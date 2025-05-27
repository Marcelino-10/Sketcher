#include "ConvexFilling.h"

ConvexFilling::ConvexFilling(COLORREF cf, vector<Point> &v) : Filling(cf, cf), v(v){}

void LineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c) {
    int mx = max(abs(x2 - x1), abs(y2 - y1));
    double step = 1.0 / mx;
    int alpha1 = x2 - x1, beta1 = x1, alpha2 = y2 - y1, beta2 = y1;
    double t;
    for(t = 0; t < 1; t += step){
        double x = alpha1 * t + beta1;
        double y = alpha2 * t + beta2;
        SetPixel(hdc, Round(x), Round(y), c);
    }
}

void init(edgeTable &t){
    for (int i = 0; i < 1024; ++i) {
        t[i].xLeft = INT_MAX;
        t[i].xRight = -INT_MAX;
    }
}

void edge2Table(Point v1, Point v2, edgeTable &t){
    if(v1.y == v2.y)
        return;
    else if (v1.y > v2.y) swap(v1, v2);

    double invM = (double) (v2.x - v1.x) / (v2.y - v1.y);
    int y = v1.y;
    double x = v1.x;
    while(y < v2.y){
        if(x < t[y].xLeft)
            t[y].xLeft = x;
        else if(x > t[y].xRight)
            t[y].xRight = x;
        y++;
        x += invM;
    }
}

void polygon2Table(vector<Point> &p, edgeTable &t){
    Point v = p[p.size() - 1];
    for (int i = 0; i < p.size(); ++i) {
        edge2Table(v, p[i], t);
        v = p[i];
    }
}

void table2Screen(HDC hdc, edgeTable &t, COLORREF c){
    for (int y = 0; y < 1024; ++y) {
        if(t[y].xLeft < t[y].xRight)
            LineDDA(hdc, (int) ceil(t[y].xLeft), y, (int) floor(t[y].xRight), y, c);
    }
}

void drawConvexScanLineFilling(HDC hdc, vector<Point> &p, COLORREF c){
    edgeTable t;
    init(t);
    polygon2Table(p, t);
    table2Screen(hdc, t, c);
}

void ConvexFilling::fill(HDC hdc) {
    drawConvexScanLineFilling(hdc, v, cf);
}