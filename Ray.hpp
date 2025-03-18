#pragma once

#include "Vec3D.hpp"
#include <iostream>
#include <vector>
#include "Object.hpp"

namespace st = std;

class Object;

class Ray
{
    friend class Sphere;
    friend class Object;
    friend class Floor;
    friend class RayScanner;
private:
    Vec3D support, direction;
    st::vector<Object*> VPO;
    Object* hitObj; 

public:
    Ray(float xStart, float yStart, st::vector<Object*> &objects);
    bool scan();
    Object* hitObject();
};


