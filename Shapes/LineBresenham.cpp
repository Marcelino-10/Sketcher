#include "LineBresenham.h"

LineBresenham::LineBresenham(Point p1, Point p2, COLORREF c) : Shape(c), p1(p1), p2(p2){}

void LineBresenham::draw(HDC hdc, COLORREF c) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    int dx = x2 - x1;
    int dy = y2 - y1;
    double m = (double) dy / dx;
    if(m > 0 && m <= 1){
        if(x1 > x2){
            swap(x1, x2);
            swap(y1, y2);
            int dx = x2 - x1;
            int dy = y2 - y1;
        }
        int d = dx - 2 * dy;
        int d1 = -2 * dy;
        int d2 = 2 * (dx - dy);
        int x = x1;
        int y = y1;
        SetPixel(hdc, x, y, c);
        while(x < x2){
            if(d > 0){
                d += d1;
            }
            else{
                d += d2;
                y++;
            }
            x++;
            SetPixel(hdc, x, y, c);
        }
    }else if(m > 1){
        if(y1 > y2){
            swap(x1, x2);
            swap(y1, y2);
            int dx = x2 - x1;
            int dy = y2 - y1;
        }
        int d = dy - 2 * dx;
        int d1 = -2 * dx;
        int d2 = 2 * (dy - dx);
        int x = x1;
        int y = y1;
        SetPixel(hdc, x, y, c);
        while(y < y2){
            if(d > 0){
                d += d1;
            }
            else{
                d += d2;
                x++;
            }
            y++;
            SetPixel(hdc, x, y, c);
        }
    }else if(m < 0 && m > -1){
        if(x1 > x2){
            swap(x1, x2);
            swap(y1, y2);
            int dx = x2 - x1;
            int dy = y2 - y1;
        }
        int d = dx + 2 * dy;
        int d1 = 2 * dy;
        int d2 = 2 * (dx + dy);
        int x = x1;
        int y = y1;
        SetPixel(hdc, x, y, c);
        while(x < x2){
            if(d > 0){
                d += d1;
            }
            else{
                d += d2;
                y--;
            }
            x++;
            SetPixel(hdc, x, y, c);
        }
    }
    else{
        if(y1 > y2){
            swap(x1, x2);
            swap(y1, y2);
            int dx = x2 - x1;
            int dy = y2 - y1;
        }
        int d = dy + 2 * dx;
        int d1 = 2 * dx;
        int d2 = 2 * (dy + dx);
        int x = x1;
        int y = y1;
        SetPixel(hdc, x, y, c);
        while(y < y2){
            if(d > 0){
                d += d1;
            }
            else{
                d += d2;
                x--;
            }
            y++;
            SetPixel(hdc, x, y, c);
        }
    }
}