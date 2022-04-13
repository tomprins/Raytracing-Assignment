#ifndef RAYSCANNER_H
#define RAYSCANNER_H
#pragma once

#include <vector>
#include "Object.h"
#define VPO std::vector<Object *>


class RayScanner
{
public:
    RayScanner(VPO O);
    VPO objects;

    void scan(float screenWidthInMeters, float screenHeightInMeters, float PixelHeight, float PixelWidth, float midX, float XsquareSize, float YsquareSize);

    std::vector<float> pixelsToMeter(int Columns, int Rows, float PixelHeight, float PixelWidth);
};
#endif