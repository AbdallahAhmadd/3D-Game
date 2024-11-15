//
//  DrawCylinder.cpp
//  Assignment2
//
//  Created by NANNA on 11/11/2024.
//

#include "DrawCylinder.hpp"
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

void DrawCylinder(double radius, double length) {
    GLUquadric* quad = gluNewQuadric();  // Create a new quadric object
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);  // Rotate cylinder to align along the Z-axis
    gluCylinder(quad, radius, radius, length, 32, 32);  // Draw cylinder
    glPopMatrix();
    gluDeleteQuadric(quad);  // Delete the quadric object
}


