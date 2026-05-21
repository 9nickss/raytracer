/*
** EPITECH PROJECT, 2026
** Rectangle3D.cpp
** File description:
** Rectangle3D.cpp
*/

#include "../../includes/Math.hpp"

namespace Math {

    Point3D Rectangle3D::pointAt(double u, double v)
    {
        if (u > 1 || u < 0 || v < 0 || v > 1)
            return Point3D(0, 0, 0);
        return Point3D(this->origin + (this->bottom_side * u) +
            (this->left_side * v));
    }

} // namespace Math
