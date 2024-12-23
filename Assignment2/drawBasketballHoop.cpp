#include "drawBasketballHoop.hpp"
#define GL_SCIENCE_DEPRECATION
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <math.h>


float translateValue = 0.1f;
float translateSpeed = 0.05f;
bool isAnim = false;

void TranslateHoop(int value) {
    if(isAnim){
        translateValue += translateSpeed;
        
        if ( (translateValue > 1.2f || translateValue < -1.2f) && isAnim==true ) {
            translateSpeed = -translateSpeed;
        }
    }else{
        translateValue=0;
    }
    glutPostRedisplay();
    glutTimerFunc(30, TranslateHoop, 0);
}

void drawBasketballHoop() {
    
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 4.0f, -0.5f);
    glScalef(2.0f, 1.2f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    
    glColor3f(1.0f, 0.0f, 0.0f);

    // Top bar
    glPushMatrix();
    glTranslatef(0.0f, 4.25f, -0.30f);
    glScalef(0.6f, 0.1f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Bottom bar
    glPushMatrix();
    glTranslatef(0.0f, 3.75f, -0.30f);
    glScalef(0.6f, 0.1f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left bar
    glPushMatrix();
    glTranslatef(-0.3f, 4.0f, -0.30f);
    glScalef(0.05f, 0.6f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Right bar
    glPushMatrix();
    glTranslatef(0.3f, 4.0f, -0.30f);
    glScalef(0.05f, 0.6f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Hoop Ring
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    glTranslatef(translateValue, 4.0f, 0.1);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(0.04, 0.35, 30, 30);
    glPopMatrix();

    // Net
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(translateValue, 4.0f, 0.1);
    for (float angle = 0; angle < 360; angle += 20) {
        float rad = angle * M_PI / 180.0;
        glPushMatrix();
        glTranslatef(0.35 * cos(rad), -0.4f, 0.35 * sin(rad));
        glScalef(0.04f, 0.8f, 0.04f);
        glutSolidCube(1.0f);
        glPopMatrix();
    }
    glPopMatrix();

    
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glTranslatef(0.0f, 2.0f, -0.5f);
    glScalef(0.1f, 4.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
}
