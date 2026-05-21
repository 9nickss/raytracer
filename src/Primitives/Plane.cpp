/*
** EPITECH PROJECT, 2026
** Plane.cpp
** File description:
** Plane.cpp
*/

#include "../../includes/Plane.hpp"

Plane::Plane(const Math::Point3D &p, const Math::Vector3D &n, const Math::Vector3D &c, const Rotation &rot) : point(p), normal(n), color(c), rotation(rot) 
{
    normal = rot.applyToVector(n);
}

bool Plane::hits(const RayTracer::Ray &ray, double &t) const
{
    double d = normal.dot(ray.direction);

    if (std::abs(d) < 1e-6)
        return false;
    t = (point - ray.origin).dot(normal) / d;
    return t >= 0;
}

Math::Vector3D Plane::getNormal(const Math::Point3D &p) const
{
    (void)p;
    return this->normal;
}

Math::Vector3D Plane::getColor() const
{
    return this->color;
}
