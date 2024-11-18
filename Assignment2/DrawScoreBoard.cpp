//
//  DrawScoreBoard.cpp
//  Assignment2
//
//  Created by NANNA on 13/11/2024.
//

#include "DrawScoreBoard.hpp"
#include "drawBasketballHoop.hpp"
#define GL_SCIENCE_DEPRECATION
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <math.h>

void DrawScoreBoard(){
    // Scoreboard Frame
       glPushMatrix();
       glColor3f(0.1f, 0.1f, 0.1f);
       glTranslatef(0.0f, 4.0f, -9.5f);
       glScalef(2.0f, 1.0f, 0.1f);
       glutSolidCube(1.0f);
       glPopMatrix();

       // Display Screen
       glPushMatrix();
       glColor3f(0.2f, 0.2f, 0.2f);
       glTranslatef(0.0f, 4.0f, -9.15f);
       glScalef(1.8f, 0.8f, 0.05f);
       glutSolidCube(1.0f);
       glPopMatrix();

       // Sample Score (Left Team)
       glPushMatrix();
       glColor3f(1.0f, 0.0f, 0.0f);
       glTranslatef(-0.5f, 4.1f, -8.9f);
       glScalef(0.2f, 0.4f, 0.05f);
       glutSolidCube(1.0f);
       glPopMatrix();

       // Sample Score (Right Team)
       glPushMatrix();
       glColor3f(0.0f, 1.0f, 0.0f);
       glTranslatef(0.5f, 4.1f, -8.9f);
       glScalef(0.2f, 0.4f, 0.05f);
       glutSolidCube(1.0f);               
       glPopMatrix();
    
}
