#include <iostream>
#include "Vec3D.h"
#include <math.h>
#include <vector>
#include <string>

// Constructor for a vector, that implements a x, y and z length.
Vec3D ::Vec3D(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3D ::Vec3D() {}

// Multiple functions that manipulate or print a vector.
void Vec3D ::show(std::string label) const { std::cout << label << "X:" << x << ", Y:" << y << ", Z:" << z << '\n'; }

void Vec3D ::show(std::string label, float scalar) { std::cout << label << "Scalar: " << scalar << '\n'; }

void Vec3D ::show() { std::cout << '\n'; }

Vec3D Vec3D::min() { return Vec3D(x * -1, y * -1, z * -1); }

Vec3D Vec3D::add(Vec3D const &other) { return Vec3D(x + other.x, y + other.y, z + other.z); }

Vec3D Vec3D::sub(Vec3D const &other) const { return Vec3D(x - other.x, y - other.y, z - other.z); }

Vec3D Vec3D::mul(float scalar) { return Vec3D(x * scalar, y * scalar, z * scalar); }

Vec3D Vec3D::div(float scalar) { return Vec3D(x / scalar, y / scalar, z / scalar); }

float Vec3D ::norm() { return float(sqrt(x * x + y * y + z * z)); }

Vec3D Vec3D::unit()
{
    float length = norm();
    return Vec3D(x / length, y / length, z / length);
}

float Vec3D ::dot(Vec3D const &other) const { return float(x * other.x + y * other.y + z * other.z); }

Vec3D Vec3D::cross(Vec3D const &other) { return Vec3D((y * other.z - z * other.y), (z * other.x - x * other.z), (x * other.y - y * other.x)); }
