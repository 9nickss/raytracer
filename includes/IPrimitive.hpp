/*
** EPITECH PROJECT, 2026
** IPrimitive.hpp
** File description:
** IPrimitive.hpp
*/

#ifndef IPRIMITIVE_HPP_
    #define IPRIMITIVE_HPP_

    #include "Raytracer.hpp"

    class IPrimitive {
        public:
            virtual bool hits(const RayTracer::Ray &ray, double &t) const = 0;
            virtual Math::Vector3D getNormal(const Math::Point3D &p) const = 0;
            virtual Math::Vector3D getColor() const = 0;
            virtual ~IPrimitive() = default;
    };

#endif /* IPRIMITIVE_HPP_ */
