/*
** EPITECH PROJECT, 2026
** Cylinder.hpp
** File description:
** Cylinder.hpp
*/

#ifndef CYLINDER_HPP_
    #define CYLINDER_HPP_

    #include "IPrimitive.hpp"
    #include "Rotation.hpp"

    class Cylinder : public IPrimitive {
        public:
            Math::Point3D center;
            double radius;
            Math::Vector3D color;
            Rotation rotation;

            Cylinder(const Math::Point3D &c, double r, const Math::Vector3D &col, const Rotation &rot);
            bool hits(const RayTracer::Ray &ray, double &t) const override;
            Math::Vector3D getNormal(const Math::Point3D &p) const override;
            Math::Vector3D getColor() const override;
    };

#endif /* CYLINDER_HPP_ */
