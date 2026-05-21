/*
** EPITECH PROJECT, 2026
** ILight.hpp
** File description:
** ILight.hpp
*/

#ifndef ILIGHT_HPP_
    #define ILIGHT_HPP_

    #include "Raytracer.hpp"

    class ILight {
        public:
            virtual Math::Vector3D illuminate(const Math::Point3D &point,
                const Math::Vector3D &normal) const = 0;
            virtual bool castsShadow() const = 0;
            virtual Math::Vector3D getShadowDirection() const = 0;

            virtual ~ILight() = default;
    };

#endif /* ILIGHT_HPP_ */
