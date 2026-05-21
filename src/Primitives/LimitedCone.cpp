/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     LimitedCone                                                                      *
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

#include "../../includes/LimitedCone.hpp"
#include <initializer_list>
 
LimitedCone::LimitedCone(const Math::Point3D &a, double r, double h,
    const Math::Vector3D &col, const Rotation &rot)
    : apex(a), radius(r), height(h), color(col), rotation(rot) {}
 
bool LimitedCone::hits(const RayTracer::Ray &ray, double &t) const
{
    Math::Vector3D localOrigin(
        ray.origin.X - apex.X,
        ray.origin.Y - apex.Y,
        ray.origin.Z - apex.Z
    );
    Math::Vector3D rotOrigin = rotation.applyInverseToVector(localOrigin);
    Math::Vector3D rotDir    = rotation.applyInverseToVector(ray.direction);
 
    double k  = radius / height;
    double k2 = k * k;
 
    double ox = rotOrigin.X, oy = rotOrigin.Y, oz = rotOrigin.Z;
    double dx = rotDir.X,    dy = rotDir.Y,    dz = rotDir.Z;
 
    double a = dx*dx + dz*dz - k2 * dy*dy;
    double b = 2.0 * (ox*dx + oz*dz - k2 * oy*dy);
    double c = ox*ox + oz*oz - k2 * oy*oy;
 
    double d = b*b - 4.0*a*c;
    if (d < 0)
        return false;
 
    double sqrtD = std::sqrt(d);
    double t0 = (-b - sqrtD) / (2.0 * a);
    double t1 = (-b + sqrtD) / (2.0 * a);
 
    for (double candidate : {t0, t1}) {
        if (candidate < 1e-4)
            continue;
        double hitY = oy + candidate * dy;
        if (hitY >= -height && hitY <= 0) {
            t = candidate;
            return true;
        }
    }
    return false;
}
 
Math::Vector3D LimitedCone::getNormal(const Math::Point3D &p) const
{
    Math::Vector3D localP(
        p.X - apex.X,
        p.Y - apex.Y,
        p.Z - apex.Z
    );
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
 
Math::Vector3D LimitedCone::getColor() const
{
    return color;
}
