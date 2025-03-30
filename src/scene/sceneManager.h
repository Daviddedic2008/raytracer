#pragma once

#include "../tracer/structs/shapes.h"
#include "../tracer/structs/ray.h"
#include "../tracer/structs/color.h"

void initializeRays(const float fov, const float blurStrength);

void cycleRays(const int bounceLimit);

void cycleRaysVector(const int bounceLimit, const std::vector<triangle>& triangleVector);

void writeResultToBuffer();

void addTriangle(const triangle& t);

void addFacet(const vec3& corner1, const vec3& corner2, const vec3& normal, const color& c, const float brightness, const float roughness);

void addRectangularPrism(const vec3& corner1, const vec3& corner2, const color& c, const float brightness, const float roughness);

extern ray* rays;

extern int bounceLimit;