//
//  DrawPodium.cpp
//  Assignment2
//
//  Created by NANNA on 11/11/2024.
//



#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include "DrawPodium.hpp"

void drawText(const char* text, float x, float y, float z) {

    glRasterPos3f(x, y, z);  // Position the text
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);  // Use a bitmap font
    }
}

void drawOlympicPodium() {
    
    glPushMatrix();
    glTranslated(-4, 0, -7);
    
    
    GLUquadric* quad = gluNewQuadric();

    // Draw the 1st place platform
    glPushMatrix();
    glColor3f(1.0f, 0.9f, 0.3f);  // Gold-like color
    glTranslatef(0.0, 0.5, 0.0);  // Center platform
    glScaled(2.0, 1.0, 1.0);      // Larger scale for the 1st place platform
    glutSolidCube(1.0);           // Draw the platform as a cube
    glPopMatrix();

    // Draw the 2nd place platform (slightly lower)
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);  // Silver-like color
    glTranslatef(-2.5, 0.3, 0.0); // Position left for 2nd place
    glScaled(2.0, 0.6, 1.0);      // Slightly lower height
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the 3rd place platform (even lower)
    glPushMatrix();
    glColor3f(0.8f, 0.5f, 0.2f);  // Bronze-like color
    glTranslatef(2.5, 0.2, 0.0);  // Position right for 3rd place
    glScaled(2.0, 0.4, 1.0);      // Lower height
    glutSolidCube(1.0);
    glPopMatrix();

//    // Draw cylinders (decorative columns) on each platform
//    glColor3f(0.5f, 0.5f, 0.5f);  // Gray for columns
//    glPushMatrix();
//    glTranslatef(-1.0, 0.5, -0.5); // Front-left of 1st place
//    gluCylinder(quad, 0.1, 0.1, 0.5, 20, 20);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(1.0, 0.5, -0.5); // Front-right of 1st place
//    gluCylinder(quad, 0.1, 0.1, 0.5, 20, 20);
//    glPopMatrix();
//
//    

    // Draw disk for numbers on the 1st place
    glColor3f(0.0f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(0.0, 1.45, 0.0); // Center of 1st place top, slightly raised
    gluDisk(quad, 0.0, 0.3, 20, 20);
    glPopMatrix();

    // Draw disk for numbers on the 2nd place
    glPushMatrix();
    glTranslatef(-2.5, 0.90, 0.0); // Center of 2nd place top, slightly raised
    gluDisk(quad, 0.0, 0.3, 20, 20);
    glPopMatrix();

    // Draw disk for numbers on the 3rd place
    glPushMatrix();
    glTranslatef(2.5, 0.70, 0.0);  // Center of 3rd place top, slightly raised
    gluDisk(quad, 0.0, 0.3, 20, 20);
    glPopMatrix();
    glPopMatrix();
   


    gluDeleteQuadric(quad);
}
