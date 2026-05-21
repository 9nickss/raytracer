/*
** EPITECH PROJECT, 2026
** PrimitiveFactory.cpp
** File description:
** PrimitiveFactory.cpp
*/

#include "../../includes/PrimitiveFactory.hpp"

Math::Vector3D PrimitiveFactory::getColor(const libconfig::Setting &setting)
{
    double r = setting["r"];
    double g = setting["g"];
    double b = setting["b"];
    return Math::Vector3D(r, g, b);
}

Math::Point3D PrimitiveFactory::getPoint(const libconfig::Setting &setting)
{
    double x = setting["x"];
    double y = setting["y"];
    double z = setting["z"];
    return Math::Point3D(x, y, z);
}

Math::Vector3D PrimitiveFactory::getVector(const libconfig::Setting &setting)
{
    double x = setting["x"];
    double y = setting["y"];
    double z = setting["z"];
    return Math::Vector3D(x, y, z);
}

Rotation PrimitiveFactory::getRotation(const libconfig::Setting &setting)
{
    double x = setting["x"];
    double y = setting["y"];
    double z = setting["z"];
    return Rotation(x, y ,z);
}

std::unique_ptr<IPrimitive> PrimitiveFactory::create(const libconfig::Setting &setting, const std::string &type)
{
    if (type == "sphere") {
        return std::make_unique<Sphere>(
            getPoint(setting["center"]),
            (double)setting["radius"],
            getColor(setting["color"])  
        );
    }

    if (type == "plane") {
        Rotation rot(0, 0, 0);
        if (setting.exists("rotation"))
            rot = getRotation(setting["rotation"]);
        return std::make_unique<Plane>(
            getPoint(setting["point"]),
            getVector(setting["normal"]),
            getColor(setting["color"]),
            rot
        );
    }

    if (type == "cylinder") {
        Rotation rot(0, 0, 0);
        if (setting.exists("rotation"))
            rot = getRotation(setting["rotation"]);
        return std::make_unique<Cylinder>(
            getPoint(setting["center"]),
            (double)setting["radius"],
            getColor(setting["color"]),
            rot
        );
    }

    if (type == "cone") {
        Rotation rot(0, 0, 0);
        if (setting.exists("rotation"))
            rot = getRotation(setting["rotation"]);
        return std::make_unique<Cone>(
            (double)setting["height"],
            (double)setting["radius"],
            getPoint(setting["apex"]),
            getColor(setting["color"]),
            rot
        );
    }

    if (type == "limited_cylinder") {
        Rotation rot(0, 0, 0);
        if (setting.exists("rotation"))
            rot = getRotation(setting["rotation"]);
        return std::make_unique<LimitedCylinder>(
            getPoint(setting["center"]),
            (double)setting["radius"],
            (double)setting["height"],
            getColor(setting["color"]),
            rot
        );
    }

    if (type == "limited_cone") {
        Rotation rot(0, 0, 0);
        if (setting.exists("rotation"))
            rot = getRotation(setting["rotation"]);
        return std::make_unique<LimitedCone>(
            getPoint(setting["apex"]),
            (double)setting["radius"],
            (double)setting["height"],
            getColor(setting["color"]),
            rot
        );
    }

    return nullptr;
}
