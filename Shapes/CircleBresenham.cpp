#include "CircleBresenham.h"

CircleBresenham::CircleBresenham(Point center, Point p, COLORREF c) : Shape(c), center(center), p(p){}

void draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c){
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc + y, yc + x, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc + y, yc - x, c);
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc - y, yc + x, c);
    SetPixel(hdc, xc - x, yc - y, c);
    SetPixel(hdc, xc - y, yc - x, c);
}

void CircleBresenham::draw(HDC hdc, COLORREF c) {
    auto [xc, yc] = center;
    double r = distance(p, center);
    int x = 0, y = (int) r, d = 1 - r;
    int d1 = 3, d2 = 5 - (2 * r);
    draw8Points(hdc, (int) xc, (int) yc, x, y, c);
    while(x < y){
        x++;
        d1 += 2;
        if(d < 0){
            d += d1;
            d2 += 2;
        }
        else{
            d += d2;
            d2 += 4;
            y--;
        }
        draw8Points(hdc, (int) xc, (int) yc, x, y, c);
    }
}