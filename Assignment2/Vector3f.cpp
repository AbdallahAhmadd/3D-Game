//
//  Vector3f.cpp
//  Assignment2
//
//  Created by NANNA on 10/11/2024.
//

#include "Vector3f.hpp"
#include <cmath>

Vector3f::Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

Vector3f Vector3f::operator+(const Vector3f &v) const {
    return Vector3f(x + v.x, y + v.y, z + v.z);
}

Vector3f Vector3f::operator-(const Vector3f &v) const {
    return Vector3f(x - v.x, y - v.y, z - v.z);
}

Vector3f Vector3f::operator*(float n) const {
    return Vector3f(x * n, y * n, z * n);
}

Vector3f Vector3f::operator/(float n) const {
    return Vector3f(x / n, y / n, z / n);
}

Vector3f Vector3f::unit() const {
    float length = sqrt(x * x + y * y + z * z);
    return *this / length;
}

Vector3f Vector3f::cross(const Vector3f &v) const {
    return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
