//
// Created by alexandre on 09/05/19.
//

#ifndef TP1_VECTOR3_H
#define TP1_VECTOR3_H

#include <ostream>
#include <stdexcept>
#include <cmath>

struct Vector3
{
    float x;
    float y;
    float z;

    Vector3(float x, float y, float z);

    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);

    float dot(const Vector3& rhs);
    Vector3 cross(const Vector3& rhs);

    float norm();
    Vector3& normalize();

    Vector3 inverse() const;
};


// Operations between vectors
Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
Vector3 operator*(const Vector3& lhs, const Vector3& rhs);


// Operations between vector and scalar
Vector3 operator*(const Vector3& lhs, const float& rhs);


float distance(const Vector3& lhs, const Vector3& rhs);

std::ostream& operator<<(std::ostream& out, const Vector3& lhs);


#endif //TP1_VECTOR3_H
