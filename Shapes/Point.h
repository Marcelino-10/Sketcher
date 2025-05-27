#ifndef GRAPHICSPROJECT_POINT_H
#define GRAPHICSPROJECT_POINT_H

#include <cmath>

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0);
    Point operator* (double d) const;
    Point operator+ (Point p) const;
    Point operator- (Point p) const;
};

inline int Round(double x){
    return (int) (x + 0.5);
}

inline double distance(Point p1, Point p2){
    double dist = sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
    return dist;
}

#endif //GRAPHICSPROJECT_POINT_H