/*
** EPITECH PROJECT, 2026
** Scene.hpp
** File description:
** Scene.hpp
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include "IPrimitive.hpp"
    #include "ILight.hpp"
    #include <memory>
    #include <vector>

    class Scene {
        public:
            std::vector<std::unique_ptr<IPrimitive>> primitives;
            std::vector<std::unique_ptr<ILight>> lights;

            void add(std::unique_ptr<IPrimitive> primitive);
            void addLight(std::unique_ptr<ILight> light);
            Math::Vector3D getColor(const Math::Point3D &point, const Math::Vector3D &normal,
                IPrimitive &hit_primitive);
            bool hits(const RayTracer::Ray &ray, double &t, IPrimitive* &hit_primitive) const;
    };

#endif /* SCENE_HPP_ */
