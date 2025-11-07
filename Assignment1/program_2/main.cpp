#include <iostream>
#include "../house.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    const int   N         = 5;
    const float cx        = WINDOW_WIDTH  * 0.5f;
    const float cy        = WINDOW_HEIGHT * 0.35f;  // arc center moved down to fit all houses
    const float R         = 230.0f;
    const float startDeg  = 200.0f;
    const float endDeg    = 340.0f;

    for (int i = 0; i < N; ++i) {
        float tDeg = startDeg + (endDeg - startDeg) * (float)i / (float)(N - 1);
        float t    = tDeg * (float)M_PI / 180.0f;
        float x = cx + R * cosf(t);
        float y = cy - R * sinf(t);                 // flip vertically by negating sine
        float rotDeg = -(tDeg - 90.0f) + 180.0f;    // flip rotation and add 180 to point roofs outward
        drawPlacedHouse(x, y, rotDeg, true);
    }

    glFlush();
}
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Assignment 1 Program 2 -2D Graphics Transformation");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}