#include <iostream>
#include "Ray.h"

    // Constructor for the Ray, support is here the point from where the rays are sent, in scherm are coordinates stored, where it intersects the screen where the image is printed from.
    // direction is the direction that the ray takes from the support, this is calculated with scherm and support.
    Ray::Ray(float xStart, float yStart) : support(0, 0, 0.6), scherm(xStart, yStart, 0), direction(0, 0, 0) { direction = scherm.sub(support); }