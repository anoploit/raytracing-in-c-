#pragma once
#include "Object.hpp"
#include "Vec3D.hpp"

class Sphere : public Object 
{

private:
    float radius;

public:
    Sphere(float x, float y, float z, float radius) : Object(x, y, z), radius(radius){}
    bool hit(Ray &ray) override;
    Vec3D hitPoint (Ray const &ray) const;

};
