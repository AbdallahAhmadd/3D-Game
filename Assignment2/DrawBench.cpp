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
       glColor3f(0.7f, 0.4f, 0.1f); // Brown color for the bench seat
       glTranslatef(0.0f, 0.5f, -2.0f); // Position the bench seat above the ground
       glScalef(4.0f, 0.1f, 0.4f);      // Scale to create a long rectangular seat
       glutSolidCube(1.0f);
       glPopMatrix();

       // Left Bench Leg
       glPushMatrix();
       glColor3f(0.4f, 0.2f, 0.0f); // Darker brown color for the legs
       glTranslatef(-1.6f, 0.25f, -2.15f); // Position the left leg under the seat
       glScalef(0.1f, 0.5f, 0.1f);         // Scale to create a small cube as the leg
       glutSolidCube(1.0f);
       glPopMatrix();

       // Right Bench Leg
       glPushMatrix();
       glColor3f(0.4f, 0.2f, 0.0f); // Darker brown color for the legs
       glTranslatef(1.6f, 0.25f, -2.15f); // Position the right leg under the seat
       glScalef(0.1f, 0.5f, 0.1f);       // Scale to create a small cube as the leg
       glutSolidCube(1.0f);
       glPopMatrix();

       // Middle Bench Leg
       glPushMatrix();
       glColor3f(0.4f, 0.2f, 0.0f); // Darker brown color for the legs
       glTranslatef(0.0f, 0.25f, -2.15f); // Position the middle leg under the seat
       glScalef(0.1f, 0.5f, 0.1f);       // Scale to create a small cube as the leg
       glutSolidCube(1.0f);
       glPopMatrix();
    

}
