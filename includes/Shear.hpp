/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     Shear                                                                            *
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

#ifndef SHEAR_HPP
    #define SHEAR_HPP

#include "Math.hpp"

class Shear
{
public:
    double xy, xz;
    double yx, yz;
    double zx, zy;
 
    Shear(double xy, double xz,
        double yx, double yz,
        double zx, double zy)
        : xy(xy), xz(xz),
        yx(yx), yz(yz),
        zx(zx), zy(zy) {}
    Shear() : xy(0), xz(0), yx(0), yz(0), zx(0), zy(0) {}
    ~Shear() = default;
 
    Math::Vector3D applyToVector(const Math::Vector3D &v) const;
    Math::Point3D  applyToPoint(const Math::Point3D &p) const;
 
    Math::Vector3D applyInverseToVector(const Math::Vector3D &v) const;
    Math::Point3D  applyInverseToPoint(const Math::Point3D &p) const;
};
 
#endif
