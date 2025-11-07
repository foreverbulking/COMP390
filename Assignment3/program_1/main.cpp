#include "program_1.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 540);
    glutCreateWindow("Assignment 3 - Program 1: Lighting and Materials");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // ---- Right-click menu ----
    int lightMenu = glutCreateMenu(menuHandler);
    glutAddMenuEntry("White Light", 0);
    glutAddMenuEntry("Red Light",   1);
    glutAddMenuEntry("Green Light", 2);
    glutAddMenuEntry("Blue Light",  3);

    int materialMenu = glutCreateMenu(menuHandler);
    glutAddMenuEntry("Gold",   4);
    glutAddMenuEntry("Silver", 5);
    glutAddMenuEntry("Copper", 6);

    int mainMenu = glutCreateMenu(menuHandler);
    glutAddSubMenu("Light Color", lightMenu);
    glutAddSubMenu("Material",    materialMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}