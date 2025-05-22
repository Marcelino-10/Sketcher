#include "FloodFill.h"

FloodFill::FloodFill(COLORREF cf, COLORREF cb, Point begin) : Filling(cf, cb), begin(begin) {}

void FloodFill::fill(HDC hdc) {
    stack<Point> st;
    st.emplace(begin);
    while(!st.empty()){
        Point p = st.top();
        st.pop();
        COLORREF c = GetPixel(hdc, p.x, p.y);
        if(c == cf || c == cb) continue;
        SetPixel(hdc, p.x, p.y, cf);
        st.emplace(p.x + 1, p.y);
        st.emplace(p.x - 1, p.y);
        st.emplace(p.x, p.y + 1);
        st.emplace(p.x, p.y - 1);
    }
}
