#include "ConvexFilling.h"

ConvexFilling::ConvexFilling(COLORREF cf, vector<Point> &v) : Filling(cf, cf), v(v){}

void LineDDA(HDC hdc, Point p1, Point p2, COLORREF c) {
    double dx = (p2.x - p1.x), dy = (p2.y - p1.y);
    SetPixel(hdc, (int) p1.x, (int) p1.y, c);
    if(abs(dx) >= abs(dy)){
        if(p2.x < p1.x){
            swap(p1.x, p2.x);
            swap(p1.y, p2.y);
        }
        int xs = (int) p1.x;
        double ys = p1.y;
        double yInc = (dy / dx);
        while(xs < p2.x){
            xs++;
            ys += yInc;
            SetPixel(hdc, xs, round(ys), c);
        }
    }
    else{
        if(p2.y < p1.y){
            swap(p1.x, p2.x);
            swap(p1.y, p2.y);
        }
        int ys = (int) p1.y;
        double xs = p1.x;
        double xInc = (dx / dy);
        while(ys < p2.y){
            ys++;
            xs += xInc;
            SetPixel(hdc, round(xs), ys, c);
        }
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
        if(x > t[y].xRight)
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
            LineDDA(hdc, {ceil(t[y].xLeft), (double) y}, {floor(t[y].xRight), (double) y}, c);
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
string ConvexFilling::serialize() {
    stringstream ss;

    ss << "ConvexFilling " << cf <<" "<<v.size();
    for(auto p:v) {
        ss<<" "<<p.x<<" "<<p.y;
    }
    return ss.str();
}

Filling* ConvexFilling::deserialize(std::istream &in) {
    COLORREF cf;
    int vecSz;
    in >> cf >> vecSz;
    vector<Point>v;
    int x,y;
    for (int i=0;i<vecSz;i++) {
        in>>x>>y;
        v.push_back(Point(x,y));
    }
    return new ConvexFilling(cf, v);
}