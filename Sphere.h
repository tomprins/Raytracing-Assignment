#ifndef SPHERE_H
#define SPHERE_H
#pragma once

#include "Object.h"
#include "Ray.h"

class Sphere : public Object
{
public:
    float radius;

    // Constructor for the Sphere, that implements the location (with x, y and z) and the radius.
    Sphere(float x, float y, float z, float radius);

    // An equation to calculate the distance from a given Ray and the Sphere.
    float distFromRay(Ray const &ray) const;

    // Function to calculate the point where a Ray, intersects with the Sphere.
    void hitPoint(Ray &ray);

    bool hit(Ray &ray, float midX, float XsquareSize, float YsquareSize);

    std::string getName();
};

#endif