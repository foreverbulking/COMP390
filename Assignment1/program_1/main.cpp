#include <iostream>
#include "../house.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPlacedHouse(250.f, 380.f, 20.f, false);
    drawPlacedHouse(300.f, 250.f, 20.f, true);
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Assignment 1 Program 1 - Anti-aliasing");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}