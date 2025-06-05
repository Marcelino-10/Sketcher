#ifndef GRAPHICSPROJECT_CONVEXFILLING_H
#define GRAPHICSPROJECT_CONVEXFILLING_H

#include "Filling.h"
#include <vector>
#include <cmath>

using namespace std;

struct Entry{
    double xLeft, xRight;
};

typedef  Entry edgeTable[1024];

class ConvexFilling : public Filling {
    vector<Point> v;
public:
    ConvexFilling(COLORREF cf, vector<Point> &v);
    void fill(HDC hdc);
    string serialize() override;
    static Filling* deserialize(std::istream &in);
};

#endif //GRAPHICSPROJECT_CONVEXFILLING_H
