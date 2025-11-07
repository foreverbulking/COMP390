#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <math.h>
#include <GLUT/glut.h>
#include "vector3.h"

using namespace std;

// Viewer farther away
vector3 viewer(0.0, 0.0, 100.0);
vector3 wallNormal(0.0, 0.0, 1.0);
vector3 lightPosition(10, 10, 10);
vector3 lightColor(0.75, 0.1, 0.1);

// coefficients
float ambient_coef = 0.3;
float diffuse_coef = 0.7;
float specular_coef = 0.5;
float shininess = 20.0;

// background
void initialize() { glClearColor(0.5, 0.7, 0.5, 0.0); }

// compute local color (now includes specular)
vector3 localColor(vector3 intersect, vector3 baseColor, vector3 normal) {
    vector3 origin = lightPosition.subtract(intersect);
    vector3 L = origin.normalize();
    float NL = max(L.dot(normal), 0.0f);

    // Ambient + Diffuse
    float ambient = ambient_coef;
    float diffuse = diffuse_coef * NL;

    // Specular term
    vector3 R = L.reflect(normal).normalize();
    vector3 V = viewer.subtract(intersect).normalize();
    float RV = max(R.dot(V), 0.0f);
    float specular = specular_coef * pow(RV, shininess);

    float intensity = ambient + diffuse + specular;
    if (intensity > 1.0f) intensity = 1.0f;

    return vector3(
        intensity * baseColor.x,
        intensity * baseColor.y,
        intensity * baseColor.z
    );
}

void render() {
    for (int m=-25; m<25; m++) {
        for (int n=-25; n<25; n++) {
            vector3 color = localColor(vector3(m,n,0), lightColor, wallNormal);
            glColor3f(color.x, color.y, color.z);
            glRecti(m, n, m+1, n+1);
        }
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(viewer.x, viewer.y, viewer.z, 0,0,0, 0,1,0);
    render();
    glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1.5,250.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Assignment 3 - Program 2: Specular Lighting");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initialize();
    glutMainLoop();
    return 0;
}