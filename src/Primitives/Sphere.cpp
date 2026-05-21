/*
** EPITECH PROJECT, 2026
** Sphere.cpp
** File description:
** Sphere.cpp
*/

#include "../../includes/Sphere.hpp"

Sphere::Sphere(const Math::Point3D &c, double r, const Math::Vector3D &col) : center(c), radius(r), color(col) {}

bool Sphere::hits(const RayTracer::Ray &ray, double &t) const
{
    double a = ray.direction.dot(ray.direction);
    double b = 2 * ray.direction.dot(ray.origin - this->center);
    double c = (ray.origin - this->center).dot(ray.origin - this->center) -
        (this->radius * this->radius);
    double d = (b * b) - (4 * a * c);
    if (d >= 0) { 
        t = (-b - sqrt(d)) / (2 * a);
        if (t < 0) t = (-b + sqrt(d)) / (2 * a);
        if (t < 0) return false;
        return true; 
    }
    return false;
}

Math::Vector3D Sphere::getNormal(const Math::Point3D &p) const
{
    Math::Vector3D n = p - this->center;
    double len = n.length();
    return Math::Vector3D(n.X / len, n.Y / len, n.Z / len);
}

Math::Vector3D Sphere::getColor() const
{
    return this->color;
}
