/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     ColoredLight                                                                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "../../includes/ColoredLight.hpp"
#include <algorithm>
 
Math::Vector3D ColoredLight::illuminate(const Math::Point3D &point,
    const Math::Vector3D &normal) const
{
    (void)point;
 
    Math::Vector3D toLight(
        -direction.X,
        -direction.Y,
        -direction.Z
    );

    double diff = std::max(0.0, normal.dot(toLight));
    double value = diff * intensity;
 
    return Math::Vector3D(
        value * color.X,
        value * color.Y,
        value * color.Z
    );
}
