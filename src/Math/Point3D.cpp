/*
** EPITECH PROJECT, 2026
** Point3D.cpp
** File description:
** Point3D.cpp
*/

#include "../../includes/Math.hpp"

namespace Math {

    Point3D Point3D::operator+(const Vector3D &other) const
    {
        return Point3D(this->X + other.X, this->Y + other.Y, this->Z + other.Z);
    }

    Vector3D Point3D::operator-(const Point3D &other) const
    {
        return Vector3D(this->X - other.X, this->Y - other.Y, this->Z - other.Z);
    }

} // namespace Math
