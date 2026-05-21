/*
** EPITECH PROJECT, 2026
** LightsFactory.hpp
** File description:
** LightsFactory.hpp
*/

#ifndef LIGHTSFACTORY_HPP_
    #define LIGHTSFACTORY_HPP_

    #include <libconfig.h++>
    #include "AmbientLight.hpp"
    #include "DirectionalLight.hpp"
    #include "PointLight.hpp"
    #include "ColoredLight.hpp"
    #include "ILight.hpp"
    #include <memory>
    #include <string>
    #include "PrimitiveFactory.hpp"

    class LightsFactory {
        public:
            static std::unique_ptr<ILight> create(const libconfig::Setting &setting, const std::string &type);
    };

#endif /* LIGHTSFACTORY_HPP_ */
