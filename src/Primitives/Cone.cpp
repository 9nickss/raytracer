/*
** EPITECH PROJECT, 2026
** Cone.cpp
** File description:
** Cone.cpp
*/

#include "../../includes/Cone.hpp"

Cone::Cone(double h, double r, const Math::Point3D &a, const Math::Vector3D &c, const Rotation &rot) : height(h), radius(r), apex(a), color(c), rotation(rot) {}

Math::Vector3D Cone::getNormal(const Math::Point3D &p) const
{
    Math::Vector3D localP(p.X - apex.X, p.Y - apex.Y, p.Z - apex.Z);
    localP = rotation.applyInverseToVector(localP);

    double k = radius / height;
    Math::Vector3D n(
        localP.X,
        -k * k * localP.Y,
        localP.Z
    );
    n = rotation.applyToVector(n);
    double len = n.length();
    return Math::Vector3D(n.X / len, n.Y / len, n.Z / len);
}

bool Cone::hits(const RayTracer::Ray &ray, double &t) const
{
    Math::Vector3D localOrigin (
      ray.origin.X - apex.X,
      ray.origin.Y - apex.Y,
      ray.origin.Z - apex.Z
    );
    Math::Vector3D rotatedOrigin = rotation.applyInverseToVector(localOrigin);
    Math::Vector3D rotatedDir = rotation.applyInverseToVector(ray.direction);
    double k = radius / height;
    double ox = rotatedOrigin.X;
    double oy = rotatedOrigin.Y;
    double oz = rotatedOrigin.Z;

    double a = rotatedDir.X * rotatedDir.X + rotatedDir.Z * rotatedDir.Z - k*k * rotatedDir.Y * rotatedDir.Y;
    double b = 2 * (ox * rotatedDir.X + oz * rotatedDir.Z - k*k * oy * rotatedDir.Y);
    double c = ox*ox + oz*oz - k*k * oy*oy;

    double d = b*b - 4*a*c;
    if (d >= 0) {
        t = (-b - sqrt(d)) / (2*a);
        if (t < 0) return false;
        double hitY = rotatedOrigin.Y + t * rotatedDir.Y;
        if (hitY < -height || hitY > 0)
            return false;
        return true;
    }
    return false;
}

Math::Vector3D Cone::getColor() const
{
    return this->color;
}
