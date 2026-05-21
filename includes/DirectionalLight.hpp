/*
** EPITECH PROJECT, 2026
** DirectionalLight.hpp
** File description:
** DirectionalLight.hpp
*/

#ifndef DIRECTIONALLIGHT_HPP_
    #define DIRECTIONALLIGHT_HPP_

    #include "ILight.hpp"

    class DirectionalLight : public ILight {
        public:
            Math::Vector3D direction;
            double intensity;

            DirectionalLight(Math::Vector3D dir, double i): intensity(i)
            {
                double len = dir.length();
                direction = Math::Vector3D(dir.X / len, dir.Y / len, dir.Z / len);
            }

            ~DirectionalLight() = default;

            bool castsShadow() const override { return true; }
            Math::Vector3D getShadowDirection() const override { return direction; }
            Math::Vector3D illuminate(const Math::Point3D &point,
                const Math::Vector3D &normal) const override;
    };

#endif /* DIRECTIONALLIGHT_HPP_ */
