/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     Scale                                                                            *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

 #include "../../includes/Scale.hpp"
 
Math::Vector3D Scale::applyToVector(const Math::Vector3D &v) const
{
    return Math::Vector3D(v.X * sX, v.Y * sY, v.Z * sZ);
}
 
Math::Point3D Scale::applyToPoint(const Math::Point3D &p) const
{
    return Math::Point3D(p.X * sX, p.Y * sY, p.Z * sZ);
}
 
Math::Vector3D Scale::applyInverseToVector(const Math::Vector3D &v) const
{
    return Math::Vector3D(
        sX != 0 ? v.X / sX : 0,
        sY != 0 ? v.Y / sY : 0,
        sZ != 0 ? v.Z / sZ : 0
    );
}
 
Math::Point3D Scale::applyInverseToPoint(const Math::Point3D &p) const
{
    return Math::Point3D(
        sX != 0 ? p.X / sX : 0,
        sY != 0 ? p.Y / sY : 0,
        sZ != 0 ? p.Z / sZ : 0
    );
}
