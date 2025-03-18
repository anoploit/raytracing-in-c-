#pragma once
#include "Ray.hpp"
#include "Vec3D.hpp"
#include <iostream>

class Ray;

class Object
{
    friend class Ray;
    friend class RayScanner;
    protected:
        Vec3D center;

    public:
        Object(float x, float y, float z): center(x, y, z){}

        virtual bool hit(Ray &ray) = 0;
//Deze method test in derived classes of het betreffende object geraakt wordt door de straal en
//wat de support vector en de direction vector van de weerkaatste straal zijn.
};