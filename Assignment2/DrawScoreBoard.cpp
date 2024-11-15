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
       glColor3f(0.1f, 0.1f, 0.1f); // Dark color for the frame
       glTranslatef(0.0f, 4.0f, -9.5f); // Position it at the back, elevated above the court
       glScalef(2.0f, 1.0f, 0.1f);       // Scale to create a rectangular frame
       glutSolidCube(1.0f);
       glPopMatrix();

       // Display Screen
       glPushMatrix();
       glColor3f(0.2f, 0.2f, 0.2f); // Darker color for the screen background
       glTranslatef(0.0f, 4.0f, -9.15f); // Position it slightly in front of the frame
       glScalef(1.8f, 0.8f, 0.05f);       // Slightly smaller than the frame
       glutSolidCube(1.0f);
       glPopMatrix();

       // Sample Score (Left Team)
       glPushMatrix();
       glColor3f(1.0f, 0.0f, 0.0f); // Red color for the score
       glTranslatef(-0.5f, 4.1f, -8.9f); // Position on the left side of the screen
       glScalef(0.2f, 0.4f, 0.05f);       // Scale to represent a digit
       glutSolidCube(1.0f);               // Example "score" number as a simple block
       glPopMatrix();

       // Sample Score (Right Team)
       glPushMatrix();
       glColor3f(0.0f, 1.0f, 0.0f); // Green color for the score
       glTranslatef(0.5f, 4.1f, -8.9f); // Position on the right side of the screen
       glScalef(0.2f, 0.4f, 0.05f);       // Scale to represent a digit
       glutSolidCube(1.0f);               // Example "score" number as a simple block
       glPopMatrix();
    
}
