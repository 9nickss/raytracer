/*
** EPITECH PROJECT, 2026
** Scene.cpp
** File description:
** Scene.cpp
*/

#include "../../includes/Scene.hpp"
#include <limits>

void Scene::add(std::unique_ptr<IPrimitive> primitive)
{
    primitives.push_back(std::move(primitive));
}

void Scene::addLight(std::unique_ptr<ILight> light)
{
    lights.push_back(std::move(light));
}

Math::Vector3D Scene::getColor(const Math::Point3D &point, const Math::Vector3D &normal,
    IPrimitive &hit_primitive)
{
    Math::Vector3D color = hit_primitive.getColor();
    Math::Vector3D light(0, 0, 0);

    for (const auto &l : lights) {
        if (l->castsShadow()) {
            Math::Point3D shadowOrigin = point + (normal * 1e-4);
            Math::Vector3D shadowDir = -(l->getShadowDirection());
            RayTracer::Ray shadowRay(shadowOrigin, shadowDir);
            double tmp = 0;
            IPrimitive* blocked = nullptr;
            if (hits(shadowRay, tmp, blocked))
                continue;
        }
        light = light + l->illuminate(point, normal);
    }
    return color * light;
}

bool Scene::hits(const RayTracer::Ray &ray, double &t, IPrimitive* &hit_primitive) const
{
    double closest_t = std::numeric_limits<double>::max();
    bool has_hit = false;

    for (auto &prim : primitives) {
        if (prim->hits(ray, t) && t < closest_t) {
            has_hit = true;
            closest_t = t;
            hit_primitive = prim.get();
        }
    }
    t = closest_t;
    return has_hit;
}
