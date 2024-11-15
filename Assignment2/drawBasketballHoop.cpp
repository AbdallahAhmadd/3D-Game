#include "drawBasketballHoop.hpp"
#define GL_SCIENCE_DEPRECATION
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <math.h>


float translateValue = 0.1f;  // Make this a float for smooth movement
float translateSpeed = 0.05f; // Adjust speed as needed
bool isAnim = true;

void TranslateHoop(int value) {
    if(isAnim){
        translateValue += translateSpeed;
        // Reverse direction if it reaches the limits
        if ( (translateValue > 1.2f || translateValue < -1.2f) && isAnim==true ) {
            translateSpeed = -translateSpeed;
        }
    }else{
        translateValue=0;
    }
    glutPostRedisplay(); // Request display update
    glutTimerFunc(30, TranslateHoop, 0); // Re-trigger every 30ms
}

void drawBasketballHoop() {
    // Backboard
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White backboard
    glTranslatef(0.0f, 4.0f, -0.5f); // Position the backboard
    glScalef(2.0f, 1.2f, 0.1f);       // Scale to a rectangular shape
    glutSolidCube(1.0f);
    glPopMatrix();

    // Red rectangle outline on the backboard using 4 cubes
    glColor3f(1.0f, 0.0f, 0.0f); // Red color

    // Top bar
    glPushMatrix();
    glTranslatef(0.0f, 4.25f, -0.30f); // Position top bar in front of the backboard
    glScalef(0.6f, 0.1f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Bottom bar
    glPushMatrix();
    glTranslatef(0.0f, 3.75f, -0.30f);
    glScalef(0.6f, 0.1f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left bar
    glPushMatrix();
    glTranslatef(-0.3f, 4.0f, -0.30f);
    glScalef(0.05f, 0.6f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Right bar
    glPushMatrix();
    glTranslatef(0.3f, 4.0f, -0.30f);
    glScalef(0.05f, 0.6f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Hoop Ring
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color for the hoop ring
    glTranslatef(translateValue, 4.0f, 0.1); // Animated translation on the z-axis
    glRotatef(90, 1, 0, 0); // Rotate 90 degrees around the x-axis to make the ring horizontal
    glutSolidTorus(0.04, 0.35, 30, 30); // Smaller torus to simulate the ring
    glPopMatrix();

    // Net
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White net
    glTranslatef(translateValue, 4.0f, 0.1);
    for (float angle = 0; angle < 360; angle += 20) {
        float rad = angle * M_PI / 180.0;
        glPushMatrix();
        glTranslatef(0.35 * cos(rad), -0.4f, 0.35 * sin(rad)); // Smaller radius for net placement
        glScalef(0.04f, 0.8f, 0.04f);
        glutSolidCube(1.0f); // Small cube simulating a net segment
        glPopMatrix();
    }
    glPopMatrix();

    // Pole
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f); // Gray color for the pole
    glTranslatef(0.0f, 2.0f, -0.5f); // Position the pole to hold the backboard
    glScalef(0.1f, 4.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
}
