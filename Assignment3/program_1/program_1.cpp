#define GL_SILENCE_DEPRECATION
#include "program_1.h"

int currentMaterial = 0;
int currentLight = 0;

// Light colors
GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
GLfloat green_light[] = {0.2, 1.0, 0.2, 1.0};
GLfloat red_light[]   = {1.0, 0.4, 0.4, 1.0};
GLfloat blue_light[]  = {0.2, 0.2, 1.0, 1.0};

// Material definitions
GLfloat gold_ambient[]   = {0.24725, 0.1995, 0.0745, 1.0};
GLfloat gold_diffuse[]   = {0.75164, 0.60648, 0.22658, 1.0};
GLfloat gold_specular[]  = {0.628281, 0.555802, 0.366065, 1.0};
GLfloat gold_shininess[] = {51.2};

GLfloat silver_ambient[]   = {0.19225, 0.19225, 0.19225, 1.0};
GLfloat silver_diffuse[]   = {0.50754, 0.50754, 0.50754, 1.0};
GLfloat silver_specular[]  = {0.508273, 0.508273, 0.508273, 1.0};
GLfloat silver_shininess[] = {51.2};

GLfloat copper_ambient[]   = {0.2295, 0.08825, 0.0275, 1.0};
GLfloat copper_diffuse[]   = {0.5508, 0.2118, 0.066, 1.0};
GLfloat copper_specular[]  = {0.580594, 0.223257, 0.06957, 1.0};
GLfloat copper_shininess[] = {51.2};

void setupMaterial(int mat) {
    switch (mat) {
        case 0: // gold
            glMaterialfv(GL_FRONT, GL_AMBIENT,  gold_ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,  gold_diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, gold_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, gold_shininess);
            break;
        case 1: // silver
            glMaterialfv(GL_FRONT, GL_AMBIENT,  silver_ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,  silver_diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, silver_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, silver_shininess);
            break;
        case 2: // copper
            glMaterialfv(GL_FRONT, GL_AMBIENT,  copper_ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,  copper_diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, copper_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, copper_shininess);
            break;
    }
}

void setupLights() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    // Positions of lights
    GLfloat light0_pos[] = {-5.0, 5.0, 5.0, 1.0};
    GLfloat light1_pos[] = {5.0, 5.0, 5.0, 1.0};
    GLfloat light2_pos[] = {0.0, 0.0, 5.0, 1.0};

    // Pick selected light color
    GLfloat *selectedColor;
    switch (currentLight) {
        case 0: selectedColor = white_light; break;
        case 1: selectedColor = red_light;   break;
        case 2: selectedColor = green_light; break;
        case 3: selectedColor = blue_light;  break;
    }

    glLightfv(GL_LIGHT0, GL_DIFFUSE,  selectedColor);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  selectedColor);
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  selectedColor);

    glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    setupLights();
    setupMaterial(currentMaterial);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 6.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    setupLights();
    setupMaterial(currentMaterial);

    glutSolidSphere(1.5, 50, 50);
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 20.0);
}

void menuHandler(int option) {
    if (option >= 0 && option <= 3)
        currentLight = option;        // light color
    else
        currentMaterial = option - 4; // material choice
    glutPostRedisplay();
}