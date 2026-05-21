/*
** EPITECH PROJECT, 2026
** Math.hpp
** File description:
** Math.hpp
*/

#ifndef MATH_HPP_
    #define MATH_HPP_

    #include <math.h>

    namespace Math {

        class Vector3D {
            public:
                double X;
                double Y;
                double Z;
                Vector3D() : X(0), Y(0), Z(0) {}
                Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}
                ~Vector3D() = default;
                double dot(const Vector3D &other) const;
                double length() const;

                Vector3D operator*(double scalar) const;
                Vector3D operator+(const Vector3D &other);
                Vector3D operator*(const Vector3D &other) const;
                Vector3D operator-() const;
        };

        class Point3D {
            public:
                double X;
                double Y;
                double Z;
                Point3D(): X(0), Y(0), Z(0) {}
                Point3D(double x, double y, double z): X(x), Y(y), Z(z) {}
                ~Point3D() = default;

                Point3D operator+(const Vector3D &other) const;
                Vector3D operator-(const Point3D &other) const;
        };

        class Rectangle3D {
            public:
                Point3D origin;
                Vector3D bottom_side;
                Vector3D left_side;

                Rectangle3D(): origin(0, 0, 0), bottom_side(1, 0, 0),
                    left_side(0, 1, 0) {}
                Rectangle3D(const Point3D &org, const Vector3D &bt_sd,
                    const Vector3D &lt_sd): origin(org), bottom_side(bt_sd),
                    left_side(lt_sd) {}
                ~Rectangle3D() = default;

                Point3D pointAt(double u, double v);
        };

    } // namespace Math

#endif /* MATH_HPP_ */
