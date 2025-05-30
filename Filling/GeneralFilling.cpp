#include "GeneralFilling.h"

GeneralFilling::GeneralFilling(COLORREF c, vector<Point> &v) : Filling(c, c), v(v) {}

void DrawLine(HDC hdc, Point p1, Point p2, COLORREF c) {
    double dx = (p2.x - p1.x), dy = (p2.y - p1.y);
    SetPixel(hdc, (int) p1.x, (int) p1.y, c);
    if(abs(dx) >= abs(dy)){
        if(p2.x < p1.x){
            swap(p1.x, p2.x);
            swap(p1.y, p2.y);
        }
        int xs = (int) p1.x;
        double ys = p1.y;
        double yInc = (dy / dx);
        while(xs < p2.x){
            xs++;
            ys += yInc;
            SetPixel(hdc, xs, round(ys), c);
        }
    }
    else{
        if(p2.y < p1.y){
            swap(p1.x, p2.x);
            swap(p1.y, p2.y);
        }
        int ys = (int) p1.y;
        double xs = p1.x;
        double xInc = (dx / dy);
        while(ys < p2.y){
            ys++;
            xs += xInc;
            SetPixel(hdc, round(xs), ys, c);
        }
    }
}

void GeneralFilling::edge2Table(Point v1, Point v2) {
    if(v1.y == v2.y)
        return;
    if(v1.y > v2.y)
        swap(v1, v2);

    this->t[(int)v1.y].emplace_back(v1.x, (double) ((v2.x - v1.x) / (v2.y - v1.y)), v2.y);
}

void GeneralFilling::polygon2Table(vector<Point> &v) {
    Point p1 = v[v.size() - 1];
    for (int i = 0; i < (int) v.size(); ++i) {
        Point p2 = v[i];
        edge2Table(p1, p2);
        p1 = p2;
    }
}

void GeneralFilling::table2Screen(HDC hdc) {
    int y = 0;
    while(t[y].empty()){
        y++;
    }

    vector<Node> active = t[y];

    while(!active.empty()){
        std::sort(active.begin(), active.end());
        for (int i = 0; i < active.size();) {
            DrawLine(hdc, {ceil(active[i].x), (double) y}, {floor(active[i+1].x), (double) y}, this->cf);
            i += 2;
        }
        y++;

        erase_if(active, [y](Node node) -> bool {return node.yMax == y;});

        for(auto &it : active){
            it.x += it.mInv;
        }

        if(t[y].size() > 0){
            for(auto it : t[y])
                active.push_back(it);
        }
    }
}

void GeneralFilling::fill(HDC hdc) {
    polygon2Table(this->v);
    table2Screen(hdc);
}