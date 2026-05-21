/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     ColoredLight                                                                     *
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

#ifndef COLOREDLIGHT_HPP
    #define COLOREDLIGHT_HPP

#include "ILight.hpp"

class ColoredLight : public ILight 
{
public:
    Math::Vector3D direction;
    Math::Vector3D color;
    double intensity;
 
    ColoredLight(const Math::Vector3D &dir, const Math::Vector3D &col, double i)
        : color(col), intensity(i)
    {
        double len = dir.length();
        direction = len > 1e-6
            ? Math::Vector3D(dir.X / len, dir.Y / len, dir.Z / len)
            : Math::Vector3D(0, -1, 0);
    }
        ~ColoredLight() = default;
 
        bool castsShadow() const override { return true; }
        Math::Vector3D getShadowDirection() const override { return direction; }
 
        Math::Vector3D illuminate(const Math::Point3D &point,
        const Math::Vector3D &normal) const override;
};
 
#endif
