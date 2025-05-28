#include "LineClipping.h"

LineClipping::LineClipping(vector<Point> v, int xLeft, int xRight, int yTop, int yBottom) : Clipping(v, xLeft, xRight, yTop, yBottom),
                                                                                            v(v), xLeft(xLeft), xRight(xRight), yTop(yTop), yBottom(yBottom){}

void LineClipping::clip(HDC hdc, vector<Point> &p) {
    Point p1 = p[0];
    Point p2 = p[1];
    OutCode out1 = getOutCode(p1, xLeft, xRight, yTop, yBottom);
    OutCode out2 = getOutCode(p2, xLeft, xRight, yTop, yBottom);

    while((out1.all || out2.all) && !(out1.all & out2.all)){
        if(out1.all){
            if(out1.left) p1 = vIntersect(p1, p2, xLeft);
            if(out1.right) p1 = vIntersect(p1, p2, xRight);
            if(out1.top) p1 = hIntersect(p1, p2, yTop);
            if(out1.bottom) p1 = hIntersect(p1, p2, yBottom);
            out1 = getOutCode(p1, xLeft, xRight, yTop, yBottom);
        }
        else {
            if(out2.left) p2 = vIntersect(p1, p2, xLeft);
            if(out2.right) p2 = vIntersect(p1, p2, xRight);
            if(out2.top) p2 = hIntersect(p1, p2, yTop);
            if(out2.bottom) p2 = hIntersect(p1, p2, yBottom);
            out2 = getOutCode(p2, xLeft, xRight, yTop, yBottom);
        }
    }
    p[0] = p1, p[1] = p2;

    if(out1.all && out2.all)
        p.clear();
}