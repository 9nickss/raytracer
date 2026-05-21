/*
** EPITECH PROJECT, 2026
** main.cpp
** File description:
** main.cpp
*/

#include "../includes/Raytracer.hpp"
#include "../includes/Config.hpp"
#include "../includes/Scene.hpp"
#include "../includes/SceneBuilder.hpp"

void write_color(const Math::Vector3D &color)
{
    auto toByte = [](double c) -> int {
        c *= 255.0;
        int v = static_cast<int>(std::round(c));
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        return v;
    };
    std::cout << toByte(color.X) << " " << toByte(color.Y) << " " << toByte(color.Z) << "\n";
}

int main(int ac, char **av)
{
    RayTracer::Camera cam;
    (void)ac;
    Scene scene = SceneBuilder(av[1]).build();

    std::cout << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n" << std::endl;
    for (int y = HEIGHT - 1; y >= 0; y--) {
        for (int x = WIDTH - 1; x >= 0; x--) {
            double u = (double)x / WIDTH;
            double v = (double)y / HEIGHT;
            RayTracer::Ray r = cam.ray(u, v);
            double t = 0;
            IPrimitive* hit_prim = nullptr;
            if (scene.hits(r, t, hit_prim)) {
                Math::Point3D intersect = r.origin + (r.direction * t);
                Math::Vector3D normal = hit_prim->getNormal(intersect);
                Math::Vector3D color = scene.getColor(intersect, normal, *hit_prim);
                write_color(color);
            } else {
                write_color(Math::Vector3D(0, 0, 0));
            }
        }
    }
}
