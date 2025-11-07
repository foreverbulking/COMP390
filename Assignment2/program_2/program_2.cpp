#define GL_SILENCE_DEPRECATION
#include "program_2.h"

// Initializes rendering states. This function is called once at the beginning.
void init() {
    // Set the clear color to white and enable depth testing for 3D occlusion.
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    // Set polygon drawing mode to filled to draw solid objects.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    // Set up the projection matrix to define the camera's viewing volume.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Defines a perspective projection matrix.
    // 60.0: Field of view angle in degrees.
    // 1.0: Aspect ratio (width/height).
    // 1.0, 50.0: Near and far clipping planes.
    gluPerspective(60.0, 1.0, 1.0, 50.0);
}

// ---- Base components ----
// Draws the main grey ground plane.
void drawCityGround() {
    // Grey ground
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
        glVertex3f(-8.0, -0.1, -8.0);
        glVertex3f(-8.0, -0.1,  8.0);
        glVertex3f( 8.0, -0.1,  8.0);
        glVertex3f( 8.0, -0.1, -8.0);
    glEnd();
}

// Draws a single green lot at a specified position and scale.
void drawGreenLot(float x, float z, float scale) {
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    // The y-coordinate is slightly elevated (0.0) compared to the grey ground (-0.1)
    // to prevent Z-fighting, where the renderer struggles to decide which polygon to show.
    glTranslatef(x, 0.0, z); // y is 0.0 to sit on top of grey ground at -0.1
    glScalef(scale, 1.0, scale);
    glBegin(GL_QUADS);
        glVertex3f(-1.5, 0.0, -1.5);
        glVertex3f(-1.5, 0.0,  1.5);
        glVertex3f( 1.5, 0.0,  1.5);
        glVertex3f( 1.5, 0.0, -1.5);
    glEnd();
    glPopMatrix();
}

// Draws a unit cube with its base at y=0.
void drawCubeBody() {
    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_QUADS);
        // Front
        glVertex3f(-1.0, 0.0, 1.0);
        glVertex3f(1.0, 0.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        // Back
        glVertex3f(-1.0, 0.0, -1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.0, 0.0, -1.0);
        // Top
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        // Bottom
        glVertex3f(-1.0, 0.0, -1.0);
        glVertex3f(1.0, 0.0, -1.0);
        glVertex3f(1.0, 0.0, 1.0);
        glVertex3f(-1.0, 0.0, 1.0);
        // Right
        glVertex3f(1.0, 0.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 0.0, 1.0);
        // Left
        glVertex3f(-1.0, 0.0, -1.0);
        glVertex3f(-1.0, 0.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
    glEnd();
}

// Draws a pyramid roof that sits on top of the unit cube.
void drawPyramidRoof() {
    glColor3f(0.0, 0.0, 1.0); // Blue
    glBegin(GL_TRIANGLES);
        // Front
        glVertex3f(-1.2, 1.0, 1.2);
        glVertex3f(1.2, 1.0, 1.2);
        glVertex3f(0.0, 2.0, 0.0);
        // Right
        glVertex3f(1.2, 1.0, 1.2);
        glVertex3f(1.2, 1.0, -1.2);
        glVertex3f(0.0, 2.0, 0.0);
        // Back
        glVertex3f(1.2, 1.0, -1.2);
        glVertex3f(-1.2, 1.0, -1.2);
        glVertex3f(0.0, 2.0, 0.0);
        // Left
        glVertex3f(-1.2, 1.0, -1.2);
        glVertex3f(-1.2, 1.0, 1.2);
        glVertex3f(0.0, 2.0, 0.0);
    glEnd();
}

// ---- Combine components ----
// A composite function that draws a complete house.
void drawHouse() {
    drawCubeBody();
    drawPyramidRoof();
}

// Draws a house at a specific location, with transformations for scale, rotation, and type (tower).
// This function uses the matrix stack to ensure transformations for one house do not affect others.
void drawHouseAt(float x, float y, float z, float scale, float rotation, bool isTower) {
    glPushMatrix(); // Save the current matrix state.
    
    // Apply transformations: Translate, Scale, and Rotate.
    // The order of transformations is important.
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);
    if (isTower) {
        glScalef(1.0, 2.0, 1.0); // Apply additional scaling for the tower.
    }
    glRotatef(rotation, 0.0, 1.0, 0.0);
    
    drawHouse(); // Draw the object with the applied transformations.
    
    glPopMatrix(); // Restore the matrix state, removing the transformations for this house.
}

// ---- Scene composition ----
// This function orchestrates the drawing of the entire village scene.
// It uses a data-driven approach, defining positions and scales in arrays
// to systematically place each element in the scene.
void drawVillage() {
    drawCityGround();

    // Define house positions in a 2D array for easy management.
    float positions[8][3] = {
        {-5.0, 0.0, -5.0}, {-1.0, 0.0, -5.0}, {3.0, 0.0, -5.0},
        {-5.0, 0.0, -1.0}, {-1.0, 0.0, -1.0},
        {6.0, 0.0, -1.0}, // Adjusted this house's x-position
        {-5.0, 0.0,  3.0}, {3.0, 0.0,  3.0}
    };

    // Define house scales, allowing some houses to be larger than others.
    float scales[] = {1.2, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

    // Loop through the data arrays to draw each lot and house.
    for (int i = 0; i < 8; ++i) {
        drawGreenLot(positions[i][0], positions[i][2], scales[i]);
        bool isTower = (i == 5); // The 6th house is designated as the tower.
        drawHouseAt(positions[i][0], positions[i][1], positions[i][2], scales[i], 0, isTower);
    }
}

// ---- Display ----
// The main display callback function, called whenever the window needs to be redrawn.
void display() {
    // Clear the color and depth buffers before drawing the new frame.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Switch to the modelview matrix to position and orient the camera and objects.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set up the camera's position and orientation.
    // It's positioned at (5, 7, 10), looks at the origin (0,0,0),
    // with the 'up' direction along the positive Y-axis.
    gluLookAt(5.0, 7.0, 10.0,   // eye position
              0.0, 0.0, 0.0,     // look at origin
              0.0, 1.0, 0.0);    // up vector

    drawVillage(); // Draw the entire scene.
    
    // Swap the front and back buffers to display the rendered image.
    glutSwapBuffers();
}

// ---- Reshape ----
// This function is called when the window is resized.
void reshape(int w, int h) {
    // Set the viewport to cover the new window dimensions.
    glViewport(0, 0, w, h);
    
    // Re-calculate the projection matrix to maintain the aspect ratio.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // The aspect ratio is updated to match the new window dimensions, preventing distortion.
    gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
}