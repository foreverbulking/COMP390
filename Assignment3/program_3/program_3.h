#ifndef ASSIGNMENT2_PROGRAM_3_H
#define ASSIGNMENT2_PROGRAM_3_H

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
GLuint loadBMP(const char* filename);
void drawBackground();

#endif