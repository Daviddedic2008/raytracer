#include "screen.h"
#include "C:\Users\david\OneDrive\Documents\raytracerFinishedCPU\tracer\fileIO\writeToBMP.h"

int scrWidth, scrHeight;

color* displayBuffer;

void initImg(const int width, const int height) {
	scrWidth = width;
	scrHeight = height;
	displayBuffer = new color[width * height];
}

void writeToImageBuffer(const color c, const int px, const int py) {
	displayBuffer[px + py * scrWidth] = c;
}

color readFromImageBuffer(const int px, const int py) {
	return displayBuffer[px + py * scrWidth];
}

void flipBufferToBMP() {
	saveBMP("outImg.bmp", scrWidth, scrHeight, displayBuffer);
}