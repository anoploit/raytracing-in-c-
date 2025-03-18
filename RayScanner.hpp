#pragma once
#include "Object.hpp"
#include "Floor.hpp"
#include "Sphere.hpp"
#include <vector>

class RayScanner
{        
    public:
        RayScanner();
        void scan();
        std::vector<Object*> objects;
};
