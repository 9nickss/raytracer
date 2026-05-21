/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     PointLight                                                                       *
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

#ifndef POINTLIGHT_HPP
    #define POINTLIGHT_HPP

#include "ILight.hpp"

class PointLight : public ILight
{
public:
    Math::Point3D position;
    double        intensity;
 
    PointLight(const Math::Point3D &pos, double i)
        : position(pos), intensity(i) {}
    ~PointLight() = default;
 
    bool castsShadow() const override { return true; }
 
            
    Math::Vector3D getShadowDirection() const override
    {
        return Math::Vector3D(0, 0, 0);
    }
 
    Math::Point3D getPosition() const { return position; }
 
    Math::Vector3D illuminate(const Math::Point3D &point,
        const Math::Vector3D &normal) const override;
};
 
#endif
