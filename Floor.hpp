#pragma once
#include "Object.hpp"
#include "Vec3D.hpp"


class Floor : public Object 
{

public:
    Floor(float x, float y, float z) : Object(x, y, z) {
        center = Vec3D{x, y, z};
    }
    bool hit(Ray &ray) override;
    Vec3D hitPoint (Ray const &ray);
    bool isWhiteTile(Vec3D p);

};