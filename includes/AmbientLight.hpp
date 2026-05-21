/*
** EPITECH PROJECT, 2026
** AmbientLight.hpp
** File description:
** AmbientLight.hpp
*/

#ifndef AMBIENTLIGHT_HPP_
    #define AMBIENTLIGHT_HPP_

    #include "ILight.hpp"

    class AmbientLight : public ILight {
        public:
            double intensity;
            AmbientLight(double i): intensity(i)  {}
            bool castsShadow() const override { return false; }
            Math::Vector3D getShadowDirection() const override { return Math::Vector3D(0, 0, 0); }

            ~AmbientLight() = default;
            Math::Vector3D illuminate(const Math::Point3D &point,
                const Math::Vector3D &normal) const override;
    };

#endif /* AMBIENTLIGHT_HPP_ */
