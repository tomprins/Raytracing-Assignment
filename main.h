#ifndef MAIN_H
#define MAIN_H
#pragma once

using namespace std;

// define the core template sizes for the chessboard
#define nrOfScreenRowPixels 80
#define nrOfScreenColumnPixels 130
#define nrOfScreenLevels 16
// #define screenWidth 80
// #define screenHeight 40
#define screenWidth 84
#define screenHeight 44

// float PixelWidth = 0.00126;
float PixelWidth = 0.00180;
float PixelHeight = 0.00265;

float ThousandPixelWidth = PixelWidth * 1000;
float ThousandPixelHeight = PixelHeight * 1000;

// declaring parameters for the chessboard
float midX;
float midY;

char charactersOnBrightness[nrOfScreenLevels] = {' ', '.', '^', ';', 'i', '+', '1', 't', 'x', 'X', 'Q', 'w', 'b', '&', 'B', '@'};

int columnsCounter = 0;
int rowCounter = 0;
int squareSize = 4;
float XsquareSize = PixelWidth * squareSize;
float YsquareSize = PixelHeight * squareSize;

int defaultColumnIndex = 0;

#endif
