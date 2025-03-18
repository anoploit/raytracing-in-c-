#include "Sphere.hpp"
#include <cmath>
namespace st = std;

bool Sphere::hit(Ray &ray) 
{
    Vec3D quadratic = hitPoint(ray);        //get the quadratic points back (a, b, c)
    float discriminant = quadratic.y* quadratic.y - 4 * quadratic.x * quadratic.z;      // float discriminant = b*b - 4 * a * c;

    //Intersection points of ray and sphere
    float t0; 
    float t1;

    if (discriminant < 0) return false;

    t0 = (-quadratic.y - sqrt(discriminant)) / (2.0f * quadratic.x); 
    t1 = (-quadratic.y + sqrt(discriminant)) / (2.0f * quadratic.x);

    // If both t0 and t1 are negative, the intersection is behind the ray's origin
    if (t0 > 0) 
    {
        // Choose the smaller positive t
        float t = (t1 > 0) ? st::min(t0, t1) : t0;     // a new check to see if t1 is also positive and then choose between the smallest of (t0 and t1)

        Vec3D intersect = ray.support.add(ray.direction.mul(t));
        // intersect.show("Intersect Sphere");
        return true;                
    }

    return false;           //handle case when there is an intersection but its smaller than 0, in this case the ray shoots from the inside and if t is smaller than it returns false
}
// All the math from here, note: I didnt use the whole formula 
// https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection.html

Vec3D Sphere::hitPoint(const Ray &ray) const
{
    Vec3D L = ray.support.sub(center);
    float a = ray.direction.dot(ray.direction);
    float b = 2.0f * ray.direction.dot(L);
    float c = L.dot(L) - radius * radius;

    return Vec3D(a, b, c);  // Return coefficients as a Vec3D
}