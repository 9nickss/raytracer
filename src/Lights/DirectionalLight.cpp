/*
** EPITECH PROJECT, 2026
** DirectionalLight.cpp
** File description:
** DirectionalLight.cpp
*/

#include "../../includes/DirectionalLight.hpp"
#include <algorithm>

Math::Vector3D DirectionalLight::illuminate(const Math::Point3D &point,
    const Math::Vector3D &normal) const 
{
    double diff = std::max(0.0, normal.dot(-(direction)));
    (void)point;
    return Math::Vector3D(intensity * diff, intensity * diff,
        intensity * diff);
}
