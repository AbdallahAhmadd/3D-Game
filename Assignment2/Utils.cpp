//
//  Utils.cpp
//  Assignment2
//
//  Created by NANNA on 11/11/2024.
//

#include "Utils.hpp"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <GLUT/glut.h>



void color(short r, short g, short b) {
    glColor3d(r / 255.0, g / 255.0, b / 255.0);
}

void cylinder(double radius, double height) {
   
    GLUquadric* quad = gluNewQuadric();

    gluCylinder(quad, radius, radius, height, 50, 50);

    glPushMatrix();
    glTranslatef(0, 0, height);
    gluDisk(quad, 0, radius, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glRotated(180, 1, 0, 0);
    gluDisk(quad, 0, radius, 50, 50);
    glPopMatrix();

    gluDeleteQuadric(quad);
}
