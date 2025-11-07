#ifndef ASSIGNMENT2_PROGRAM_2_H
#define ASSIGNMENT2_PROGRAM_2_H

#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init();
void display();
void reshape(int w, int h);
void drawGround();
void drawCubeBody();
void drawPyramidRoof();
void drawHouse();
void drawVillage();

#endif