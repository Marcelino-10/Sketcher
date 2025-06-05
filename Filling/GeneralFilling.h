#ifndef GRAPHICSPROJECT_GENERALFILLING_H
#define GRAPHICSPROJECT_GENERALFILLING_H

#include "Filling.h"
#include "../Shapes/Point.h"
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node{
    double x, mInv;
    int yMax;
    Node(double x = 0, double mInv = 0, int yMax = 0) : x(x), mInv(mInv), yMax(yMax) {}
};

inline bool operator< (Node n1, Node n2){
    return n1.x < n2.x;
}

class GeneralFilling : public Filling{
    vector<Point> v;
    vector<Node> t[1024];
public:
    GeneralFilling(COLORREF c, vector<Point> &v);
    void edge2Table(Point v1, Point v2);
    void polygon2Table(vector<Point> &v);
    void table2Screen(HDC hdc);
    void fill(HDC hdc);
    std::string serialize() override;
    static Filling* deserialize(std::istream &in);
};


#endif //GRAPHICSPROJECT_GENERALFILLING_H
