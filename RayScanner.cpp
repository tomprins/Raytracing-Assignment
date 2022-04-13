// Define and include the needed libraries, vectors and headers
#include <iostream>
#include "RayScanner.h"
#include <string>
#include <math.h>
#include "Ray.h"

RayScanner::RayScanner(VPO O) : objects(O) {}

// Method for shooting a ray, through every pixel of the screen
void RayScanner::scan(float screenWidthInMeters, float screenHeightInMeters, float PixelHeight, float PixelWidth, float midX, float XsquareSize, float YsquareSize)
{
    float Height = screenHeightInMeters * 10000;
    int intHeight = (int)Height;
    int intWidth = screenWidthInMeters * 10000;

    char screen[intHeight][intWidth];

    // The for loop for the height of the screen
    for (float rowIndex = 0; rowIndex < screenHeightInMeters; rowIndex += PixelHeight)
    {
        float floatCoordinateY = (rowIndex * 10000);
        int coordinateY = ((int)floatCoordinateY);

        // The for loop for the width of the screen
        for (float columnIndex = 0; columnIndex < screenWidthInMeters; columnIndex += PixelWidth)
        {
            float floatCoordinateX = columnIndex * 10000;
            int coordinateX = ((int)floatCoordinateX);

            float pixelX = (PixelWidth * columnIndex * 1000) - (screenWidthInMeters / 2);
            float pixelY = (PixelHeight * rowIndex * 1000);

            // Declare the ray, with the appropiate X and Y values;
            Ray *ray = new Ray(pixelX, pixelY);

            // Shoot the ray to every object
            for (int i = 0; i < objects.size(); i++)
            {
                if (objects[i]->getName() == "Sphere")
                {
                    // If the ray hits the objects, print '@'
                    if (objects[i]->hit(*ray, midX, XsquareSize, YsquareSize) == true)
                    {
                        screen[coordinateY][coordinateX] = '@';
                    }
                }
                else
                {
                    // If the ray hits the objects, print '@'
                    if (objects[i]->hit(*ray, midX, XsquareSize, YsquareSize) == true && ray->direction.y > 0.17)
                    {
                        screen[coordinateY][coordinateX] = '@';
                    }
                }
            }
        }
    }

    // Print the screen
    for (float rowIndex = 0; rowIndex < screenHeightInMeters; rowIndex += PixelHeight)
    {
        float floatCoordinateY = (rowIndex * 10000);
        int coordinateY = ((int)floatCoordinateY);

        for (float columnIndex = 0; columnIndex < screenWidthInMeters; columnIndex += PixelWidth)
        {
            float floatCoordinateX = columnIndex * 10000;
            int coordinateX = ((int)floatCoordinateX);

            printf("%c", screen[coordinateY][coordinateX]);
        }
        printf("\n");
    }
}

std::vector<float> RayScanner::pixelsToMeter(int Columns, int Rows, float PixelHeight, float PixelWidth)
{
    // Convert the screen from pixels to meters, with the width and height of a single pixel, and the number of rows and columns
    float WidthInMeters = Columns * (PixelWidth * 1000);
    float HeightInMeters = Rows * (PixelHeight * 1000);

    WidthInMeters = WidthInMeters / 1000;
    HeightInMeters = HeightInMeters / 1000;

    std::vector<float> v;
    v.push_back(WidthInMeters);
    v.push_back(HeightInMeters);

    return v;
};