//
// Created by alexandre on 09/05/19.
//

#include "Vector3.h"


Vector3::Vector3(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z)
{}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}

float Vector3::dot(const Vector3& rhs)
{
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

Vector3 Vector3::cross(const Vector3& rhs)
{
    return Vector3(this->y * rhs.z - this->z * rhs.y,
                   this->z * rhs.x - this->x * rhs.z,
                   this->x * rhs.y - this->y * rhs.x);
}

float Vector3::norm()
{
    return std::sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::normalize()
{
    float norm = this->norm();
    if (norm != 0.0f)
    {
        x /= norm;
        y /= norm;
        z /= norm;
    }
    return *this;
}

Vector3 Vector3::inverse() const
{
    return Vector3(-this->x, -this->y, -this->z);
}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3 operator-(const Vector3&lhs, const Vector3& rhs)
{
    return Vector3(lhs.x - rhs.x,lhs.y - rhs.y,lhs.z - rhs.z);
}

Vector3 operator*(const Vector3&lhs, const Vector3& rhs)
{
    return Vector3(lhs.x * rhs.x,lhs.y * rhs.y,lhs.z * rhs.z);
}


Vector3 operator*(const Vector3&lhs, const float& rhs)
{
    return Vector3(lhs.x * rhs,lhs.y * rhs,lhs.z * rhs);
}

std::ostream& operator<<(std::ostream& out, const Vector3&lhs)
{
    out << '(' <<lhs.x << ',' <<lhs.y << ',' <<lhs.z << ')';
    return out;
}