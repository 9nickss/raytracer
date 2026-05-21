/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     Rotation                                                                         *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "../../includes/Rotation.hpp"

static double toRad(double deg)
{
    return deg * M_PI / 180.0;
}

static Math::Vector3D rotateX(const Math::Vector3D &v, double rad)
{
    double c = std::cos(rad);
    double s = std::sin(rad);
    return Math::Vector3D(
        v.X,
        v.Y * c - v.Z * s,
        v.Y * s + v.Z * c
    );
}

static Math::Vector3D rotateY(const Math::Vector3D &v, double rad)
{
    double c = std::cos(rad);
    double s = std::sin(rad);
    return Math::Vector3D(
        v.X * c + v.Z * s,
        v.Y,
        -v.X * s + v.Z * c
    );
}

static Math::Vector3D rotateZ(const Math::Vector3D &v, double rad)
{
    double c = std::cos(rad);
    double s = std::sin(rad);
    return Math::Vector3D(
        v.X * c - v.Y * s,
        v.X * s + v.Y * c,
        v.Z
    );
}

Math::Vector3D Rotation::applyToVector(const Math::Vector3D &v) const
{
    Math::Vector3D r = rotateX(v, toRad(angleX));
    r = rotateY(r, toRad(angleY));
    r = rotateZ(r, toRad(angleZ));
    return r;
}

Math::Point3D Rotation::applyToPoint(const Math::Point3D &p) const
{
    Math::Vector3D v(p.X, p.Y, p.Z);
    Math::Vector3D r = applyToVector(v);
    return Math::Point3D(r.X, r.Y, r.Z);
}

Math::Vector3D Rotation::applyInverseToVector(const Math::Vector3D &v) const
{
    Math::Vector3D r = rotateZ(v, toRad(-angleZ));
    r = rotateY(r, toRad(-angleY));
    r = rotateX(r, toRad(-angleX));
    return r;
}

Math::Point3D Rotation::applyInverseToPoint(const Math::Point3D &p) const
{
    Math::Vector3D v(p.X, p.Y, p.Z);
    Math::Vector3D r = applyInverseToVector(v);
    return Math::Point3D(r.X, r.Y, r.Z);
}
