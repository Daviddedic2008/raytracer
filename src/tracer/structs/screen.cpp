#include "screen.h"
#include "../fileIO/writeToBMP.h"

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

void addToImageBuffer(const color c, const int px, const int py) {
	displayBuffer[px + py * scrWidth] += c;
}

void scaleImageBuffer(const float scl, const int px, const int py) {
	displayBuffer[px + py * scrWidth] *= scl;
}

color readFromImageBuffer(const int px, const int py) {
	return displayBuffer[px + py * scrWidth];
}

void flipBufferToBMP() {
	saveBMP("C:\\Users\\david\\OneDrive\\Documents\\raytracerFinishedCPU\\src\\tracer\\fileIO\\outImg.bmp", scrWidth, scrHeight, displayBuffer);
}