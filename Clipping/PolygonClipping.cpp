#include "PolygonClipping.h"

PolygonClipping::PolygonClipping(vector<Point> v, int xLeft, int xRight, int yTop, int yBottom) : Clipping(v, xLeft, xRight, yTop, yBottom),
                                                                                                  v(v), xLeft(xLeft), xRight(xRight), yTop(yTop), yBottom(yBottom){}

vector<Point> clipEdges(vector<Point> &p, IsIn in, Intersect intersect, double edge){
    vector<Point> result;
    Point v1 = p[p.size() - 1];
    bool in1 = in(v1, edge);
    for (int i = 0; i < p.size(); ++i) {
        Point v2 = p[i];
        bool in2 = in(v2, edge);
        if((!in1) && in2){
            result.push_back(intersect(v1, v2, edge));
            result.push_back(v2);
        }
        else if(in1 && in2){
            result.push_back(v2);
        }
        else if(in1){
            result.push_back(intersect(v1, v2, edge));
        }
        v1 = v2;
        in1 = in2;
    }
    return result;
}

void polygonClipping (vector<Point> &p, double xLeft, double xRight, double yTop, double yBottom){
    vector<Point> result;
    result = clipEdges(p, inLeft, vIntersect, xLeft); // clip left
    result = clipEdges(result, inRight, vIntersect, xRight); // clip right
    result = clipEdges(result, inTop, hIntersect, yTop); // clip top
    result = clipEdges(result, inBottom, hIntersect, yBottom); // clip bottom

    p = result;
}

void PolygonClipping::clip(HDC hdc, vector<Point> &p) {
    polygonClipping(p, xLeft, xRight, yTop, yBottom);
}