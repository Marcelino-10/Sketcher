#include <iostream>
#include <Windows.h>
#include <commdlg.h>
#include "Shapes/Point.h"
#include "Shapes/Shape.h"
#include "Filling/Filling.h"
#include "Shapes/BezierCurve.h"
#include "Shapes/BezierCurveMatrix.h"
#include "Shapes/BezierCurveMidpoint.h"
#include "Shapes/HermiteCurve.h"
#include "Shapes/CardinalSpline.h"
#include "Shapes/GeneralPolygon.h"
#include "Shapes/LinesDDA.h"
#include "Shapes/LineBresenham.h"
#include "Shapes/LineParametric.h"
#include "Shapes/CircleBresenham.h"
#include "Filling/FloodFilling.h"
#include "Filling/RecursiveFloodFill.h"
#include "Filling/ConvexFilling.h"
#include "Filling/GeneralFilling.h"
#include "Clipping/Clipping.h"
#include "Clipping/LineClipping.h"
#include "Clipping/PolygonClipping.h"
#include "Shapes/DirectCircle.h"
#include "Shapes/PolarCircle.h"
#include "Shapes/IterativePolar.h"
#include "Filling/CircleLineFilling.h"
#include "Shapes/EllipseDirect.h"
#include "Shapes/EllipsePolar.h"
#include "Shapes/EllipseMidpoint.h"
#include "Filling/CircleCirclesFilling.h"

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
#define CircleBresenham_ID 10
#define CirclePolar_ID 11
#define CircleIterativePolar_ID 12
#define Circle_ID 13
#define EllipseDirect_ID 14
#define EllipsePolar_ID 15
#define EllipseMidpoint_ID 16

// filling id
#define ConvexScanLine_ID 100
#define GeneralScanLine_ID 200
#define FloodFill_ID 300
#define RecFloodFill_ID 400
#define CircleLineFill_ID 500
#define CircleCirclesFill_ID 600

// clipping
#define LineClipping_ID 10000
#define PolygonClipping_ID 20000
#define DisableClipping_ID 30000

// color picker button id
#define ColorPicker_ID 1000
#define ColorFillingPicker_ID 2000

// mouse shapes
#define ArrowMouse_ID 5000
#define CrossMouse_ID 5100
#define HandMouse_ID 5200
#define NoMouse_ID 5300

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
    AppendMenu(hFileMenu, MF_STRING, CircleIterativePolar_ID, "Circle Iterative Polar");
    AppendMenu(hFileMenu, MF_STRING, Polygon_ID, "General Polygon");
    AppendMenu(hFileMenu, MF_STRING, EllipseDirect_ID, "Ellipse Direct");
    AppendMenu(hFileMenu, MF_STRING, EllipsePolar_ID, "Ellipse Polar");
    AppendMenu(hFileMenu, MF_STRING, EllipseMidpoint_ID, "Ellipse Midpoint");


    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Polygons");

    SetMenu(hwnd, hMenu);
}

void AddFillingMenu(HWND hwnd) {

    HMENU hFileMenu = CreatePopupMenu();
    AppendMenu(hFileMenu, MF_STRING, ConvexScanLine_ID, "Convex Scan Line Filling");
    AppendMenu(hFileMenu, MF_STRING, GeneralScanLine_ID, "General Scan Line Filling");
    AppendMenu(hFileMenu, MF_STRING, RecFloodFill_ID, "Recursive FloodFill");
    AppendMenu(hFileMenu, MF_STRING, FloodFill_ID, "Non-Recursive FloodFill");
    AppendMenu(hFileMenu, MF_STRING, CircleLineFill_ID, "CircleLine Filling");
    AppendMenu(hFileMenu, MF_STRING, CircleCirclesFill_ID, "Circle with Circles Filling");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Filling");

    SetMenu(hwnd, hMenu);
}

void AddClippingMenu(HWND hwnd) {

    HMENU hFileMenu = CreatePopupMenu();
    AppendMenu(hFileMenu, MF_STRING, LineClipping_ID, "LineClipping");
    AppendMenu(hFileMenu, MF_STRING, PolygonClipping_ID, "Polygon Clipping");
    AppendMenu(hFileMenu, MF_STRING, DisableClipping_ID, "Disable Clipping");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Clipping");

    SetMenu(hwnd, hMenu);
}

void AddMouseMenu(HWND hwnd){

    HMENU hFileMenu = CreatePopupMenu();
    AppendMenuA(hFileMenu, MF_STRING, ArrowMouse_ID, "Arrow");
    AppendMenuA(hFileMenu, MF_STRING, CrossMouse_ID, "Cross");
    AppendMenuA(hFileMenu, MF_STRING, HandMouse_ID, "Hand");
    AppendMenuA(hFileMenu, MF_STRING, NoMouse_ID, "No");

    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Mouse");

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

HCURSOR hCursor = LoadCursor(nullptr, IDC_ARROW);
LRESULT WndProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
    HDC hdc;
    static Shape *s;
    static Filling *f;
    static Clipping *c;
    static vector<Point> v;
    static int shapeToDraw;
    static bool isLineClipping;
    static bool isPolygonClipping;
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
                case LineBresenham_ID:
                    shapeToDraw = LineBresenham_ID;
                    break;
                case LineParametric_ID:
                    shapeToDraw = LineParametric_ID;
                    break;
                case CircleBresenham_ID:
                    shapeToDraw = CircleBresenham_ID;
                    break;
                case Circle_ID:
                    shapeToDraw = Circle_ID;
                    break;
                case CirclePolar_ID:
                    shapeToDraw = CirclePolar_ID;
                    break;
                case CircleIterativePolar_ID:
                    shapeToDraw = CircleIterativePolar_ID;
                    break;
                case EllipseDirect_ID:
                    shapeToDraw = EllipseDirect_ID;
                    break;
                case EllipsePolar_ID:
                    shapeToDraw = EllipsePolar_ID;
                    break;
                case EllipseMidpoint_ID:
                    shapeToDraw = EllipseMidpoint_ID;
                    break;

                // filling
                case FloodFill_ID:
                    shapeToDraw = FloodFill_ID;
                    break;
                case RecFloodFill_ID:
                    shapeToDraw = RecFloodFill_ID;
                    break;
                case ConvexScanLine_ID:
                    shapeToDraw = ConvexScanLine_ID;
                    break;
                case GeneralScanLine_ID:
                    shapeToDraw = GeneralScanLine_ID;
                    break;
                case CircleLineFill_ID:
                    shapeToDraw = CircleLineFill_ID;
                    break;
                case CircleCirclesFill_ID:
                    shapeToDraw = CircleCirclesFill_ID;
                    break;

                // clipping
                case LineClipping_ID:
                    isLineClipping = true;
                    shapeToDraw = LineClipping_ID;
                    break;

                case PolygonClipping_ID:
                    isPolygonClipping = true;
                    shapeToDraw = PolygonClipping_ID;
                    break;

                case DisableClipping_ID:
                    isLineClipping = false;
                    isPolygonClipping = false;
                    break;

                // mouse shapes
                case ArrowMouse_ID:
                    hCursor = LoadCursor(nullptr, IDC_ARROW);
                    break;
                case CrossMouse_ID:
                    hCursor = LoadCursor(nullptr, IDC_CROSS);
                    break;
                case HandMouse_ID:
                    hCursor = LoadCursor(nullptr, IDC_HAND);
                    break;
                case NoMouse_ID:
                    hCursor = LoadCursor(nullptr, IDC_NO);
                    break;
            }
            break;

        case WM_CREATE:
            CreateWindow(
                    "BUTTON", "Pick a Color",
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1024, 20, 100, 40,
                    hwnd, (HMENU) ColorPicker_ID, (HINSTANCE) GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
            CreateWindow(
                    "BUTTON", "Pick a Filling Color",
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                    800, 20, 200, 40,
                    hwnd, (HMENU) ColorFillingPicker_ID, (HINSTANCE) GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
            break;

        case WM_SETCURSOR:
            SetCursor(hCursor);
            return TRUE;

        case WM_LBUTTONDOWN:
            p.x = LOWORD(lp);
            p.y = HIWORD(lp);
            v.push_back(p);
            break;
        case WM_RBUTTONDOWN:
            if (shapeToDraw == BezierCurve_ID) {
                hdc = GetDC(hwnd);
                s = new BezierCurve(v, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == BezierCurveMidpoint_ID) {
                hdc = GetDC(hwnd);
                s = new BezierCurveMidpoint(v, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == BezierCurveMatrix_ID) {
                hdc = GetDC(hwnd);
                s = new BezierCurveMatrix(v, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == HermiteCurve_ID) {
                hdc = GetDC(hwnd);
                s = new HermiteCurve(v, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == CardinalSpline_ID) {
                hdc = GetDC(hwnd);
                s = new CardinalSpline(v, 3, 1000, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == Polygon_ID) {
                hdc = GetDC(hwnd);
                if (isPolygonClipping) {
                    c->clip(hdc, v);
                }
                s = new GeneralPolygon(v, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == LineDDA_ID) {
                hdc = GetDC(hwnd);
                if (isLineClipping) {
                    c->clip(hdc, v);
                }
                if (!v.empty()) {
                    s = new LinesDDA(v[0], v[1], rgbDrawing);
                    s->draw(hdc, rgbDrawing);
                }
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == LineBresenham_ID) {
                hdc = GetDC(hwnd);
                if (isLineClipping) {
                    c->clip(hdc, v);
                }
                if (!v.empty()) {
                    s = new LineBresenham(v[0], v[1], rgbDrawing);
                    s->draw(hdc, rgbDrawing);
                }
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == LineParametric_ID) {
                hdc = GetDC(hwnd);
                if (isLineClipping) {
                    c->clip(hdc, v);
                }
                if (!v.empty()) {
                    s = new LineParametric(v[0], v[1], rgbDrawing);
                    s->draw(hdc, rgbDrawing);
                }
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == CircleBresenham_ID) {
                hdc = GetDC(hwnd);
                s = new CircleBresenham(v[0], v[1], rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == Circle_ID) {
                hdc = GetDC(hwnd);
                s = new DirectCircle(v[0], v[1], rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == CirclePolar_ID) {
                hdc = GetDC(hwnd);
                s = new PolarCircle(v[0], v[1], rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == CircleIterativePolar_ID) {
                hdc = GetDC(hwnd);
                s = new IterativePolar(v[0], v[1], rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == EllipseDirect_ID) {
                hdc = GetDC(hwnd);

                s = new EllipseDirect(v[0], v[1],v[2], rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == EllipsePolar_ID) {
                hdc = GetDC(hwnd);

                s = new EllipsePolar(v[0], v[1],v[2], rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == EllipseMidpoint_ID) {
                hdc = GetDC(hwnd);

                s = new EllipseMidpoint(v[0], v[1],v[2], rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == FloodFill_ID) {
                hdc = GetDC(hwnd);
                f = new FloodFilling(rgbFilling, rgbDrawing, v[0]);
                f->fill(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if (shapeToDraw == RecFloodFill_ID) {
                hdc = GetDC(hwnd);
                f = new RecursiveFloodFill(rgbFilling, rgbDrawing, v[0]);
                f->fill(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }

            if (shapeToDraw == CircleLineFill_ID) {
                if (v.size() == 2) {
                    hdc = GetDC(hwnd);
                    int quarter = 1;
                    int response = MessageBoxA(hwnd, "Choose quarter:\nYes = 1st\nNo = 2nd\nCancel = More options",
                                               "Select Quarter", MB_YESNOCANCEL);

                    switch (response) {
                        case IDYES: quarter = 1; break;
                        case IDNO:  quarter = 2; break;
                        case IDCANCEL: {
                            int more = MessageBoxA(hwnd, "Choose quarter:\nYes = 3rd\nNo = 4th",
                                                   "Select Quarter", MB_YESNO);
                            quarter = (more == IDYES) ? 3 : 4;
                            break;
                        }
                    }


                    f = new CircleLineFilling(v[0], v[1], quarter, rgbFilling);
                    f->fill(hdc);
                    v.clear();
                    ReleaseDC(hwnd, hdc);
                }
            }
            if(shapeToDraw == CircleCirclesFill_ID){
                cout << "Enter Number of steps needed in filling:\n";
                int steps = 1;
                cin >> steps;
                hdc = GetDC(hwnd);
                int quarter = 1;
                int response = MessageBoxA(hwnd, "Choose quarter:\nYes = 1st\nNo = 2nd\nCancel = More options",
                                           "Select Quarter", MB_YESNOCANCEL);

                switch (response) {
                    case IDYES: quarter = 1; break;
                    case IDNO:  quarter = 2; break;
                    case IDCANCEL: {
                        int more = MessageBoxA(hwnd, "Choose quarter:\nYes = 3rd\nNo = 4th",
                                               "Select Quarter", MB_YESNO);
                        quarter = (more == IDYES) ? 3 : 4;
                        break;
                    }
                }
                f = new CircleCirclesFilling(rgbFilling, v[0], v[1], steps, quarter);
                f->fill(hdc);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }

            if(shapeToDraw == ConvexScanLine_ID){
                hdc = GetDC(hwnd);
                f = new ConvexFilling(rgbFilling, v);
                s = new GeneralPolygon(v, rgbDrawing);
                f->fill(hdc);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
           if(shapeToDraw == GeneralScanLine_ID){
                hdc = GetDC(hwnd);
                f = new GeneralFilling(rgbFilling, v);
                s = new GeneralPolygon(v, rgbDrawing);
                f->fill(hdc);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == LineClipping_ID){
                hdc = GetDC(hwnd);
                c = new LineClipping(v, (int) v[0].x, (int) v[1].x, (int)v[0].y, (int) v[1].y);
                vector<Point> point = {{v[0].x, v[0].y}, {v[1].x, v[0].y}, {v[1].x, v[1].y}, {v[0].x, v[1].y}};
                s = new GeneralPolygon(point, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == PolygonClipping_ID){
                hdc = GetDC(hwnd);
                c = new PolygonClipping(v, (int) v[0].x, (int) v[1].x, (int)v[0].y, (int) v[1].y);
                vector<Point> clipWindow = {{v[0].x, v[0].y}, {v[1].x, v[0].y}, {v[1].x, v[1].y}, {v[0].x, v[1].y}};
                s = new GeneralPolygon(clipWindow, rgbDrawing);
                s->draw(hdc, rgbDrawing);
                v.clear();
                ReleaseDC(hwnd, hdc);
            }
            if(shapeToDraw == LineClipping_ID){
                hdc = GetDC(hwnd);
                c = new LineClipping(v, (int) v[0].x, (int) v[1].x, (int)v[0].y, (int) v[1].y);
                vector<Point> clipWindow = {{v[0].x, v[0].y}, {v[1].x, v[0].y}, {v[1].x, v[1].y}, {v[0].x, v[1].y}};
                s = new GeneralPolygon(clipWindow, rgbDrawing);
                s->draw(hdc, rgbDrawing);
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
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
    wc.lpszClassName = "MyClass";
    wc.lpszMenuName = nullptr;
    wc.lpfnWndProc = WndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hInstance = hi;
    RegisterClass(&wc);
    HWND hwnd = CreateWindow("MyClass", "Sketcher", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                             CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hi, nullptr);
    ShowWindow(hwnd, nsh);
    UpdateWindow(hwnd);
    MSG msg;
    AddCurvesMenu(hwnd);
    AddPolygonsMenu(hwnd);
    AddFillingMenu(hwnd);
    AddClippingMenu(hwnd);
    AddMouseMenu(hwnd);
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}