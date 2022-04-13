#ifndef OBJECT_H
#define OBJECT_H
#pragma once

#include <string>
#include "Vec3D.h"

class Object
{
public:
    float x, y, z;
    float midX, XsquareSize, YsquareSize;
    Vec3D center = Vec3D(x, y, z);

    // Constructor for Object, that implements a x, y and z length.
    Object(float x, float y, float z);

    // Abstact function 'hit' that every child-class implements.
    virtual bool hit(class Ray &ray, float midX, float XsquareSize, float YsquareSize) = 0;

    virtual std::string getName() = 0;
};
#endif