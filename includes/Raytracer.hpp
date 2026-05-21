/*
** EPITECH PROJECT, 2026
** RayTracer.hpp
** File description:
** RayTracer.hpp
*/

#ifndef RAYTRACER_HPP_
    #define RAYTRACER_HPP_

    #include "Math.hpp"

    namespace RayTracer {

        class Ray {
            public:
                Math::Point3D origin;
                Math::Vector3D direction;
                Ray(): origin(0, 0, 0), direction(0, 0, 0) {}
                Ray(const Math::Point3D &org, const Math::Vector3D &dir): origin(org),
                    direction(dir) {}
                ~Ray() = default;
        };

        class Camera {
            public:
                Math::Point3D origin;
                Math::Rectangle3D screen;

                Camera(): origin(0, 0, 0), screen(
                    Math::Point3D(-1, -1, -1),
                    Math::Vector3D(2, 0, 0),
                    Math::Vector3D(0, 2, 0)
                ) {}
                Camera(const Math::Point3D &org, const Math::Rectangle3D &scr):
                    origin(org), screen(scr) {}
                ~Camera() = default;

                Ray ray(double u, double v);
        };

    } // namespace RayTracer

#endif /* RAYTRACER_HPP_ */
