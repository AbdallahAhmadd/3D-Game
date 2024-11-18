#include "DrawBall.hpp"
#define GL_SCIENCE_DEPRECATION
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <cmath>
#include "Vector3f.hpp"

// Define the global vector to store the balls


// Function to detect and remove balls colliding with the player


void drawBasketball() {
    // Set color for the basketball
    glColor3f(1.0f, 0.55f, 0.0f);
    glPushMatrix();
    glutSolidSphere(0.4, 30, 30);
    glPopMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    
    // Horizontal line around the sphere (equator)
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(0.02, 0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(0.02, 0.4, 20, 20);
    glPopMatrix();
    
    // Diagonal line 1
    glPushMatrix();
    glRotatef(45, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(0.02, 0.4, 20, 20);
    glPopMatrix();
    
    // Diagonal line 2 (opposite diagonal)
    glPushMatrix();
    glRotatef(-45, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(0.02, 0.4, 20, 20);
    glPopMatrix();
}
