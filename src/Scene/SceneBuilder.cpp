/*
** EPITECH PROJECT, 2026
** SceneBuilder.cpp
** File description:
** SceneBuilder.cpp
*/

#include "../../includes/SceneBuilder.hpp"

SceneBuilder::SceneBuilder(const std::string &filepath)
{
    _cfg.readFile(filepath.c_str());

}

void SceneBuilder::addPrimitives(Scene &scene, const std::string &path,
    const std::string &type)
{
    const libconfig::Setting &prims = _cfg.lookup(path);

    for (int i = 0; i < prims.getLength(); i++)
        scene.add(PrimitiveFactory::create(prims[i], type));
}

void SceneBuilder::addLights(Scene &scene, const std::string &path,
    const std::string &type)
{
    const libconfig::Setting &lights = _cfg.lookup(path);

    for (int i = 0; i < lights.getLength(); i++)
        scene.addLight(LightsFactory::create(lights[i], type));
}

Scene SceneBuilder::build()
{
    Scene scene;

    addPrimitives(scene, "primitives.spheres", "sphere");
    addPrimitives(scene, "primitives.planes", "plane");
    addPrimitives(scene, "primitives.cylinders", "cylinder");
    addPrimitives(scene, "primitives.cones", "cone");
    addPrimitives(scene, "primitives.limited_cylinders", "limited_cylinder");
    addPrimitives(scene, "primitives.limited_cones", "limited_cone");
    addLights(scene, "lights.ambient", "ambient");
    addLights(scene, "lights.directional", "directional");
    addLights(scene, "lights.point_lights", "point_light");
    addLights(scene, "lights.colored_lights", "colored_light");
    return scene;
}
