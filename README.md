# Sketcher
# 🎨 Sketcher Application – 2D Drawing Tool

Welcome to **Sketcher**, a 2D drawing program built using C++ and the Windows API. This application offers a rich set of features for shape drawing, curve rendering, filling algorithms, and geometric clipping, all accessible via a mouse-driven GUI.

---

## 📌 Features

### 💟️ Mouse-Driven GUI

* Complete interaction via **mouse only** (no keyboard input required).
* Custom **mouse pointer** shape for enhanced drawing experience.
* Intuitive **menu system** for selecting options and tools.

### 🎨 Drawing Capabilities

* **Line Drawing Algorithms:**

  * DDA (Digital Differential Analyzer)
  * Midpoint Line Algorithm
  * Parametric Line Drawing
* **Circle Drawing Algorithms:**

  * Direct
  * Polar
  * Iterative Polar
  * Midpoint
  * Modified Midpoint
* **Ellipse Drawing Algorithms:**

  * Direct
  * Polar
  * Midpoint
* **Curve Drawing:**

  * Hermite Curve (used for filling squares vertically)
  * Bezier Curve (used for filling rectangles horizontally)
  * Cardinal Spline Curve

### 🧱 Fill Algorithms

* **Circle Fill:**

  * With lines
  * With other circles
    *(Based on the selected quarter: Top-Left, Top-Right, Bottom-Left, Bottom-Right)*
* **Polygon Fill:**

  * Convex Fill
  * Non-Convex Fill
* **Flood Fill:**

  * Recursive
  * Non-Recursive

### 🚟️ Window & Interaction

* Background can be set to **white** via the menu.
* Mouse shape is customized for a more engaging user experience.
* Combines **console output** with the GUI for logging and debugging.

### 📁 File Operations

* **Save**: Save all drawn shapes and data to a file.
* **Load**: Load and restore drawing data from saved files.

### ✂️ Clipping Algorithms

* **Rectangle Clipping Window:**

  * Clip: Point, Line, Polygon
* **Square Clipping Window:**

  * Clip: Point, Line

---

## 🧑‍💻 How to Use

1. **Run the application**.
2. Use the **menu bar** to:

   * Select drawing tools
   * Choose shape color
   * Change background
   * Perform filling
   * Apply clipping
   * Save/load your work
   * Clear the canvas
3. **Click and drag** on the canvas to draw shapes.
4. Use **right-click or menu options** to switch tools or access advanced features.

---

## 🛠 Build Instructions

### Requirements:

* Windows OS
* C++ compiler (e.g., MinGW or MSVC)
* Win32 API libraries (`windows.h`, `commdlg.h`)

### Compilation (MinGW example):

```bash
g++ -o Sketcher sketcher.cpp -mwindows
```

If you're using Visual Studio:

* Create a new **Windows Desktop Application** project.
* Add the source files and build.

---
