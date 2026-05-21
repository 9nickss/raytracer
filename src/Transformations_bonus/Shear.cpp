/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     Shear                                                                            *
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

#include "../../includes/Shear.hpp"

Math::Vector3D Shear::applyToVector(const Math::Vector3D &v) const
{
    return Math::Vector3D(
        v.X + xy * v.Y + xz * v.Z,
        yx * v.X + v.Y + yz * v.Z,
        zx * v.X + zy * v.Y + v.Z
    );
}
 
Math::Point3D Shear::applyToPoint(const Math::Point3D &p) const
{
    return Math::Point3D(
        p.X + xy * p.Y + xz * p.Z,
        yx * p.X + p.Y + yz * p.Z,
        zx * p.X + zy * p.Y + p.Z
    );
}
 
Math::Vector3D Shear::applyInverseToVector(const Math::Vector3D &v) const
{
    double x = v.X - xy * v.Y - xz * v.Z + xy * yz * v.Z;
    double y = v.Y - yx * v.X - yz * v.Z + yx * xz * v.Z;
    double z = v.Z - zx * v.X - zy * v.Y + zx * xy * v.Y;
    return Math::Vector3D(x, y, z);
}
 
Math::Point3D Shear::applyInverseToPoint(const Math::Point3D &p) const
{
    double x = p.X - xy * p.Y - xz * p.Z + xy * yz * p.Z;
    double y = p.Y - yx * p.X - yz * p.Z + yx * xz * p.Z;
    double z = p.Z - zx * p.X - zy * p.Y + zx * xy * p.Y;
    return Math::Point3D(x, y, z);
}
