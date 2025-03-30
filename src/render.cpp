#include "render.h"

Bitmap::Bitmap(const int width, const int height) : width(width), height(height) {}

Bitmap::~Bitmap() {
	delete(colors);
}

Camera::Camera(const vec3 position, const vec3 direction, const float fov, const float blur) : position(position), direction(direction), fov(fov), blur(blur){}

RenderParameters::RenderParameters(const int w, const int h, const int numBounces, const int numIterations) : screenWidth(w), screenHeight(h), numberBounces(numBounces), numberIterations(numIterations){}

Bitmap render(const std::vector<triangle>& triangles, const Camera& camera, const RenderParameters& parameters) {
	initImg(parameters.screenWidth, parameters.screenHeight);
	initializeRays(camera.fov, camera.blur);
	
	for (int p = 0; p < parameters.numberIterations; p++) {
		// set rays to original positions
		resetRayBounces(camera.fov, camera.blur);
		resetRayPositions(camera.fov, camera.blur);

		cycleRaysVector(parameters.numberBounces, triangles);

		for (int x = 0; x < parameters.screenWidth; x++) {
			for (int y = 0; y < parameters.screenHeight; y++) {
				addToImageBuffer(rays[x + y * parameters.screenWidth].c, x, y);
			}
		}
	}

	for (int x = 0; x < parameters.screenWidth; x++) {
		for (int y = 0; y < parameters.screenHeight; y++) {
			if (rays[x + y * parameters.screenWidth].numBounces == 0) {
				writeToImageBuffer(color(0, 0, 0), x, y);
				continue;
			}
			scaleImageBuffer(1.0f/parameters.numberIterations, x, y);
		}
	}

	Bitmap returnBitmap = Bitmap(parameters.screenWidth, parameters.screenHeight);

	returnBitmap.colors = displayBuffer;

	return returnBitmap;
}