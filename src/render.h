#pragma once
#include <vector>
#include "../src/scene/sceneManager.h"

struct Bitmap {
	color* colors;
	int width, height;

	Bitmap(const int width, const int height);

	~Bitmap();
};

struct Camera {
	vec3 position, direction;

	float fov, blur;

	Camera(const vec3 position, const vec3 direction, const float fov, const float blur);
};

struct RenderParameters {
	int screenWidth, screenHeight, numberBounces, numberIterations;

	RenderParameters(const int w, const int h, const int numBounces, const int numIterations);
};

// Given an array of triangles, this function returns a bitmap of their render
Bitmap render(const std::vector<triangle>& triangles, const Camera& camera, const RenderParameters& parameters);