/*
** EPITECH PROJECT, 2026
** Sphere.hpp
** File description:
** Sphere.hpp
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "IPrimitive.hpp"

    class Sphere : public IPrimitive {
        public:
            Math::Point3D center;
            double radius;
            Math::Vector3D color;

            Sphere(const Math::Point3D &c, double r, const Math::Vector3D &col);
            bool hits(const RayTracer::Ray &ray, double &t) const override;
            Math::Vector3D getNormal(const Math::Point3D &p) const override;
            Math::Vector3D getColor() const override;
    };

#endif /* SPHERE_HPP_ */
