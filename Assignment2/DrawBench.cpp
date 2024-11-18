//
//  DrawBench.cpp
//  Assignment2
//
//  Created by NANNA on 13/11/2024.
//

#include "DrawBench.hpp"
#include "drawBasketballHoop.hpp"
#define GL_SCIENCE_DEPRECATION
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <math.h>


void DrawBench(){
  
    // Bench Seat
       glPushMatrix();
       glColor3f(0.7f, 0.4f, 0.1f);
       glTranslatef(0.0f, 0.5f, -2.0f);
       glScalef(4.0f, 0.1f, 0.4f);
       glutSolidCube(1.0f);
       glPopMatrix();

       // Left Bench Leg
       glPushMatrix();
       glColor3f(0.4f, 0.2f, 0.0f);
       glTranslatef(-1.6f, 0.25f, -2.15f);
       glScalef(0.1f, 0.5f, 0.1f);
       glutSolidCube(1.0f);
       glPopMatrix();

       // Right Bench Leg
       glPushMatrix();
       glColor3f(0.4f, 0.2f, 0.0f);
       glTranslatef(1.6f, 0.25f, -2.15f);
       glScalef(0.1f, 0.5f, 0.1f);
       glutSolidCube(1.0f);
       glPopMatrix();

       // Middle Bench Leg
       glPushMatrix();
       glColor3f(0.4f, 0.2f, 0.0f);
       glTranslatef(0.0f, 0.25f, -2.15f);
       glScalef(0.1f, 0.5f, 0.1f);
       glutSolidCube(1.0f);
       glPopMatrix();
    

}
