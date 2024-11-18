//
//  DrawPlayer.cpp
//  Assignment2
//
//  Created by NANNA on 11/11/2024.
//
#include "DrawWall.hpp"
#include <GLUT/glut.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include "DrawPlayer.hpp"
#include "Vector3f.hpp"
#include <cmath>
#include "SoundManager.hpp"

#define DEG2RAD(x) ((x) * M_PI / 180.0f)

Player::Player(Vector3f pos)
: position(pos), facingDirection(0, 0, -1), up(0, 1, 0), boundingRadius(0.0f) {
    
}

bool Player::isPlayerInsideFence(const Vector3f& newPosition) const {
    // Wall 1: Front wall (aligned with Z axis)
    float frontWallMinX = -8.5f;
    float frontWallMaxX = 8.5f;
    float frontWallMinY = 0.4f;  // Bottom edge
    float frontWallMaxY = 0.6f;  // Top edge
    float frontWallMinZ = -9.5f;
    float frontWallMaxZ = -8.5f;

    // Wall 2: Left wall (rotated 90 degrees around Y axis, extending along Z-axis)
    float leftWallMinX = -9.25f;  // -9.0 - (0.5 / 2)
    float leftWallMaxX = -8.75f;  // -9.0 + (0.5 / 2)
    float leftWallMinY = 0.25f;   // 0.5 - (0.5 / 2)
    float leftWallMaxY = 0.75f;   // 0.5 + (0.5 / 2)
    float leftWallMinZ = -9.75f;  // 0.0 - (15.5 / 2)
    float leftWallMaxZ = 9.75f;   // 0.0 + (15.5 / 2)

    // Wall 3: Right wall (positioned at 9.0, 0.5, 0.0 and scaled to 0.5 x 0.5 x 15.5)
    float rightWallMinX = 8.75f;  // 9.0 - (0.5 / 2)
    float rightWallMaxX = 9.25f;  // 9.0 + (0.5 / 2)
    float rightWallMinY = 0.25f;  // 0.5 - (0.5 / 2)
    float rightWallMaxY = 0.75f;  // 0.5 + (0.5 / 2)
    float rightWallMinZ = -9.75f; // 0.0 - (15.5 / 2)
    float rightWallMaxZ = 9.75f;  // 0.0 + (15.5 / 2)

    // Wall 4: Back wall (aligned with Z axis, in front of the player)
    float backWallMinX = -8.5f;   // Aligned with front wall X bounds
    float backWallMaxX = 8.5f;    // Aligned with front wall X bounds
    float backWallMinY = 0.4f;    // Bottom edge
    float backWallMaxY = 0.6f;    // Top edge
    float backWallMinZ = 8.5f;    // Positioned in front
    float backWallMaxZ = 9.5f;    // Positioned in front

    // Define player's bounding box based on position and dimensions
    float playerMinX = newPosition.x - 1.5f / 2.0f;
    float playerMaxX = newPosition.x + 1.5f / 2.0f;
    float playerMinY = newPosition.y;
    float playerMaxY = newPosition.y + 5.0f / 2.0f;
    float playerMinZ = newPosition.z - 0.6f / 2.0f;
    float playerMaxZ = newPosition.z + 0.6f / 2.0f;

    // Check for collision with each wall
    bool frontWallCollision =
        playerMaxX > frontWallMinX && playerMinX < frontWallMaxX &&
        playerMaxY > frontWallMinY && playerMinY < frontWallMaxY &&
        playerMaxZ > frontWallMinZ && playerMinZ < frontWallMaxZ;

    bool leftWallCollision =
        playerMaxX > leftWallMinX && playerMinX < leftWallMaxX &&
        playerMaxY > leftWallMinY && playerMinY < leftWallMaxY &&
        playerMaxZ > leftWallMinZ && playerMinZ < leftWallMaxZ;

    bool rightWallCollision =
        playerMaxX > rightWallMinX && playerMinX < rightWallMaxX &&
        playerMaxY > rightWallMinY && playerMinY < rightWallMaxY &&
        playerMaxZ > rightWallMinZ && playerMinZ < rightWallMaxZ;

    bool backWallCollision =
        playerMaxX > backWallMinX && playerMinX < backWallMaxX &&
        playerMaxY > backWallMinY && playerMinY < backWallMaxY &&
        playerMaxZ > backWallMinZ && playerMinZ < backWallMaxZ;

    return frontWallCollision || leftWallCollision || rightWallCollision || backWallCollision;
}

void Player::drawHead() {
    glColor3fv(skinColor);
    glPushMatrix();
    glTranslated(0, 2.5, 0);  // Position the head
    glutSolidSphere(0.4, 20, 20);  // Draw the head
    glPopMatrix();

    // Draw left eye
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);  // Black color for the eyes
    glTranslatef(-0.1, 2.6, 0.35);  // Position the left eye
    glutSolidSphere(0.08, 10, 10);  // Draw the left eye as a small sphere
    glPopMatrix();

    // Draw right eye
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);  // Black color for the eyes
    glTranslatef(0.1, 2.6, 0.35);  // Position the right eye
    glutSolidSphere(0.08, 10, 10);  // Draw the right eye as a small sphere
    glPopMatrix();
}

void Player::drawBody() {
    glColor3fv(shirtColor);
    glPushMatrix();
    glTranslated(0, 1.5, 0);
    glScaled(1.0, 1.2, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Player::drawLeftArm() {
    glColor3fv(shirtColor);
    glPushMatrix();
    glTranslated(-0.65, 1.5, 0);
    glScaled(0.2, 0.6, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glColor3fv(skinColor);
    glPushMatrix();
    glTranslated(-0.65, 0.9, 0);
    glScaled(0.2, 0.4, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Player::drawRightArm() {
    glColor3fv(shirtColor);
    glPushMatrix();
    glTranslated(0.65, 1.5, 0);
    glScaled(0.2, 0.6, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glColor3fv(skinColor);
    glPushMatrix();
    glTranslated(0.65, 0.9, 0);
    glScaled(0.2, 0.4, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Player::drawLeftLeg() {
    glColor3fv(skinColor);
    glPushMatrix();
    glTranslated(-0.3, 0.5, 0);
    glScaled(0.2, 1.0, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Player::drawRightLeg() {
    glColor3fv(skinColor);
    glPushMatrix();
    glTranslated(0.3, 0.5, 0);
    glScaled(0.2, 1.0, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Player::rotateY(float a) {
    
    Vector3f right = up.cross(facingDirection).unit();
    facingDirection = facingDirection * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
    rotationAngle += a; // Update the rotation angle
}


void Player::moveForward(float distance) {
    Vector3f newPosition = position + facingDirection.unit() * distance;
    if (!isPlayerInsideFence(newPosition)) {
        position = newPosition;
        
    }else{
        playSound("hit");
        position = position - facingDirection.unit() * (distance * 1.0f); // Bounce back
    }
}

void Player::moveBackward(float distance) {
    Vector3f newPosition = position - facingDirection.unit() * distance;
    if (!isPlayerInsideFence(newPosition)) {
        
        position = newPosition;
    }else{
        position = position + facingDirection.unit() * (distance * 1.0f); // Bounce back
        playSound("hit");
    }
}

void Player::moveRight(float distance) {
    Vector3f right = up.cross(facingDirection).unit();
    Vector3f newPosition = position + right * distance;
    if (!isPlayerInsideFence(newPosition)) {
        position = newPosition;
    }else{
        
        playSound("hit");
        position = position - right * (distance * 1.0f); // Bounce back
    }
    

}

void Player::moveLeft(float distance) {
    Vector3f right = up.cross(facingDirection).unit();
    Vector3f newPosition = position - right * distance;
    if (!isPlayerInsideFence(newPosition)) {
        position = newPosition;
    }else{
        playSound("hit");
        position = position + right * (distance * 1.0f); // Bounce back
    }
}

void Player::draw() {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);  // Move player to its position
    glRotatef(atan2(facingDirection.x, facingDirection.z) * 180.0f / M_PI, 0, 1, 0);
    drawHead();
    drawBody();
    drawLeftArm();
    drawRightArm();
    drawLeftLeg();
    drawRightLeg();
    glPopMatrix();
}

