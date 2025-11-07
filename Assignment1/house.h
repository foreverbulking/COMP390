//
// Created by Cookie on 2025-10-31.
//

#ifndef ASSIGNMENT1_HOUSE_H
#define ASSIGNMENT1_HOUSE_H

// ---------- Standard library headers ----------
#include <cstdio>
#include <cstdlib>
#include <cmath>

// ---------- OpenGL/GLUT header (platform-portable) ----------
#ifdef __APPLE__
#include <GLUT/glut.h>      // macOS
#else
#include <GL/glut.h>        // Windows / Linux
#endif

// ---------- Window constants ----------
#define WINDOW_WIDTH  700
#define WINDOW_HEIGHT 540


void init();
void reshape(int w, int h);

void drawHouse(bool antialiased);
void drawPlacedHouse(float cx, float cy, float rotationDeg, bool antialiased);

#endif

