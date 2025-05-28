#ifndef GRAPHICSPROJECT_CLIPPING_H
#define GRAPHICSPROJECT_CLIPPING_H

#include "../Shapes/Point.h"
#include "../Shapes/Shape.h"
#include <vector>

using namespace std;

class Clipping {
    vector<Point> v;
    int xLeft, xRight, yTop, yBottom;
public:
    Clipping(vector<Point> v, int xLeft, int xRight, int yTop, int yBottom);
    virtual void clip(HDC hdc, vector<Point> &v) = 0;
};

union OutCode {
    unsigned all: 4;
    struct {
        unsigned left : 1, right : 1, top : 1, bottom : 1;
    };
};

// Utilities functions
inline OutCode getOutCode(Point p, double xLeft, double xRight, double yTop, double yBottom){
    OutCode result{};
    result.all = 0;
    if(p.x < xLeft) result.left = 1;
    if(p.x > xRight) result.right = 1;
    if(p.y < yTop) result.top = 1;
    if(p.y > yBottom) result.bottom = 1;
    return result;
}

inline Point vIntersect(Point p1, Point p2, double xEdge){
    Point result{};
    result.x = xEdge;
    result.y = (xEdge - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y;
    return result;
}

inline Point hIntersect(Point p1, Point p2, double yEdge){
    Point result{};
    result.y = yEdge;
    result.x = (yEdge - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
    return result;
}

inline bool inLeft(Point p, double edge){
    return (p.x >= edge);
}

inline bool inRight(Point p, double edge){
    return (p.x <= edge);
}

inline bool inTop(Point p, double edge){
    return (p.y >= edge);
}

inline bool inBottom(Point p, double edge){
    return (p.y <= edge);
}

typedef bool (*IsIn) (Point p, double edge);
typedef Point (*Intersect) (Point p1, Point p2, double edge);

#endif //GRAPHICSPROJECT_CLIPPING_H
