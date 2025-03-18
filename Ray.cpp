#include "Vec3D.hpp"
#include "Ray.hpp"
#include <iostream> 

namespace st = std;

    Ray::Ray(float xStart, float yStart, st::vector<Object*> &objects) : 
            support(Vec3D(0.0f, 0.0f, -3.0f)),
            direction(Vec3D(xStart, yStart, 0.0f).sub(support).unit()),
            VPO(objects)
    {
        //For debug
    // std::cout << "Ray starting at (" << support.x << ", " << support.y << ", " << support.z << ")\n";
    // std::cout << "Ray direction: (" << direction.x << ", " << direction.y << ", " << direction.z << ")\n";

    }

    bool Ray::scan(){
        for(auto &vpo : VPO){
            if (vpo -> hit(*this)){
                hitObj = vpo;
                return true;
            }
        }
        return false;
    }    

    Object* Ray::hitObject(){
        return hitObj;
    }