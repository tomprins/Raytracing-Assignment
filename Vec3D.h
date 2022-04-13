#ifndef VEC3D_H
#define VEC3D_H
#pragma once

class Vec3D
{
public:
    float x;
    float y;
    float z;

    Vec3D(float x, float y, float z);

    Vec3D();

    void show(std::string label) const;

    void show(std::string label, float scalar);

    void show();

    Vec3D min();

    Vec3D add(Vec3D const &other);

    Vec3D sub(Vec3D const &other) const;

    Vec3D mul(float scalar);

    Vec3D div(float scalar);

    float norm();

    Vec3D unit();

    float dot(Vec3D const &other) const;

    Vec3D cross(Vec3D const &other);
};
#endif