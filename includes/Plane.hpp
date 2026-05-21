/*
** EPITECH PROJECT, 2026
** Plane.hpp
** File description:
** Plane.hpp
*/

#ifndef PLANE_HPP_
    #define PLANE_HPP_

    #include "IPrimitive.hpp"
    #include "Rotation.hpp"

    class Plane : public IPrimitive {
        public:
            Math::Point3D point;
            Math::Vector3D normal;
            Math::Vector3D color;
            Rotation rotation;
        
            Plane(const Math::Point3D &p, const Math::Vector3D &n, const Math::Vector3D &c, const Rotation &rot);
            bool hits(const RayTracer::Ray &ray, double &t) const override;
            Math::Vector3D getNormal(const Math::Point3D &p) const override;
            Math::Vector3D getColor() const override;
    };

#endif /* PLANE_HPP_ */
