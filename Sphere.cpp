#include <iostream>
#include "Sphere.h"
#include <string>
#include <math.h>
  
    // Constructor for the Sphere, that implements the location (with x, y and z) and the radius.
    Sphere::Sphere(float x, float y, float z, float radius) : Object(x, y, z), radius(radius) {}

    // An equation to calculate the distance from a given Ray and the Sphere.
    float Sphere::distFromRay(Ray const &ray) const { return ray.support.sub(center).cross(ray.direction).norm(); }

    // Function to calculate the point where a Ray, intersects with the Sphere.
    void Sphere::hitPoint(Ray &ray)
    {
        // Check if the ray even hits the Sphere
        if (distFromRay(ray) <= radius)
        {
            // An equation with the "distFromRay" funtion to calculate the point where the Ray hits the Sphere
            // First use the pythagoras theorem to calculate the length from where the ray hits the Sphere to where it is closest to its center.
            float r2 = pow(radius, 2);
            float dr2 = pow(distFromRay(ray), 2);
            float afstand = sqrt(r2 + dr2);

            // Then calculate p (a point on the ray, that is closest to the Sphere its center)
            Vec3D p = ray.support.add(ray.direction.unit().mul(center.sub(ray.support).dot(ray.direction.unit())));
            // Now you can calculate the hitPoint with the distance, closest point and the direction vector, with this equation.
            Vec3D hitpoint = p.sub(ray.direction.unit().mul(afstand));

            std::cout << "P gegevens: " << p.x << " " << p.y << " " << p.z << "\n";
            std::cout << "This ray touches the sphere at: " << hitpoint.x << " " << hitpoint.y << " " << hitpoint.z << "\n";
        }
        else
            std::cout << "This ray doesn't touch the sphere\n";
    }

    bool Sphere::hit(Ray &ray, float midX, float XsquareSize, float YsquareSize)
    {
        if (distFromRay(ray) <= radius)
            return true;
        else
            return false;
    }

    std::string Sphere::getName() { return "Sphere"; }