//
// Created by Arsany on 6/2/2025.
//

#include "Rectangular.h"
#include "LinesDDA.h"
#include <cmath>
#include <windows.h>

Rectangular::Rectangular(Point p1, Point p2, Point p3, COLORREF c)
        : Shape(c), point1(p1), point2(p2), point3(p3) {
    calculateVertices();
}

void Rectangular::calculateVertices() {
    int widthDx = point2.x - point1.x;
    int widthDy = point2.y - point1.y;

    int heightDx = point3.x - point1.x;
    int heightDy = point3.y - point1.y;

    vertices[0] = point1;

    vertices[1] = Point(point1.x + widthDx,
                        point1.y + widthDy);

    vertices[2] = Point(point1.x + widthDx + heightDx,
                        point1.y + widthDy + heightDy);

    vertices[3] = Point(point1.x + heightDx,
                        point1.y + heightDy);
}

void Rectangular::draw(HDC hdc, COLORREF c) {
    Point p = vertices[3];
    for (int i = 0; i < 4; ++i) {
        LinesDDA l(p, vertices[i], c);
        l.draw(hdc, c);
        p = vertices[i];
    }


}