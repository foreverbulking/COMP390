#define GL_SILENCE_DEPRECATION
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 540

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);   // white background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    // Bottom-left: RED
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(250.0, 150.0);

    // Bottom-right: YELLOW
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(450.0, 150.0);

    // Top-right: BLUE
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(450.0, 350.0);

    // Top-left: GREEN
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(250.0, 350.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Program 3 - Colouring and Shading");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}