#include "CircleCirclesFilling.h"
#include "../Shapes/CircleBresenham.h"

CircleCirclesFilling::CircleCirclesFilling(COLORREF cf, Point center, Point p, int step, int quarter) : Filling(cf, cf), center(center), p(p), step(step), quarter(quarter){}

void draw2PointsOne(HDC hdc, int xc, int yc, int x, int y, COLORREF c){
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc + y, yc - x, c);
}

void draw2PointsTwo(HDC hdc, int xc, int yc, int x, int y, COLORREF c){
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc + y, yc + x, c);
}

void draw2PointsThree(HDC hdc, int xc, int yc, int x, int y, COLORREF c){
    SetPixel(hdc, xc - x, yc + y, c);
    SetPixel(hdc, xc - y, yc + x, c);
}

void draw2PointsFour(HDC hdc, int xc, int yc, int x, int y, COLORREF c){
    SetPixel(hdc, xc - x, yc - y, c);
    SetPixel(hdc, xc - y, yc - x, c);
}

void drawCircle(HDC hdc, COLORREF c, Point center, int R, bool flag, int quarter) {
    int xc = (int) center.x;
    int yc = (int) center.y;

    int x = 0, y = R;
    while (x < y) {
        y = round(sqrt(R * R - x * x));
        if(flag)
            draw8Points(hdc, xc, yc, x, y, c);
        else{
            switch (quarter) {
                case 1:
                    draw2PointsOne(hdc, xc, yc, x, y, c);
                    break;
                case 2:
                    draw2PointsTwo(hdc, xc, yc, x, y, c);
                    break;
                case 3:
                    draw2PointsThree(hdc, xc, yc, x, y, c);
                    break;
                case 4:
                    draw2PointsFour(hdc, xc, yc, x, y, c);
                    break;
            }
        }
        x++;
    }
}

void CircleCirclesFilling::fill(HDC hdc) {
    int r = (int) sqrt((p.x - center.x) * (p.x - center.x) + (p.y - center.y) * (p.y - center.y));
    for (int i = (int) r; i > 0; i -= step) {
        if(i == r)
            drawCircle(hdc, cf, center, i, true, quarter);
        else
            drawCircle(hdc, cf, center, i, false, quarter);
    }
}