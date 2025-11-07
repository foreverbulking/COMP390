#ifndef ASSIGNMENT3_PROGRAM_1_H
#define ASSIGNMENT3_PROGRAM_1_H

#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init();
void display();
void reshape(int w, int h);
void setupLights();
void setupMaterial(int mat);
void menuHandler(int option);

#endif