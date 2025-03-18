// #include "Floor.hpp"
// #include <cmath>

// bool Floor::hit(Ray &ray) 
// {
//     Vec3D intersect = hitPoint(static_cast<const Ray&> (ray));
    
//     return isWhiteTile(intersect);
// }

// /*
//     t = (plane point - ray origin) * normal / ray direction * normal
// */

// Vec3D Floor::hitPoint(Ray const &ray) 
// {

//     Vec3D directionUnit = ray.direction.unit(); //Get unit direction of ray
//     Vec3D raySubPlane = center.sub(ray.support);  //Difference between point of center and the ray
//     Vec3D normal = center.unit();  // For a flat plane, use the normalized vector of the center
//     float numerator = raySubPlane.dot(normal);  // The numerator of the formula (plane point - ray origin) * normal
//     float denominator = directionUnit.dot(normal);  // The denominator of the formula (ray direction * normal)

//         //If the denominator is 0, the ray is parallel to the plane
//     if (denominator == 0) {
//         return Vec3D(INFINITY, INFINITY, INFINITY);  // No intersection
//     }

//     auto t = numerator / denominator;  //The final step, the intersection between ray and plane if there is one
//     auto intersect = ray.support.add(ray.direction.mul(t)); //calculate where the intersection is (x,y,z) => t = ray origin + ray direction * t
    
//         // std::cout << "Intersection at: (" << intersect.x << ", " << intersect.y << ", " << intersect.z << ")\n";

//     return intersect;   //this is the vec3d of the intersection point
// }

// bool Floor::isWhiteTile(Vec3D p){
//     float cellSize = 0.6;     
//     int xAxis = static_cast<int>(p.x / cellSize);
//     int zAxis = static_cast<int>(p.z / cellSize); 
    
//     bool planeTile = (xAxis + zAxis) % 2 == 0;

//     //debug:
//         // std::cout << "Tile at (" << p.x << ", " << p.z << ") is: " << (planeTile ? "White" : "Black") << "\n";

//     return (p.y > 0) ? !planeTile : planeTile;  //if the y is bigger than 0 its not a white tile but a black one
// }
