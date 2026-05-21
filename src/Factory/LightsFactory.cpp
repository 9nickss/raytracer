/*
** EPITECH PROJECT, 2026
** LightsFactory.cpp
** File description:
** LightsFactory.cpp
*/

#include "../../includes/LightsFactory.hpp"

std::unique_ptr<ILight> LightsFactory::create(const libconfig::Setting &setting,
    const std::string &type)
{
    if (type == "ambient") {
        return std::make_unique<AmbientLight>(
            (double)setting["intensity"]
        );
    }
    if (type == "directional") {
        return std::make_unique<DirectionalLight>(
            PrimitiveFactory::getVector(setting["direction"]),
            (double)setting["intensity"]
        );
    }
    if (type == "point_light") {
        return std::make_unique<PointLight>(
            PrimitiveFactory::getPoint(setting["position"]),
            (double)setting["intensity"]
        );
    }
    if (type == "colored_light") {
        return std::make_unique<ColoredLight>(
            PrimitiveFactory::getVector(setting["direction"]),
            PrimitiveFactory::getColor(setting["color"]),
            (double)setting["intensity"]
        );
    }
    return nullptr;
}
