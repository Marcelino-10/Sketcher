#include <Windows.h>
#include <commdlg.h>
#include "Point.h"
#include "Shapes/Shape.h"
#include "Filling/Filling.h"
#include "Shapes/BezierCurve.h"
#include "Shapes/BezierCurveMatrix.h"
#include "Shapes/BezierCurveMidpoint.h"
#include "Shapes/HermiteCurve.h"
#include "Shapes/CardinalSpline.h"
#include "Shapes/GeneralPolygon.h"
#include "Shapes/LinesDDA.h"
#include "Filling/FloodFilling.h"

// shapes id
#define BezierCurve_ID 1
#define BezierCurveMidpoint_ID 2
#define BezierCurveMatrix_ID 3
#define HermiteCurve_ID 4
#define CardinalSpline_ID 5
#define Polygon_ID 6
#define LineDDA_ID 7
#define LineBresenham_ID 8
#define LineParametric_ID 9
#define Circle_ID 10
#define CircleBresenham_ID 10
#define CirclePolar_ID 11
#define CirlceIterativePolar_ID 12

// filling id
#define ConvexScanLine_ID 100
#define GeneralScanLine_ID 200
#define FloodFill_ID 300
#define RecFloodFill_ID 400

// color picker button id
#define ColorPicker_ID 1000
#define ColorFillingPicker_ID 2000

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
    AppendMenu(hFileMenu, MF_STRING, LineDDA_ID, "Line DDA");
    AppendMenu(hFileMenu, MF_STRING, LineBresenham_ID, "Line Bresenham");
    AppendMenu(hFileMenu, MF_STRING, LineParametric_ID, "Line Parametric");
    AppendMenu(hFileMenu, MF_STRING, Circle_ID, "Circle");
    AppendMenu(hFileMenu, MF_STRING, CircleBresenham_ID, "Circle Bresenham");
    AppendMenu(hFileMenu, MF_STRING, CirclePolar_ID, "Circle Polar");
    AppendMenu(hFileMenu, MF_STRING, CirlceIterativePolar_ID, "Circle Iterative Polar");
    AppendMenu(hFileMenu, MF_STRING, Polygon_ID, "General Polygon");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Polygons");

    SetMenu(hwnd, hMenu);
}

void AddFillingMenu(HWND hwnd) {



    HMENU hFileMenu = CreatePopupMenu();
    AppendMenu(hFileMenu, MF_STRING, ConvexScanLine_ID, "Convex Scan Line Filling");
    AppendMenu(hFileMenu, MF_STRING, GeneralScanLine_ID, "General Scan Line Filling");
    AppendMenu(hFileMenu, MF_STRING, RecFloodFill_ID, "Recursive FloodFill");
    AppendMenu(hFileMenu, MF_STRING, FloodFill_ID, "Non-Recursive FloodFill");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Filling");

    SetMenu(hwnd, hMenu);
}

CHOOSECOLOR cc1;
CHOOSECOLOR cc2;
static COLORREF customColors[16];
COLORREF rgbDrawing = RGB(255, 255, 255);
COLORREF rgbFilling = RGB(255, 255, 255);

void AddColorPicker(HWND hwnd){
    rgbDrawing = RGB(255, 255, 255);

    ZeroMemory(&cc1, sizeof(cc1));
    cc1.lStructSize = sizeof(cc1);
    cc1.hwndOwner = hwnd;
    cc1.lpCustColors = customColors;
    cc1.rgbResult = rgbDrawing;
    cc1.Flags = CC_FULLOPEN | CC_RGBINIT;

    if (ChooseColor(&cc1) == TRUE) {
        rgbDrawing = cc1.rgbResult;
    }
}

void AddFillerPicker(HWND hwnd){
    rgbFilling = RGB(255, 255, 255);

    ZeroMemory(&cc2, sizeof(cc2));
    cc2.lStructSize = sizeof(cc2);
    cc2.hwndOwner = hwnd;
    cc2.lpCustColors = customColors;
    cc2.rgbResult = rgbDrawing;
    cc2.Flags = CC_FULLOPEN | CC_RGBINIT;

    if(ChooseColor(&cc2) == TRUE){
        rgbFilling = cc2.rgbResult;
    }
}

LRESULT WndProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
    HDC hdc;
    static Shape *s;
    static Filling *f;
    static vector<Point> v;
    static int shapeToDraw;
    Point p;
    switch (m) {
        case WM_COMMAND:
            switch (LOWORD(wp)) {
                // color
                case ColorPicker_ID:
                    AddColorPicker(hwnd);
                    break;
                case ColorFillingPicker_ID:
                    AddFillerPicker(hwnd);
                    break;

                // shapes
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

                // filling
                case FloodFill_ID:
                    shapeToDraw = FloodFill_ID;
                    break;
            }
            break;
        case WM_CREATE:
            CreateWindow(
                    "BUTTON", "Pick a Color",
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1024, 20, 100, 40,
                    hwnd, (HMENU)ColorPicker_ID, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
            CreateWindow(
                    "BUTTON", "Pick a Filling Color",
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                    800, 20, 200, 40,
                    hwnd, (HMENU)ColorFillingPicker_ID, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
            break;

        case WM_LBUTTONDOWN:
            p.x = LOWORD(lp);
            p.y = HIWORD(lp);
            v.push_back(p);
            break;
        case WM_RBUTTONDOWN:
            if(shapeToDraw == BezierCurve_ID){
                hdc = GetDC(hwnd);
                s = new BezierCurve(v, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == BezierCurveMidpoint_ID){
                hdc = GetDC(hwnd);
                s = new BezierCurveMidpoint(v, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == BezierCurveMatrix_ID){
                hdc = GetDC(hwnd);
                s = new BezierCurveMatrix(v, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == HermiteCurve_ID){
                hdc = GetDC(hwnd);
                s = new HermiteCurve(v, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == CardinalSpline_ID){
                hdc = GetDC(hwnd);
                s = new CardinalSpline(v, 3, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == Polygon_ID){
                hdc = GetDC(hwnd);
                s = new GeneralPolygon(v, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == LineDDA_ID){
                hdc = GetDC(hwnd);
                s = new LinesDDA(v[0], v[1], rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == FloodFill_ID){
                hdc = GetDC(hwnd);
                f = new FloodFilling(rgbFilling, rgbDrawing, v[0]);
                f->fill(hdc);
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