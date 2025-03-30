#pragma once

#include "vectors.h"
#include "color.h"
#include "shapes.h"
#include "math.h"

struct ray {
	vec3 origin, direction;
	color c = color(1, 1, 1);

	int numBounces;

	float maxBrightness;

	ray(const vec3 o, const vec3 d) : c(color(0, 0, 0)), origin(o), direction(d), numBounces(0), maxBrightness(0.0f) {}

	ray(const vec3 o, const float fov, const float blurStrength);

	ray(){}

	vec3 intersectingTriangle(triangle t) const;

	void reflectOnTriangle(const triangle t, float randomContribution);

	bool attemptFullTrace(const triangle t);
};