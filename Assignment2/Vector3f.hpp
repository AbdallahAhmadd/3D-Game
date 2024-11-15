//
//  Vector3f.hpp
//  Assignment2
//
//  Created by NANNA on 10/11/2024.
//

#ifndef Vector3f_hpp
#define Vector3f_hpp


class Vector3f {
public:
    float x, y, z;

    Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);

    Vector3f operator+(const Vector3f &v) const;
    Vector3f operator-(const Vector3f &v) const;
    Vector3f operator*(float n) const;
    Vector3f operator/(float n) const;
    Vector3f unit() const;
    Vector3f cross(const Vector3f &v) const;
};

#endif // VECTOR3F_HPP


