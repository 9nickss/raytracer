/*
** EPITECH PROJECT, 2026
** Cone.hpp
** File description:
** Cone.hpp
*/

#ifndef CONE_HPP_
    #define CONE_HPP_

    #include "IPrimitive.hpp"
    #include "Rotation.hpp"

    class Cone : public IPrimitive {
        public:
            double height;
            double radius;
            Math::Point3D apex;
            Math::Vector3D color;
            Rotation rotation;

            Cone(double h, double r, const Math::Point3D &a, const Math::Vector3D &c, const Rotation &rot);
            bool hits(const RayTracer::Ray &ray, double &t) const override;
            Math::Vector3D getNormal(const Math::Point3D &p) const override;
            Math::Vector3D getColor() const override;
    };

#endif /* CONE_HPP_ */
