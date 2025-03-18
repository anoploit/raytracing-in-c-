# Ray Tracing Simulation

## Overview
This project implements a basic ray tracing simulation using C++. It includes functionality to cast rays in a 3D scene, detect intersections with objects such as spheres and a floor, and render a simple 2D projection of the scene.

## Features
- **Ray Casting:** Computes intersections of rays with objects in a scene.
- **Object Intersections:** Supports sphere and floor intersection calculations.
- **Rendering:** Converts 3D object hits into a 2D ASCII representation.
- **Mathematical Accuracy:** Uses vector algebra and quadratic solutions for intersection calculations.
- **Modular Codebase:** Organized into separate classes for Ray, Floor, Sphere, Vec3D, and RayScanner.

## Project Structure
```
├── Floor.hpp / Floor.cpp      # Floor representation and intersection logic
├── Ray.hpp / Ray.cpp          # Ray representation and hit detection logic
├── RayScanner.hpp / .cpp      # Scene scanning and rendering logic
├── Sphere.hpp / Sphere.cpp    # Sphere representation and intersection logic
├── Vec3D.hpp / Vec3D.cpp      # 3D Vector operations (addition, subtraction, dot product, cross product)
├── main.cpp                   # Entry point of the program
```

## Dependencies
- C++17 or later
- Standard C++ libraries (cmath, iostream, vector)

## Compilation
Use a C++ compiler such as `g++` to compile the project:
```sh
 g++ -o ray_tracer main.cpp Ray.cpp Floor.cpp Sphere.cpp RayScanner.cpp Vec3D.cpp -std=c++17
```

## Usage
Run the compiled executable:
```sh
 ./ray_tracer.exe
```
The program outputs an ASCII visualization of the ray-traced scene.

## References
- **Ray-Plane Intersection**: [Scratchapixel](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-plane-and-ray-disk-intersection.html)
- **Ray-Sphere Intersection**: [Scratchapixel](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection.html)
- **3D to 2D Projection**: [YouTube Video](https://www.youtube.com/watch?v=eoXn6nwV694)

## Author
Coded by **anoploit**

## License
This project is licensed under the MIT License.

