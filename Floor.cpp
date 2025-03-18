#include "Floor.hpp"
#include <cmath>

/*
    Math used: https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-plane-and-ray-disk-intersection.html
*/

bool Floor::hit(Ray &ray) 
{
    Vec3D quadratic = hitPoint(static_cast<const Ray&> (ray));
    if(quadratic.x == 0) return false;

    float t = quadratic.y / quadratic.x;
    
    // if t is negative than the ray is behind the floor, we dont need this
    if(t < 0) return false;

    Vec3D intersection = ray.support.add(ray.direction.mul(t));
    
    return isWhiteTile(intersection);
}

Vec3D Floor::hitPoint(Ray const &ray) 
{
    float numerator = ray.support.sub(center).dot(center);    
    float denominator = ray.direction.dot(center);

    return Vec3D(denominator, numerator, 0.0f);
}

bool Floor::isWhiteTile(Vec3D p){
    float cellSize = 1.6;     
    int yAxis = static_cast<int>(p.y / cellSize);
    int zAxis = static_cast<int>(p.z / cellSize); 
    
    bool planeTile = (yAxis + zAxis) % 2 == 0;

    //debug:
        // std::cout << "Tile at (" << p.x << ", " << p.z << ") is: " << (planeTile ? "White" : "Black") << "\n";

    return (p.y > 0) ? !planeTile : planeTile;  //if the y is bigger than 0 its not a white tile but a black one
}
