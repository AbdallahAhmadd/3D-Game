#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vector3f.hpp"
#include <GLUT/glut.h>

class Camera {
public:
    Vector3f eye, center, up;
    Camera(float eyeX = 0.0f, float eyeY = 5.0f, float eyeZ = 20.0f,
           float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f,
           float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f);

    // Camera movement methods
    void moveX(float d);
    void moveY(float d);
    void moveZ(float d);

    // Camera rotation methods
    void rotateX(float a);
    void rotateY(float a);

    // Set up the view in OpenGL
    void look();
};

#endif // CAMERA_HPP
