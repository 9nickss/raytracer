/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     Scale                                                                            *
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

#ifndef SCALE_HPP
    #define SCALE_HPP

#include "Math.hpp"
 
class Scale
{
public:
    double sX;
    double sY;
    double sZ;
 
    Scale(double sx, double sy, double sz) : sX(sx), sY(sy), sZ(sz) {}
    Scale() : sX(1), sY(1), sZ(1) {}
    ~Scale() = default;
 
    Math::Vector3D applyToVector(const Math::Vector3D &v) const;
    Math::Point3D  applyToPoint(const Math::Point3D &p) const;
 
    Math::Vector3D applyInverseToVector(const Math::Vector3D &v) const;
    Math::Point3D  applyInverseToPoint(const Math::Point3D &p) const;
};
 
#endif
