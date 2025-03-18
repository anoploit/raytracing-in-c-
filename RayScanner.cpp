#include "RayScanner.hpp"
#include <iostream>  // Needed for cout
#include <cmath>

namespace st = std;

RayScanner::RayScanner()
{
        // objects.push_back(new Sphere(0.7f, -1.0f, 2.0f, 0.45f)); //new Sphere
        objects.push_back( new Sphere(1, 0, 2, 0.45) );
        objects.push_back( new Sphere(0.4, 0.9, 0, 0.35) );
        objects.push_back( new Sphere(0.5, -1.5, 1, 0.35) );
        objects.push_back(new Floor(2.0f, 0.0f, 0.0f));     //new floor     

}

/*
    References of projection from 3d to 2d:
        https://www.youtube.com/watch?v=eoXn6nwV694
*/

void RayScanner::scan(){
    int imageHeight = 100;
    int imageWidth = 160;

    float height = imageHeight / 2;
    float width = imageWidth / 2;

    // Define a field of view (in radians)
    float fov = 90.0f;
    float aspectRatio = (float)imageWidth / (float)imageHeight;  // Screen aspect ratio
    float fovRad = fov * (M_PI / 180.0f);  // Convert degrees to radians
  
    // Scaling factor for screen pixels
    float scaleX = tan(fovRad / 2.0f) * aspectRatio;
    float scaleY = tan(fovRad / 2.0f);

    // Scan the screen
    // Made the i loop from positive till negative or else i get a flipped output
    for (float i = height; i >= -height; i--) {
        for (float j = -width; j <= width; j++) {

            // Correcting the world coordinates based on pixel location
            float worldX = (j / width) * scaleX;  // Adjusting x based on width scaling
            float worldY = (i / height) * scaleY; // Adjusting y based on height scaling

            // Create a new ray based on these world coordinates
            Ray ray(worldY, worldX, objects);  // Ensure the Ray constructor is correctly defined
            if (ray.scan()) {
                // Check if the hit object is a floor
                if (ray.hitObject() && dynamic_cast<Floor*>(ray.hitObject())) {
                    // Print "FF" for floor intersections
                    st::cout << "FF";
                } else {
                    // Print "MM" for other object intersections
                    st::cout << "MM";
                }
            } else {
                // Print a space for non-intersected pixels (no hit)
                st::cout << "  ";  
            }
        }
        st::cout << "\n";
    }
}