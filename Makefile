##
## EPITECH PROJECT
## Raytracer
## File description:
## Makefile
##

NAME		=	raytracer

CXX		=	clang++
CXXFLAGS	=	-std=c++17 -Wall -Wextra -Wshadow -O2
CXXFLAGS	+=	-Iincludes

SRC		=	src/Camera/Camera.cpp				\
			src/Math/Point3D.cpp				\
			src/Math/Rectangle3D.cpp			\
			src/Primitives/Sphere.cpp			\
			src/Math/Vector3D.cpp				\
			src/main.cpp						\
			src/Primitives/Plane.cpp			\
			src/Scene/Scene.cpp					\
			src/Scene/SceneBuilder.cpp			\
			src/Factory/PrimitiveFactory.cpp	\
			src/Factory/LightsFactory.cpp		\
			src/Lights/AmbientLight.cpp			\
			src/Lights/DirectionalLight.cpp		\
			src/Primitives/Cylinder.cpp			\
			src/Primitives/Cone.cpp				\
			src/Rotation/Rotation.cpp			\
			src/Light_bonus/ColoredLight.cpp	\
			src/Light_bonus/PointLight.cpp		\
			src/Primitives/LimitedCone.cpp		\
			src/Primitives/LimitedCylinder.cpp	\
			src/Transformations_bonus/Scale.cpp	\
			src/Transformations_bonus/Shear.cpp	\

LDFLAGS		=	-lconfig++

OBJ_DIR		=	build
OBJ		=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP		=	$(OBJ:.o=.d)

PLUGIN_DIR	=	plugins
PLUGINS		=	$(PLUGIN_DIR)/raytracer_sphere.so	\
			$(PLUGIN_DIR)/raytracer_plane.so	\
			$(PLUGIN_DIR)/raytracer_cylinder.so	\
			$(PLUGIN_DIR)/raytracer_cone.so

RESET		=	\033[0m
BOLD		=	\033[1m
GREEN		=	\033[32m
YELLOW		=	\033[33m
CYAN		=	\033[36m
RED		=	\033[31m

.PHONY: all re clean fclean plugins help

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CYAN)$(BOLD)Linking$(RESET) → $(NAME)"
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(GREEN)$(BOLD)Build OK$(RESET) — ./$(NAME)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling$(RESET) $<"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

plugins: $(PLUGINS)

$(PLUGIN_DIR)/%.so:
	@mkdir -p $(PLUGIN_DIR)
	@echo "$(YELLOW)Plugin$(RESET) $@  (stub — add real sources here)"

clean:
	@echo "$(RED)Cleaning$(RESET) objects..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing$(RESET) $(NAME)"
	@rm -f $(NAME)
	@rm -rf $(PLUGIN_DIR)

re: fclean all