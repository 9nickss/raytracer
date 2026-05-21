/*
** EPITECH PROJECT, 2026
** PrimitiveFactory.hpp
** File description:
** PrimitiveFactory.hpp
*/

#ifndef PRIMITIVEFACTORY_HPP_
    #define PRIMITIVEFACTORY_HPP_

    #include <libconfig.h++>
    #include "IPrimitive.hpp"
    #include "Sphere.hpp"
    #include "Plane.hpp"
    #include "Cylinder.hpp"
    #include "LimitedCylinder.hpp"
    #include "LimitedCone.hpp"
    #include "Cone.hpp"
    #include <memory>
    #include <string>

    class PrimitiveFactory {
    private:
        static Rotation getRotation(const libconfig::Setting &setting);
    public:
        static Math::Vector3D getColor(const libconfig::Setting &setting);
        static Math::Point3D getPoint(const libconfig::Setting &setting);
        static std::unique_ptr<IPrimitive> create(const libconfig::Setting &setting, const std::string &type);
        static Math::Vector3D getVector(const libconfig::Setting &setting);
    };

#endif /* PRIMITIVEFACTORY_HPP_ */
