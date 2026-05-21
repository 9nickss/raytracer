/*
** EPITECH PROJECT, 2026
** Vector3D.cpp
** File description:
** Vector3D.cpp
*/

#include "../../includes/Math.hpp"

namespace Math {

    double Vector3D::dot(const Vector3D &other) const
    {
        return ((this->X * other.X) + (this->Y * other.Y) +
            (this->Z * other.Z));
    }

    double Vector3D::length() const
    {
        return sqrt((X * X) + (Y * Y) + (Z * Z));
    }

    Vector3D Vector3D::operator*(double a) const
    {
        return Vector3D(this->X * a, this->Y * a, this->Z * a);
    }

    Vector3D Vector3D::operator+(const Vector3D &other)
    {
        return Vector3D(this->X + other.X, this->Y + other.Y, this->Z + other.Z);
    }

    Vector3D Vector3D::operator*(const Vector3D &other) const
    {
        return Vector3D(this->X * other.X, this->Y * other.Y, this->Z * other.Z);
    }

    Vector3D Vector3D::operator-() const {
        return Vector3D(-X, -Y, -Z);
    }

} // namespace Math
