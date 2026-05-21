/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     LimitedCylinder                                                                  *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "../../includes/LimitedCylinder.hpp"
#include <initializer_list>
 
LimitedCylinder::LimitedCylinder(const Math::Point3D &c, double r, double h,
    const Math::Vector3D &col, const Rotation &rot)
    : center(c), radius(r), height(h), color(col), rotation(rot) {}
 
bool LimitedCylinder::hits(const RayTracer::Ray &ray, double &t) const
{
    Math::Vector3D localOrigin(
        ray.origin.X - center.X,
        ray.origin.Y - center.Y,
        ray.origin.Z - center.Z
    );
    Math::Vector3D rotOrigin = rotation.applyInverseToVector(localOrigin);
    Math::Vector3D rotDir    = rotation.applyInverseToVector(ray.direction);
 
    double a = rotDir.X * rotDir.X + rotDir.Z * rotDir.Z;
    double b = 2.0 * (rotOrigin.X * rotDir.X + rotOrigin.Z * rotDir.Z);
    double c = rotOrigin.X * rotOrigin.X + rotOrigin.Z * rotOrigin.Z - radius * radius;
    double d = b * b - 4.0 * a * c;
 
    if (d < 0)
        return false;
 
    double sqrtD = std::sqrt(d);
    double t0 = (-b - sqrtD) / (2.0 * a);
    double t1 = (-b + sqrtD) / (2.0 * a);
     double half = height / 2.0;
 
    for (double candidate : {t0, t1}) {
        if (candidate < 1e-4)
            continue;
        double hitY = rotOrigin.Y + candidate * rotDir.Y;
        if (hitY >= -half && hitY <= half) {
            t = candidate;
            return true;
        }
    }
    return false;
}
 
Math::Vector3D LimitedCylinder::getNormal(const Math::Point3D &p) const
{
    Math::Vector3D localP(
        p.X - center.X,
        p.Y - center.Y,
        p.Z - center.Z
    );
    localP = rotation.applyInverseToVector(localP);
 
    Math::Vector3D n(localP.X, 0, localP.Z);
    n = rotation.applyToVector(n);
 
    double len = n.length();
    return Math::Vector3D(n.X / len, n.Y / len, n.Z / len);
}
 
Math::Vector3D LimitedCylinder::getColor() const
{
    return color;
}
