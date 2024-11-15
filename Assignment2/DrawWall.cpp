#include "DrawWall.hpp"
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include "DrawWall.hpp"


float ballColor[3] = {1.0f, 0.55f, 0.0f}; // Initial basketball orange color
int colorDirection = 1; // Direction to change color components



void updateColor(int value) {
    // Update color components over time
    for (int i = 0; i < 3; i++) {
        ballColor[i] += colorDirection * 0.01f;
        if (ballColor[i] >= 1.0f) {
            ballColor[i] = 1.0f;
            colorDirection = -1;
        }
        if (ballColor[i] <= 0.0f) {
            ballColor[i] = 0.0f;
            colorDirection = 1;
        }
    }

    glutPostRedisplay(); // Request display update
    glutTimerFunc(50, updateColor, 0); // Re-trigger this function every 50ms
}




void drawWall() {
    // Set color for the wall
    glColor3f(ballColor[0], ballColor[1], ballColor[2]);  // Light gray color
    
    // Draw the wall
    glPushMatrix();
    glTranslated(0.0, 0.5, -9.0);  // Position the wall slightly above the ground
    glScaled(15.0, 0.2, 0.1);     // Scale to make it short and wide
    glutSolidCube(1.0);           // Draw wall as a scaled cube
    glPopMatrix();

    // Set color for the cylinders (hinges)
    glColor3f(ballColor[0], ballColor[1], ballColor[2]);  // Light gray color
    
    // Draw left cylinder (hinge)
    glPushMatrix();
    glTranslated(-7.5, 0.5, -9.0); // Position at the left end of the wider wall
    glRotated(90, 1, 0, 0);       // Rotate to align vertically
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, 0.15, 0.15, 0.4, 20, 20);  // Cylinder with radius 0.1 and height 0.4
    gluDeleteQuadric(quad);
    glPopMatrix();

    // Draw right cylinder (hinge)
    glPushMatrix();
    glTranslated(7.5, 0.5, -9.0);  // Position at the right end of the wider wall
    glRotated(90, 1, 0, 0);       // Rotate to align vertically
    quad = gluNewQuadric();
    gluCylinder(quad, 0.15, 0.15, 0.4, 20, 20);  // Cylinder with radius 0.1 and height 0.4
    gluDeleteQuadric(quad);
    glPopMatrix();
    
    
    
    
    // Draw left the wall
    glPushMatrix();
    glRotated(90, 0, 1, 0);
    
    glPushMatrix();
    glTranslated(0.0, 0.5, -9.0);  // Position the wall slightly above the ground
    glScaled(15.0, 0.2, 0.1);     // Scale to make it short and wide
    glutSolidCube(1.0);           // Draw wall as a scaled cube
    glPopMatrix();

    // Set color for the cylinders (hinges)
    glColor3f(ballColor[0], ballColor[1], ballColor[2]);
    
    // Draw left cylinder (hinge)
    glPushMatrix();
    glTranslated(-7.5, 0.5, -9.0); // Position at the left end of the wider wall
    glRotated(90, 1, 0, 0);       // Rotate to align vertically
    GLUquadric* quad2 = gluNewQuadric();
    gluCylinder(quad2, 0.15, 0.15, 0.4, 20, 20);  // Cylinder with radius 0.1 and height 0.4
    gluDeleteQuadric(quad2);
    glPopMatrix();

    // Draw right cylinder (hinge)
    glPushMatrix();
    glTranslated(7.5, 0.5, -9.0);  // Position at the right end of the wider wall
    glRotated(90, 1, 0, 0);       // Rotate to align vertically
    quad = gluNewQuadric();
    gluCylinder(quad, 0.15, 0.15, 0.4, 20, 20);  // Cylinder with radius 0.1 and height 0.4
    gluDeleteQuadric(quad);
    glPopMatrix();
    glPopMatrix();
    
    
    
    // Draw right the wall
    glPushMatrix();
    glRotated(-90, 0, 1, 0);
    
    glPushMatrix();
    glTranslated(0.0, 0.5, -9.0);  // Position the wall slightly above the ground
    glScaled(15.0, 0.2, 0.1);     // Scale to make it short and wide
    glutSolidCube(1.0);           // Draw wall as a scaled cube
    glPopMatrix();

    // Set color for the cylinders (hinges)
    glColor3f(ballColor[0], ballColor[1], ballColor[2]);  // Light gray color
    
    // Draw left cylinder (hinge)
    glPushMatrix();
    glTranslated(-7.5, 0.5, -9.0); // Position at the left end of the wider wall
    glRotated(90, 1, 0, 0);       // Rotate to align vertically
    GLUquadric* quad3 = gluNewQuadric();
    gluCylinder(quad3, 0.15, 0.15, 0.4, 20, 20);  // Cylinder with radius 0.1 and height 0.4
    gluDeleteQuadric(quad3);
    glPopMatrix();

    // Draw right cylinder (hinge)
    glPushMatrix();
    glTranslated(7.5, 0.5, -9.0);  // Position at the right end of the wider wall
    glRotated(90, 1, 0, 0);       // Rotate to align vertically
    quad = gluNewQuadric();
    gluCylinder(quad, 0.15, 0.15, 0.4, 20, 20);  // Cylinder with radius 0.1 and height 0.4
    gluDeleteQuadric(quad);
    glPopMatrix();
    glPopMatrix();
    

}
