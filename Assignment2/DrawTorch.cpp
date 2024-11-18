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
    glTranslatef(7.0, 0.0, -6.0);
    glRotated(-45, 0, 1, 0);
    
    GLUquadric* quad = gluNewQuadric();
    
    // Draw the base disk with thickness
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0.0, 0.1, 0.0);  
    gluCylinder(quad, 1.0, 1.0, 0.2, 30, 30);  // Thick cylinder for base disk
    glTranslatef(0.0, 0.2, 0.0);  // Move up for top face of the base disk
    gluDisk(quad, 0.0, 1.0, 30, 30);  // Disk on top of the base
    glPopMatrix();
    
    // Draw the standing cube on the base
    glPushMatrix();
    glColor3f(0.8f, 0.5f, 0.2f);
    glTranslatef(0.0, 0.5, 0.0);
    glScaled(0.5, 1.0, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Draw the cylinder (flame holder) on top of the cube
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glTranslatef(0.0, 1.25, 0.0);
    gluCylinder(quad, 0.25, 0.25, 0.5, 30, 30);
    glPopMatrix();
    
   
    glPushMatrix();
    
    
    if (flameColorState == 0 && isAnim==true ) {
           glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    } else if (flameColorState == 1 && isAnim==true) {
           glColor3f(1.0f, 0.5f, 0.0f);  // Orange
       } else {
           glColor3f(1.0f, 0.0f, 0.0f);  // Red
       }
    glTranslatef(0.0, 1.75, 0.0);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();
    
    gluDeleteQuadric(quad);
    glPopMatrix();
    
}
