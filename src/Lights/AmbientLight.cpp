/*
** EPITECH PROJECT, 2026
** AmbientLight.cpp
** File description:
** AmbientLight.cpp
*/

#include "../../includes/AmbientLight.hpp"

Math::Vector3D AmbientLight::illuminate(const Math::Point3D &point,
    const Math::Vector3D &normal) const 
{
    (void)point;
    (void)normal;
    return (Math::Vector3D(intensity, intensity, intensity));
}
