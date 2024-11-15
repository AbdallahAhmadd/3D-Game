//
//  main.cpp
//  Assignment2
//
//  Created by NANNA on 10/11/2024.
//

#include <stdlib.h>
#include <cmath>
#define GL_SCIENCE_DEPRECATION
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <math.h>
#include <stdio.h>
#include "DrawWall.hpp"
#include "Camera.hpp"
#include "DrawCylinder.hpp"
#include "DrawPlayer.hpp"
#include "DrawGround.hpp"
#include "Utils.hpp"
#include "DrawPodium.hpp"
#include "DrawTorch.hpp"
#include "drawBasketballHoop.hpp"
#include "DrawBench.hpp"
#include "DrawScoreBoard.hpp"
#include "DrawBall.hpp"
#include "SoundManager.hpp"
#define GLUT_KEY_ESCAPE 27


float BenchAngle=0;
float RotateSpeed=2;

float ScoreBoardScale = 1.0f;          // Initial scale value
float ScoreBoardScaleSpeed = 0.01f;    // Increment for smooth scaling

float PodiumTranslate=0.0f;
float podiumSpeed = 0.09f;

float BallAngle=0;
float RotateBallSpeed=5;

int TimeLeft = 60;
int BallsCollected=0;

bool gameOver = false;



Camera camera;
Player player(Vector3f(0.0f, 0.0f, 0.0f));
std::vector<Ball> balls = {
    { Vector3f(-6, 0.4, -3), 0.0f },
    { Vector3f(-5, 0.4, 2), 0.0f },
    { Vector3f(3, 0.4, 5), 0.0f },
    { Vector3f(8, 0.4, -4), 0.0f }
};


void output(int x, int y, float r, float g, float b, void* font, const char* string) {
    glColor3f(r, g, b);  // Set text color
    
    glRasterPos2f(x,y);
    
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);  // Render each character
    }
}

void renderBoldStrokeText(float x, float y, float scale, float r, float g, float b, const char* string, int thickness = 3) {
    glColor3f(r, g, b);
    glPushMatrix();

   
    for (int i = -thickness; i <= thickness; ++i) {
        for (int j = -thickness; j <= thickness; ++j) {
            glPushMatrix();
            glTranslatef(x + i * 0.5f, y + j * 0.5f, 0); // Adjust the offsets for boldness
            glScalef(scale, scale, scale);
            for (const char* c = string; *c != '\0'; ++c) {
                glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
            }
            glPopMatrix();
        }
    }

    glPopMatrix();
}

void renderText(float x, float y, const char* string) {
    glColor3f(1.0f, 1.0f, 1.0f);  // White color
    glRasterPos2f(x, y);

    for (const char* c = string; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}



bool isColliding(const Player& player, const Vector3f& ballPosition) {
    // Player's bounding box half-dimensions
    float playerHalfWidth = 1.5f / 2.0f;
    float playerHalfHeight = 5.0f / 2.0f;
    float playerHalfDepth = 0.6f / 2.0f;
    
    // Calculate the closest point on the player’s bounding box to the ball’s center
    float closestX = std::max(player.position.x - playerHalfWidth, std::min(ballPosition.x, player.position.x + playerHalfWidth));
    float closestY = std::max(player.position.y - playerHalfHeight, std::min(ballPosition.y, player.position.y + playerHalfHeight));
    float closestZ = std::max(player.position.z - playerHalfDepth, std::min(ballPosition.z, player.position.z + playerHalfDepth));
    
    // Calculate the distance from the ball’s center to this closest point
    float dx = ballPosition.x - closestX;
    float dy = ballPosition.y - closestY;
    float dz = ballPosition.z - closestZ;
    float distanceSquared = dx * dx + dy * dy + dz * dz;
    
    // Check if the distance is less than or equal to the radius squared
    return distanceSquared <= 0.4 * 0.4;
}

void setupLights() {
    GLfloat ambientLight[] = { 0.6, 0.6, 0.6, 1.0f };  // Low ambient light
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Moderate diffuse light
    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Specular highlights
    GLfloat lightPosition[] = { 2.0f, 4.0f, 2.0f, 1.0f }; // Position above the ground
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void setupCamera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1400.0 / 800.0, 0.001, 50);  // Aspect ratio as a float
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera.look();
}

void RotateBall(int value) {
    for (auto& ball : balls) {
        ball.rotationAngle += RotateBallSpeed;
        if (ball.rotationAngle >= 360.0f) {
            ball.rotationAngle -= 360.0f;
        }
    }
    
    glutPostRedisplay();
    glutTimerFunc(16, RotateBall, 0);
}


void TranslatePodium(int value) {
    if (isAnim) {
        PodiumTranslate += podiumSpeed;
        if (PodiumTranslate > 2.15 || PodiumTranslate < -1.15)
            podiumSpeed = -podiumSpeed;
    } else {
        PodiumTranslate = 0.0f;  // Default reset value
    }
    glutPostRedisplay();
    glutTimerFunc(16, TranslatePodium, 0);
}


void ScaleScore(int value) {
    if (isAnim) {
        ScoreBoardScale += ScoreBoardScaleSpeed;
        if (ScoreBoardScale > 1.25 || ScoreBoardScale <= 1.0f)
            ScoreBoardScaleSpeed = -ScoreBoardScaleSpeed;
    } else {
        ScoreBoardScale = 1.0f;  // Default reset value
    }
    glutPostRedisplay();
    glutTimerFunc(16, ScaleScore, 0);
}

void RotateBench(int value) {
    if (isAnim) {
        BenchAngle += RotateSpeed;
        if (BenchAngle > 25 || BenchAngle < -25)
            RotateSpeed = -RotateSpeed;
    } else {
        BenchAngle = 0.0f;  // Default reset value
    }
    glutPostRedisplay();
    glutTimerFunc(16, RotateBench, 0);
}
void Display() {
    if (gameOver) {
           // Skip further rendering if game is over
           return;
       }
    setupCamera();
    setupLights();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawWall();
    Ground();
    
    glPushMatrix();
    glTranslated(PodiumTranslate, 0, 0);
    drawOlympicPodium();
    glPopMatrix();
    DrawTorch();
    
    glPushMatrix();
    glTranslated(-8, 0, 0);
    glRotated(90, 0, 1, 0);
    drawBasketballHoop();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(8, 0, 0);
    glRotated(-90, 0, 1, 0);
    
    drawBasketballHoop();
    glPopMatrix();
    
    
    // Left Bench
    glPushMatrix();
    glTranslated(-5, 0, 9);       // Position the bench
    glRotated(BenchAngle, 0, 1, 0); // Rotate around its origin
    DrawBench();
    glPopMatrix();
    
    // Right Bench
    glPushMatrix();
    glTranslated(5, 0, 9);         // Position the bench
    glRotated(BenchAngle, 0, 1, 0); // Rotate around its origin
    DrawBench();
    glPopMatrix();
    
    
    
    
    // Detect collision for each ball and only draw if no collision
    for (auto it = balls.begin(); it != balls.end(); ) {
        if (isColliding(player, it->position)) {
            // Collision detected, remove the ball
            BallsCollected++;
            playSound("collect");
            it = balls.erase(it);
        } else {
            // No collision, draw and rotate the ball
            glPushMatrix();
            glTranslatef(it->position.x, it->position.y, it->position.z);
            glRotatef(it->rotationAngle, 1.0f, 1.0f, 0.0f);  // Apply rotation around y-axis
            drawBasketball();
            glPopMatrix();
            
            // Update the rotation angle for animation
            it->rotationAngle += RotateBallSpeed;
            if (it->rotationAngle >= 360.0f) {
                it->rotationAngle -= 360.0f;
            }
            
            ++it;
        }
    }
    
    glPushMatrix();
    glScaled(ScoreBoardScale, ScoreBoardScale, ScoreBoardScale);
    DrawScoreBoard();
    glPopMatrix();
    player.draw();
    
    // Switch to orthographic projection for 2D overlay
       glMatrixMode(GL_PROJECTION);
       glPushMatrix();
       glLoadIdentity();
       gluOrtho2D(0, 1400, 0, 800);  // Window size for 2D overlay
       
       glMatrixMode(GL_MODELVIEW);
       glPushMatrix();
       glLoadIdentity();

       // Display Timer
       char timerText[16];
       sprintf(timerText, "Time Left: %d", TimeLeft);
       output(1200, 750, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18, timerText);
    
        char BallsText[16];
        sprintf(BallsText, "Balls Collected: %d/4", BallsCollected);
        output(1200, 700, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18, BallsText);
       
 
    if (BallsCollected == 4 && TimeLeft > 0) {
        gameOver = true;
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
       
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(1400, 0);
        glVertex2f(1400, 800);
        glVertex2f(0, 800);
        glEnd();
        
        char GameWin[32];
        sprintf(GameWin, "Winner Winner!");
        renderBoldStrokeText(20, 350, 1.5, 0, 1, 0, GameWin);
 
    }else if(BallsCollected<4 && TimeLeft==0){
        gameOver = true;
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(1400, 0);
        glVertex2f(1400, 800);
        glVertex2f(0, 800);
        glEnd();
        
        char GameLose[32];
        sprintf(GameLose, "Game Lose!");
        renderBoldStrokeText(100, 350, 1.5, 1, 0, 0, GameLose);
    }
    

       // Restore the projection and modelview matrices
       glMatrixMode(GL_PROJECTION);
       glPopMatrix();
       glMatrixMode(GL_MODELVIEW);
       glPopMatrix();
    
    glFlush();
}

void Keyboard(unsigned char key, int x, int y) {
    float d = 0.1;
    
    switch (key) {
            
        case 'l':
            player.rotateY(1.8);
            break;
        case 'r':
            player.rotateY(-1.8);
            break;
        case 'h':
            player.moveForward(0.1);
            break;
        case 'b':
            player.moveRight(0.1);
            break;
        case 'n':
            player.moveBackward(0.1);
            break;
        case 'm':
            player.moveLeft(0.1);
            break;
            
        case 'j':
            isAnim= !isAnim;
            break;
            
        case 'w':
            camera.moveY(d);
            break;
        case 's':
            camera.moveY(-d);
            break;
        case 'a':
            camera.moveX(d);
            break;
        case 'd':
            camera.moveX(-d);
            break;
        case 'q':
            camera.moveZ(d);
            break;
        case 'e':
            camera.moveZ(-d);
            break;
        case 'u':
            camera.eye.x = 0;
            camera.eye.y = 25;
            camera.eye.z = 0;
            
            camera.center.x = 0;
            camera.center.y = 0;
            camera.center.z = 0;
            
            camera.up.x = 0;
            camera.up.y = 0;
            camera.up.z = -1;
            break;
        case 'i':
            camera.eye.x = 35;
            camera.eye.y = 0.00;
            camera.eye.z = 0;
            
            camera.center.x = 0;
            camera.center.y = 0;
            camera.center.z = 0;
            
            camera.up.x = 0;
            camera.up.y = 1;
            camera.up.z = 0;
            break;
        case 'o':
            camera.eye.x = 0;
            camera.eye.y = 0.00;
            camera.eye.z = 35;
            
            camera.center.x = 0;
            camera.center.y = 0;
            camera.center.z = 0;
            
            camera.up.x = 0;
            camera.up.y = 1;
            camera.up.z = 0;
            break;
        case 'p':
            camera.eye.x = 0;
            camera.eye.y = 5.00;
            camera.eye.z = 20;
            
            camera.center.x = 0;
            camera.center.y = 0;
            camera.center.z = 0;
            
            camera.up.x = 0;
            camera.up.y = 1;
            camera.up.z = 0;
            break;
        case GLUT_KEY_ESCAPE:
            exit(EXIT_SUCCESS);
    }
    
    glutPostRedisplay();
}
void Special(int key, int x, int y) {
    float a = 1.0;
    
    switch (key) {
        case GLUT_KEY_UP:
            camera.rotateX(a);
            break;
        case GLUT_KEY_DOWN:
            camera.rotateX(-a);
            break;
        case GLUT_KEY_LEFT:
            camera.rotateY(a);
            break;
        case GLUT_KEY_RIGHT:
            camera.rotateY(-a);
            break;
    }
    
    glutPostRedisplay();
}

void Timer(int value){
    if(TimeLeft>0){
        TimeLeft--;
        glutTimerFunc(1000, Timer, 0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Assignment 2");
    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(Special);
    loadSounds();
    playSound("main");

    glClearColor(0.53f, 0.81f, 0.92f, 0.0f); // Sky blue background
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    
    // Lighting and material settings
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // Set light properties
    setupLights();
    
    // Enable color material to use glColor
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glutTimerFunc(50, updateColor, 0);
    glutTimerFunc(1000, TranslateHoop, 0);
    glutTimerFunc(16, RotateBench, 0);
    glutTimerFunc(16, ScaleScore, 0);
    glutTimerFunc(16, TranslatePodium, 0);
    glutTimerFunc(16, RotateBall, 0);
    glutTimerFunc(16, UpdateFlameColor, 0);
    glutTimerFunc(1000, Timer, 0);
    
    
    glutMainLoop();
}
