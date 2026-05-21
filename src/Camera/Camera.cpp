/*
** EPITECH PROJECT, 2026
** Camera.cpp
** File description:
** Camera.cpp
*/

#include "../../includes/Raytracer.hpp"

namespace RayTracer {

    Ray Camera::ray(double u, double v)
    {
        return Ray(this->origin, (this->screen.pointAt(u, v) - this->origin));
    }

} // namespace RayTracer
