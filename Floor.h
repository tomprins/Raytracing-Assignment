#ifndef FLOOR_H
#define FLOOR_H
#pragma once

#include "Object.h"
#include "Ray.h"

class Floor : public Object
{
public:
    Floor(float x, float y, float z);

    bool hit(Ray &ray, float midX, float XsquareSize, float YsquareSize);

    std::string getName();
};
#endif