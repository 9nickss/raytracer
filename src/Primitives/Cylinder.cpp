/*
** EPITECH PROJECT, 2026
** Cylinder.cpp
** File description:
** Cylinder.cpp
*/

#include "../../includes/Cylinder.hpp"

Cylinder::Cylinder(const Math::Point3D &c, double r, const Math::Vector3D &col, const Rotation &rot) : center(c), radius(r), color(col), rotation(rot) {}

bool Cylinder::hits(const RayTracer::Ray &ray, double &t) const
{
    Math::Vector3D localOrigin(
        ray.origin.X - center.X,
        ray.origin.Y - center.Y,
        ray.origin.Z - center.Z
    );
    Math::Vector3D rotOrigin = rotation.applyInverseToVector(localOrigin);
    Math::Vector3D rotDir = rotation.applyInverseToVector(ray.direction);

    double a = rotDir.X * rotDir.X + rotDir.Z * rotDir.Z;
    double b = 2 * (rotOrigin.X * rotDir.X + rotOrigin.Z * rotDir.Z);
    double c = rotOrigin.X * rotOrigin.X + rotOrigin.Z * rotOrigin.Z - radius * radius;
    double d = b * b - 4 * a * c;
    if (d >= 0) {
        t = (-b - sqrt(d)) / (2 * a);
        return t >= 0;
    }
    return false;
}

Math::Vector3D Cylinder::getNormal(const Math::Point3D &p) const
{
    Math::Vector3D localP(p.X - center.X, p.Y - center.Y, p.Z - center.Z);
    localP = rotation.applyInverseToVector(localP);
    Math::Vector3D n(localP.X, 0, localP.Z);
    n = rotation.applyToVector(n);
    double len = n.length();
    return Math::Vector3D(n.X / len, n.Y / len, n.Z / len);
}

Math::Vector3D Cylinder::getColor() const
{
    return this->color;
}
