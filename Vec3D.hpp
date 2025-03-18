#pragma once

#include <iostream>
#include <stdexcept>  // For invalid_argument
namespace st = std;


class Vec3D
{
public:
    float x, y, z;

    Vec3D(float x, float y, float z) // Constructor declaration
    : x(x), y(y), z(z) {}

    void show(st::string label);
    void show(st::string label, float scalar);
    void show();

    Vec3D minus();
    Vec3D add(Vec3D const &other) const;
    Vec3D sub(Vec3D const &other) const;
    Vec3D mul(float scalar) const;
    Vec3D div(float scalar);
    float norm() const;
    Vec3D unit() const;
    float dot(Vec3D const &other) const;
    Vec3D cross(Vec3D const &other) const;
};
