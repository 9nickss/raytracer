/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, May, 2026                                                     *
 * Title           - G-OOP-400-NCE-4-1-raytracer-9                                      *
 * Description     -                                                                    *
 *     Rotation                                                                         *
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

#ifndef ROTATION_HPP
    #define ROTATION_HPP

#include "Math.hpp"

class Rotation
{
public:
    double angleX;
    double angleY;
    double angleZ;

    Rotation(double ax, double ay, double az)
        : angleX(ax), angleY(ay), angleZ(az) {}
    ~Rotation() = default;

    Math::Vector3D applyToVector(const Math::Vector3D &v) const;
    Math::Point3D applyToPoint(const Math::Point3D &p) const;

    Math::Vector3D applyInverseToVector(const Math::Vector3D &v) const;
    Math::Point3D applyInverseToPoint(const Math::Point3D &p) const;
};

#endif
