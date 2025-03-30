#include "render.h"

Bitmap::Bitmap(const int width, const int height) : width(width), height(height), colors(new color[width * height]) {}

Bitmap::~Bitmap() {
	delete(colors);
}

Camera::Camera(const vec3 position, const vec3 direction, const float fov, const float blur) : position(position), direction(direction), fov(fov), blur(blur){}

RenderParameters::RenderParameters(const int w, const int h, const int numBounces, const int numIterations) : screenWidth(w), screenHeight(h), numberBounces(numBounces), numberIterations(numIterations){}

Bitmap render(const std::vector<triangle>& triangles, const Camera& camera, const RenderParameters& parameters) {
	for (int p = 0; p < parameters.numberIterations; p++) {
		initializeRays(camera.fov, camera.blur);
		cycleRaysVector(parameters.numberBounces, triangles);
	}

	return Bitmap(512, 512);
}