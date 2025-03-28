#pragma once
#include "color.h"

extern int scrWidth, scrHeight;

extern color* displayBuffer;

void initImg(const int width, const int height);

void writeToImageBuffer(const color c, const int px, const int py);

color readFromImageBuffer(const int px, const int py);

void flipBufferToBMP();