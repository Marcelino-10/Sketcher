#include <Windows.h>
#include <commdlg.h>
#include "Point.h"
#include "Shape.h"
#include "BezierCurve.h"
#include "BezierCurveMatrix.h"
#include "BezierCurveMidpoint.h"
#include "HermiteCurve.h"
#include "CardinalSpline.h"
#include "GeneralPolygon.h"
#include "LinesDDA.h"

// shapes id
#define BezierCurve_ID 1
#define BezierCurveMidpoint_ID 2
#define BezierCurveMatrix_ID 3
#define HermiteCurve_ID 4
#define CardinalSpline_ID 5
#define Polygon_ID 6
#define LineDDA_ID 7

using namespace std;

HMENU hMenu;
void AddCurvesMenu(HWND hwnd) {
    hMenu = CreateMenu();

    HMENU hFileMenu = CreatePopupMenu();
    AppendMenu(hFileMenu, MF_STRING, BezierCurve_ID, "Bezier Curve");
    AppendMenu(hFileMenu, MF_STRING, BezierCurveMidpoint_ID, "MidPoint Bezier Curve");
    AppendMenu(hFileMenu, MF_STRING, BezierCurveMatrix_ID, "Bezier Curve Matrix");
    AppendMenu(hFileMenu, MF_STRING, HermiteCurve_ID, "Hermite Curve");
    AppendMenu(hFileMenu, MF_STRING, CardinalSpline_ID, "Cardinal Spline");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Curves");

    SetMenu(hwnd, hMenu);
}

void AddPolygonsMenu(HWND hwnd) {

    HMENU hFileMenu = CreatePopupMenu();
    AppendMenu(hFileMenu, MF_STRING, BezierCurve_ID, "Line DDA");
    AppendMenu(hFileMenu, MF_STRING, BezierCurveMidpoint_ID, "Line Bresenham");
    AppendMenu(hFileMenu, MF_STRING, BezierCurveMatrix_ID, "Line Parametric");
    AppendMenu(hFileMenu, MF_STRING, HermiteCurve_ID, "Circle");
    AppendMenu(hFileMenu, MF_STRING, HermiteCurve_ID, "Circle Bresenham");
    AppendMenu(hFileMenu, MF_STRING, HermiteCurve_ID, "Circle Polar");
    AppendMenu(hFileMenu, MF_STRING, HermiteCurve_ID, "Circle Iterative Polar");
    AppendMenu(hFileMenu, MF_STRING, Polygon_ID, "General Polygon");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Polygons");

    SetMenu(hwnd, hMenu);
}

void AddFillingMenu(HWND hwnd) {

    HMENU hFileMenu = CreatePopupMenu();
    AppendMenu(hFileMenu, MF_STRING, BezierCurve_ID, "Convex Scan Line Filling");
    AppendMenu(hFileMenu, MF_STRING, BezierCurveMidpoint_ID, "General Scan Line Filling");
    AppendMenu(hFileMenu, MF_STRING, BezierCurveMatrix_ID, "Recursive FloodFill");
    AppendMenu(hFileMenu, MF_STRING, BezierCurveMatrix_ID, "Non-Recursive FloodFill");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Filling");

    SetMenu(hwnd, hMenu);
}

LRESULT WndProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
    HDC hdc;
    static Shape *s;
    static vector<Point> v;
    static int shapeToDraw;
    Point p;
    switch (m) {
        case WM_COMMAND:
            switch (LOWORD(wp)) {
                case BezierCurve_ID:
                    shapeToDraw = BezierCurve_ID;
                    break;
                case BezierCurveMidpoint_ID:
                    shapeToDraw = BezierCurveMidpoint_ID;
                    break;
                case BezierCurveMatrix_ID:
                    shapeToDraw = BezierCurveMatrix_ID;
                    break;
                case HermiteCurve_ID:
                    shapeToDraw = HermiteCurve_ID;
                    break;
                case CardinalSpline_ID:
                    shapeToDraw = CardinalSpline_ID;
                    break;
                case Polygon_ID:
                    shapeToDraw = Polygon_ID;
                    break;
                case LineDDA_ID:
                    shapeToDraw = LineDDA_ID;
                    break;
            }
            break;
//        case WM_CREATE:
//
//            break;

        case WM_LBUTTONDOWN:
            p.x = LOWORD(lp);
            p.y = HIWORD(lp);
            v.push_back(p);
            break;
        case WM_RBUTTONDOWN:
            if(shapeToDraw == BezierCurve_ID){
                hdc = GetDC(hwnd);
                s = new BezierCurve(v, 1000);
                s->draw(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == BezierCurveMidpoint_ID){
                hdc = GetDC(hwnd);
                s = new BezierCurveMidpoint(v, 1000);
                s->draw(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == BezierCurveMatrix_ID){
                hdc = GetDC(hwnd);
                s = new BezierCurveMatrix(v, 1000);
                s->draw(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == HermiteCurve_ID){
                hdc = GetDC(hwnd);
                s = new HermiteCurve(v, 1000);
                s->draw(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == CardinalSpline_ID){
                hdc = GetDC(hwnd);
                s = new CardinalSpline(v, 3, 1000);
                s->draw(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == Polygon_ID){
                hdc = GetDC(hwnd);
                s = new GeneralPolygon(v);
                s->draw(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == LineDDA_ID){
                hdc = GetDC(hwnd);
                s = new LinesDDA(v[0], v[1]);
                s->draw(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, m, wp, lp);
    }
    return 0;
}

int APIENTRY WinMain(HINSTANCE hi, HINSTANCE pi, LPSTR cmd, int nsh) {
    WNDCLASS wc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.lpszClassName = "MyClass";
    wc.lpszMenuName = NULL;
    wc.lpfnWndProc = WndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hInstance = hi;
    RegisterClass(&wc);
    HWND hwnd = CreateWindow("MyClass", "Sketcher", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                             CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hi, 0);
    ShowWindow(hwnd, nsh);
    UpdateWindow(hwnd);
    MSG msg;
    AddCurvesMenu(hwnd);
    AddPolygonsMenu(hwnd);
    AddFillingMenu(hwnd);
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}