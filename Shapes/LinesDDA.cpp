#include "LinesDDA.h"

#include <iostream>

LinesDDA::LinesDDA(Point p1, Point p2, COLORREF c) : Shape(c), p1(p1), p2(p2){}

void LinesDDA::draw(HDC hdc, COLORREF c) {
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
void LineeDDA(HDC hdc, Point p1, Point p2, COLORREF c) {
    LinesDDA line(p1, p2, c);
    line.draw(hdc, c);
}
string LinesDDA::serialize() {
    stringstream ss;
    ss << "LinesDDA " << color << " "
            << p1.x << " " << p1.y<<" "
            << p2.x << " " << p2.y;
    return ss.str();
}

Shape *LinesDDA::deserialize(istream &in) {
    COLORREF color;
    Point p1,p2;
    in >> color >> p1.x >> p1.y >> p2.x>>p2.y;
    return new LinesDDA(p1, p2, color);
}