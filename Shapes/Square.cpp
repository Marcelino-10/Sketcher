#include "Square.h"
#include "LinesDDA.h"
#include <cmath>
#include <windows.h>
#include <algorithm>

Square::Square(Point p1, Point p2, COLORREF c) : Shape(c), point1(p1), point2(p2), isFilled(false) {
    calculateVertices();
}

void Square::calculateVertices() {
    int width = abs(point2.x - point1.x);
    int height = abs(point2.y - point1.y);
    int sideLength = max(width, height);

    int dirX = (point2.x >= point1.x) ? 1 : -1;
    int dirY = (point2.y >= point1.y) ? 1 : -1;

    vertices[0] = point1;
    vertices[1] = Point(point1.x + dirX * sideLength, point1.y);
    vertices[2] = Point(point1.x + dirX * sideLength, point1.y + dirY * sideLength);
    vertices[3] = Point(point1.x, point1.y + dirY * sideLength);
}


void Square::draw(HDC hdc, COLORREF c) {
    Point p = vertices[3];
    for (int i = 0; i < 4; ++i) {
        LinesDDA l(p, vertices[i], c);
        l.draw(hdc, c);
        p = vertices[i];
    }
    if (isFilled) {
        hermitCurveFill(hdc, fillColor);
    }
}

void Square::fill(HDC hdc, COLORREF c) {
    isFilled = true;
    fillColor = c;
    hermitCurveFill(hdc, c);
}


int Square::getMinY() {
    return min({vertices[0].y, vertices[1].y, vertices[2].y, vertices[3].y});
}

int Square::getMaxY() {
    return max({vertices[0].y, vertices[1].y, vertices[2].y, vertices[3].y});
}

int Square::getLeftX(int y) {
    return min({vertices[0].x, vertices[1].x, vertices[2].x, vertices[3].x});
}

int Square::getRightX(int y) {
    return max({vertices[0].x, vertices[1].x, vertices[2].x, vertices[3].x});
}

Point Square::hermitPoint(Point p0, Point p1, Point t0, Point t1, double t) {
    double h00 = 2*t*t*t - 3*t*t + 1;
    double h10 = t*t*t - 2*t*t + t;
    double h01 = -2*t*t*t + 3*t*t;
    double h11 = t*t*t - t*t;

    int x = (int)(h00 * p0.x + h10 * t0.x + h01 * p1.x + h11 * t1.x);
    int y = (int)(h00 * p0.y + h10 * t0.y + h01 * p1.y + h11 * t1.y);

    return Point(x, y);
}

void Square::drawHermitLine(HDC hdc, Point p0, Point p1, Point t0, Point t1, COLORREF c) {
    const int steps = 5;
    Point prevPoint = p0;

    for (int i = 1; i <= steps; i++) {
        double t = (double)i / steps;
        Point currentPoint = hermitPoint(p0, p1, t0, t1, t);

        LinesDDA line(prevPoint, currentPoint, c);
        line.draw(hdc, c);

        prevPoint = currentPoint;
    }
}

void Square::hermitCurveFill(HDC hdc, COLORREF c) {
    int minY = getMinY();
    int maxY = getMaxY();

    for (int y = minY; y <= maxY; y += 5) {
        int leftX = getLeftX(y);
        int rightX = getRightX(y);

        Point p0(leftX, y);
        Point p1(rightX, y);

        double wave = sin((double)(y - minY) * 0.2) * 20;
        Point t0((int)(20 + wave), 0);
        Point t1((int)(-20 - wave), 0);

        drawHermitLine(hdc, p0, p1, t0, t1, c);
    }
}