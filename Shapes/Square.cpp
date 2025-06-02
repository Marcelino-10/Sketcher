//
// Created by Arsany on 6/2/2025.
//

#include "Square.h"
#include <cmath>
#include <windows.h>

Square::Square(Point p1, Point p2, COLORREF c) : Shape(c), point1(p1), point2(p2) {
    calculateVertices();
}

void Square::calculateVertices() {
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;
    double sideLength = static_cast<int>(sqrt(pow(dx, 2) + pow(dy, 2)));

    double dirX = dx / sideLength;
    double dirY = dy / sideLength;

    double perpX = -dirY;
    double perpY = dirX;


    vertices[0] = point1;

    vertices[1] = Point(point1.x + dirX * sideLength,
                        point1.y + dirY * sideLength);

    vertices[2] = Point(point1.x + dirX * sideLength + perpX * sideLength,
                        point1.y + dirY * sideLength + perpY * sideLength);

    vertices[3] = Point(point1.x + perpX * sideLength,
                        point1.y + perpY * sideLength);
}

void Square::draw(HDC hdc, COLORREF c) {
    Point p = vertices[3];
    for (int i = 0; i < 4; ++i) {
        LinesDDA l(p, vertices[i], c);
        l.draw(hdc, c);
        p = vertices[i];
    }

}