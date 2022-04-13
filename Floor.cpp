#include <iostream>
#include "Floor.h"
#include <string>
//#include "main.h"
 
    Floor::Floor(float x, float y, float z) : Object(x, y, z) {}

    bool Floor::hit(Ray &ray, float midX, float XsquareSize, float YsquareSize)
    {
        // Calculate the multiplier that is needed to calculate where the Ray, intersects the Floor.
        float multiplier = (center.y - ray.support.y) / ray.direction.y;

        // ray.direction.z is constant
        float determineRow = ((ray.direction.z * multiplier)) / YsquareSize;
        int rowSquare = (int)determineRow;
        // std::cout << rowSquare << "\n";

        float determineColumn = ((ray.direction.x * multiplier) + midX) / XsquareSize;
        int columnSquare = (int)determineColumn;

        // row begins with white square
        if (determineColumn > 0)
        {
            if (rowSquare % 2 == 0)
            {
                if (columnSquare % 2 == 0)
                    return true;
                else
                    return false;
            }
            // row begins with black square
            else
            {
                if (columnSquare % 2 == 0)
                    return false;
                else
                    return true;
            }
        }
        else
        {
            if ((rowSquare % 2 == 0))
            {
                if (columnSquare % 2 == 0)
                    return false;
                else
                    return true;
            }
            // row begins with black square
            else
            {
                if ((columnSquare % 2 == 0))
                    return true;
                else
                    return false;
            }
        }
    }

     std::string Floor::getName() { return "Floor"; }