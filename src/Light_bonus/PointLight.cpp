/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     PointLight                                                                       *
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

#include "../../includes/PointLight.hpp"
#include <algorithm>
#include <cmath>

Math::Vector3D PointLight::illuminate(const Math::Point3D &point,
    const Math::Vector3D &normal) const
{
    Math::Vector3D toLight(
        position.X - point.X,
        position.Y - point.Y,
        position.Z - point.Z
    );

    double dist = toLight.length();
    if (dist < 1e-6)
        return Math::Vector3D(0, 0, 0);
 
    Math::Vector3D dir(toLight.X / dist, toLight.Y / dist, toLight.Z / dist);
 
    double diff = std::max(0.0, normal.dot(dir));
 
    double attenuation = intensity / (1.0 + 0.1 * dist + 0.01 * dist * dist);
    double value = diff * attenuation;
 
    return Math::Vector3D(value, value, value);
}
