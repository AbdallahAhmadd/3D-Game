//
//  DrawGround.cpp
//  Assignment2
//
//  Created by NANNA on 11/11/2024.
//

#include "DrawGround.hpp"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <GLUT/glut.h>
#include "Utils.hpp"



void Ground() {
    // Draw the base ground
    color(152,23,23);
    glPushMatrix();
    glTranslatef(0, 0.01, 0);
    glScalef(25, 0.05, 25);
    glutSolidCube(1.0);
    glPopMatrix();
    

    
    
    glColor3f(1.0f, 1.0f, 1.0f);

    // Center circle as a filled disk
    glPushMatrix();
    glTranslatef(0, 0.20, 0); // Position slightly above the ground to avoid z-fighting
    glRotated(90, 1, 0, 0);
    GLUquadric* quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL); // Set to GLU_FILL for a solid disk
    gluDisk(quad, 0.0, 1.0, 50, 1);     // Radius 2.0 for center circle
    gluDeleteQuadric(quad);
    glPopMatrix();
    
    // Semi-circle on the left side
    glPushMatrix();
    glTranslatef(-9.0f, 0.20f, 0); // Position on the left side of the court
    glRotated(90, 1, 0, 0);
    quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL); // Filled style for the semi-circle
    gluPartialDisk(quad, 0.0, 1.5, 50, 1, 0, 180); // Semi-circle with radius 2.0
    gluDeleteQuadric(quad);
    glPopMatrix();
    
    // Semi-circle on the right side
    glPushMatrix();
    
    glTranslatef(9.0f, 0.20f, 0);
    glRotated(90, 1, 0, 0);
    glRotated(180, 0, 1, 0);
  
    
    quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL); // Filled style for the semi-circle
    gluPartialDisk(quad, 0.0, 1.5, 50, 1, 0, 180); // Semi-circle with radius 2.0
    gluDeleteQuadric(quad);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-9, 0.20,0); // Position slightly above the ground to avoid z-fighting
    glRotated(90, 1, 0, 0);
    quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL); // Set to GLU_FILL for a solid disk
    gluPartialDisk(quad, 5.4, 5.5, 50, 1,0,180);     // Radius 2.0 for center circle
    gluDeleteQuadric(quad);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(9, 0.20,0); // Position slightly above the ground to avoid z-fighting
    glRotated(90, 1, 0, 0);
    glRotated(180, 0, 1, 0);
    
    quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL); // Set to GLU_FILL for a solid disk
    gluPartialDisk(quad, 5.4, 5.5, 50, 1,0,180);     // Radius 2.0 for center circle
    gluDeleteQuadric(quad);
    glPopMatrix();
    
    
    
    
}
