#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Vector3f.hpp"
#include <GLUT/glut.h>
#include <SFML/Audio.hpp>
class Player {
public:
    Vector3f position;
    Vector3f facingDirection;
    Vector3f up;
    float boundingRadius;
    float rotationAngle = 0.0f;  // New member to store the rotation angle

    // Constructor
    Player(Vector3f pos);

    Vector3f getPosition() const { return position; }
    float getBoundingRadius() const { return boundingRadius; }

    // Movement and Rotation Methods
    void rotateY(float angle);
    void moveForward(float distance);
    void moveBackward(float distance);
    void moveRight(float distance);
    void moveLeft(float distance);
    bool isPlayerInsideFence(const Vector3f& newPosition) const;

    // Draw Method
    void draw();

private:
    GLfloat skinColor[3] = {1.0f, 0.8f, 0.6f};   // Light peach color for skin
    GLfloat shirtColor[3] = {0.0f, 0.0f, 1.0f};  // Blue color for shirt
    // Helper Draw Methods

    void drawHead();
    void drawBody();
    void drawLeftArm();
    void drawRightArm();
    void drawLeftLeg();
    void drawRightLeg();
};

#endif // PLAYER_HPP
