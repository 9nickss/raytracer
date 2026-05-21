/*
** EPITECH PROJECT, 2026
** SceneBuilder.hpp
** File description:
** SceneBuilder.hpp
*/

#ifndef SCENEBUILDER_HPP_
    #define SCENEBUILDER_HPP_

    #include <libconfig.h++>
    #include "Scene.hpp"
    #include "PrimitiveFactory.hpp"
    #include "LightsFactory.hpp"

    class SceneBuilder {
        private:
            libconfig::Config _cfg;
            void addPrimitives(Scene &scene, const std::string &path,
                const std::string &type);
            void addLights(Scene &scene, const std::string &path,
                const std::string &type);
        public:
            SceneBuilder(const std::string &filepath);
            ~SceneBuilder() = default;

            Scene build();
    };

#endif /* SCENEBUILDER_HPP_ */
