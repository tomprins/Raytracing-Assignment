#ifndef RAY_H
#define RAY_H
#pragma once

#include "Vec3D.h"
#include <string>
#include <vector>

class Ray
{
public:
    //VPO objects;
    Vec3D support;
    Vec3D scherm;
    Vec3D direction;

    // Constructor for the Ray, support is here the point from where the rays are sent, in scherm are coordinates stored, where it intersects the screen where the image is printed from.
    // direction is the direction that the ray takes from the support, this is calculated with scherm and support.
    Ray(float xStart, float yStart);
};

#endif