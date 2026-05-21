/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     LimitedCylinder                                                                  *
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

#ifndef LIMITEDCYLINDER_HPP
    #define LIMITEDCYLINDER_HPP

#include "IPrimitive.hpp"
    #include "Rotation.hpp"
 
class LimitedCylinder : public IPrimitive 
{
public:
    Math::Point3D center;
    double radius;
    double height;
    Math::Vector3D color;
    Rotation rotation;
 
    LimitedCylinder(const Math::Point3D &c, double r, double h,
        const Math::Vector3D &col, const Rotation &rot);
    bool hits(const RayTracer::Ray &ray, double &t) const override;
    Math::Vector3D getNormal(const Math::Point3D &p) const override;
    Math::Vector3D getColor() const override;
};
 
#endif
