// Define and include the needed libraries, vectors and headers
#define VPO std::vector<Object *>
#include <iostream>
#include "main.h"
#include "Vec3D.h"
#include "Object.h"
#include "Ray.h"
#include "Sphere.h"
#include "Floor.h"
#include "RayScanner.h"

int main()
{
    // Declaring the floor and Sphere's
    Sphere one = Sphere(-0.3, 1.0, -6, 0.2);
    Sphere two = Sphere(0.6, 1.2, -6, 0.2);
    Sphere three = Sphere(1.6, 1.0, -6, 0.2);
    Floor floor = Floor(0, -0.04, 0);

    // Store the Objects in the vector
    VPO objects(4);
    objects[0] = &floor;
    objects[1] = &one;
    objects[2] = &two;
    objects[3] = &three;

    // Convert the screen from pixels to meters
    RayScanner RS = RayScanner(objects);
    std::vector<float> v = RS.pixelsToMeter(screenWidth, screenHeight, PixelHeight, PixelWidth);
    float ScreenWidthInMeters = v.at(0);
    float ScreenHeightInMeters = v.at(1);

    float midX = ScreenWidthInMeters / 2;
    float midY = -ScreenHeightInMeters / 2;

    RS.scan(ScreenWidthInMeters, ScreenHeightInMeters, PixelHeight, PixelWidth, midX, XsquareSize, YsquareSize);

    return 0;
}