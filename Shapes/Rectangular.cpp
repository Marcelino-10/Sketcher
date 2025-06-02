
#include "Rectangular.h"
#include "LinesDDA.h"
#include "BezierCurveMidpoint.h"
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <vector>

Rectangular::Rectangular(Point p1, Point p2, COLORREF c)
        : Shape(c), point1(p1), point2(p2) {
    calculateVertices();
    isFilled = false;
}

void Rectangular::calculateVertices() {
    vertices[0] = point1;
    vertices[1] = Point(point2.x, point1.y);
    vertices[2] = point2;
    vertices[3] = Point(point1.x, point2.y);
}

void Rectangular::draw(HDC hdc, COLORREF c) {
    Point p = vertices[3];
    for (int i = 0; i < 4; ++i) {
        LinesDDA l(p, vertices[i], c);
        l.draw(hdc, c);
        p = vertices[i];
    }

    if (isFilled) {
        fill(hdc, fillColor);
    }
}

int Rectangular::getMinY() {
    return std::min(point1.y, point2.y);
}

int Rectangular::getMaxY() {
    return std::max(point1.y, point2.y);
}

int Rectangular::getLeftX(int y) {
    return std::min(point1.x, point2.x);
}

int Rectangular::getRightX(int y) {
    return std::max(point1.x, point2.x);
}

void Rectangular::bezierCurveFill(HDC hdc, COLORREF c) {
    int minY = getMinY();
    int maxY = getMaxY();
    int leftX = getLeftX(0);
    int rightX = getRightX(0);
    int height = maxY - minY;
    int width = rightX - leftX;

    for (int x = leftX; x <= rightX; x += 5) {
        double normalizedX = (double) (x - leftX) / width;

        int waveAmplitude = width / 12;
        double wave = sin(normalizedX * 3.14159 * 3) * waveAmplitude;

        std::vector<Point> controlPoints;
        controlPoints.push_back(Point(x, minY));
        controlPoints.push_back(Point(x + (int) wave, minY + height / 3));
        controlPoints.push_back(Point(x - (int) wave, minY + height * 2 / 3));
        controlPoints.push_back(Point(x, maxY));

        BezierCurveMidpoint curve(controlPoints, 0, c);
        curve.draw(hdc, c);
    }
}

void Rectangular::fill(HDC hdc, COLORREF c) {
    isFilled = true;
    fillColor = c;
    bezierCurveFill(hdc, c);
}