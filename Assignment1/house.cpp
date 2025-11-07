//
// Created by Cookie on 2025-10-31.
//

#include "house.h"

void drawHouse(bool antialiased) {
    if (antialiased) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glLineWidth(1.5f);
    } else {
        glDisable(GL_LINE_SMOOTH);
       glDisable(GL_BLEND);
        glLineWidth(1.0f);
    }

    // Draw the square (house body)
    glBegin(GL_LINE_LOOP);
    glVertex2f(-40.f, -40.f);
    glVertex2f( 40.f, -40.f);
    glVertex2f( 40.f,  40.f);
    glVertex2f(-40.f,  40.f);
    glEnd();

    // Draw the roof (triangle)
    glBegin(GL_LINE_LOOP);
    glVertex2f(-55.f,  40.f);
    glVertex2f(  0.f,  65.f);
    glVertex2f( 55.f,  40.f);
    glEnd();


}

void drawPlacedHouse(float cx, float cy, float rotationDeg, bool antialiased) {
    glPushMatrix();
    glTranslatef(cx, cy, 0.0f);
    glRotatef(rotationDeg, 0.f, 0.f, 1.f);
    drawHouse(antialiased);
    glPopMatrix();
}

void init() {


    //initialize routine
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH,0.0, WINDOW_HEIGHT);

}





void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
    glMatrixMode(GL_MODELVIEW);
}

