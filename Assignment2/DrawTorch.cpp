//
//  DrawTorch.cpp
//  Assignment2
//
//  Created by NANNA on 11/11/2024.
//

#include "DrawTorch.hpp"
#define GL_SCIENCE_DEPRECATION
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include "drawBasketballHoop.hpp"


int flameColorState = 0;

void UpdateFlameColor(int value) {
    flameColorState = (flameColorState + 1) % 3;  // Cycle through 0, 1, 2
    glutPostRedisplay();  // Request display update
    glutTimerFunc(2000, UpdateFlameColor, 0);  // Re-trigger every 2000 ms (2 seconds)
}

void DrawTorch(){
    
    
    
    // Draw the Olympic torch, positioned further to the right
    glPushMatrix();
    glTranslatef(7.0, 0.0, -6.0);   // Move the torch 15 units to the right
    glRotated(-45, 0, 1, 0);        // Optional rotation to adjust angle if needed
    
    GLUquadric* quad = gluNewQuadric();
    
    // Draw the base disk with thickness
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);  // Light gray color for the base
    glTranslatef(0.0, 0.1, 0.0);  // Position slightly above ground
    gluCylinder(quad, 1.0, 1.0, 0.2, 30, 30);  // Thick cylinder for base disk
    glTranslatef(0.0, 0.2, 0.0);  // Move up for top face of the base disk
    gluDisk(quad, 0.0, 1.0, 30, 30);  // Disk on top of the base
    glPopMatrix();
    
    // Draw the standing cube on the base
    glPushMatrix();
    glColor3f(0.8f, 0.5f, 0.2f);  // Bronze color for the cube
    glTranslatef(0.0, 0.5, 0.0);  // Position cube on top of the base disk
    glScaled(0.5, 1.0, 0.5);      // Scale cube to make it taller
    glutSolidCube(1.0);            // Draw the cube
    glPopMatrix();
    
    // Draw the cylinder (flame holder) on top of the cube
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);  // Dark gray for the flame holder
    glTranslatef(0.0, 1.25, 0.0);  // Position on top of the cube
    gluCylinder(quad, 0.25, 0.25, 0.5, 30, 30);  // Thin cylinder for the flame holder
    glPopMatrix();
    
    // Draw the sphere (flame) on top of the cylinder
    glPushMatrix();
    
    
    if (flameColorState == 0 && isAnim==true ) {
           glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    } else if (flameColorState == 1 && isAnim==true) {
           glColor3f(1.0f, 0.5f, 0.0f);  // Orange
       } else {
           glColor3f(1.0f, 0.0f, 0.0f);  // Red
       }
    glTranslatef(0.0, 1.75, 0.0);  // Position above the cylinder
    glutSolidSphere(0.3, 20, 20);  // Sphere representing the flame
    glPopMatrix();
    
    gluDeleteQuadric(quad);  // Clean up quadric object
    glPopMatrix();
    
}
