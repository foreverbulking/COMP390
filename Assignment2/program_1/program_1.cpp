#include "program_1.h"

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 30.0);
}

// ---- Ground ----
void drawGround() {
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-1.0, 0.0, -0.5);
        glVertex3f( 2.0, 0.0, -0.5);
        glVertex3f( 2.0, 0.0,  2.5);
        glVertex3f(-1.0, 0.0,  2.5);
    glEnd();
}

// ---- Cube body ----
void drawCubeBody() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        // Front
        glVertex3f(0.0, 0.0, 1.0);
        glVertex3f(1.0, 0.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.0, 1.0);
        // Back
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
        glVertex3f(1.0, 1.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        // Left
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 1.0, 1.0);
        glVertex3f(0.0, 1.0, 0.0);
        // Right
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(1.0, 1.0, 0.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 0.0, 1.0);
        // Top
        glVertex3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 0.0);
        // Bottom
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 1.0);
    glEnd();
}

// ---- Roof (pyramid) ----
void drawPyramidRoof() {
    glColor3f(0.0, 0.0, 1.0);
    GLfloat top[] = {0.5, 1.5, 0.5};

    glBegin(GL_TRIANGLES);
        // Front
        glVertex3fv(top);
        glVertex3f(-0.2, 1.0, 1.2);
        glVertex3f(1.2, 1.0, 1.2);
        // Back
        glVertex3fv(top);
        glVertex3f(1.2, 1.0, -0.2);
        glVertex3f(-0.2, 1.0, -0.2);
        // Left
        glVertex3fv(top);
        glVertex3f(-0.2, 1.0, -0.2);
        glVertex3f(-0.2, 1.0, 1.2);
        // Right
        glVertex3fv(top);
        glVertex3f(1.2, 1.0, 1.2);
        glVertex3f(1.2, 1.0, -0.2);
    glEnd();
}

// ---- Combine into a house ----
void drawHouse() {
    drawGround();
    drawCubeBody();
    drawPyramidRoof();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0, 3.0, 6.0, 0.5, 0.5, 0.5, 0.0, 1.0, 0.0);

    drawHouse();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
}