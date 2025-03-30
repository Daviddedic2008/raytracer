#include "sceneManager.h"
#include <list>

ray* rays;

std::list<triangle> triangles;

#include "../tracer/structs/screen.h"

int numTriangles = 0;


void initializeRays(const float fov, const float blurStrength) {
	rays = new ray[scrHeight * scrWidth];

	for (int x = scrWidth / -2; x < scrWidth / 2; x++) {
		for (int y = scrHeight / -2; y < scrHeight / 2; y++) {
			rays[x + y * scrWidth] = ray(vec3(x, y, 0), fov, blurStrength);
		}
	}
}

void cycleRays(const int bounceLimit) {
	for (int r = 0; r < scrWidth * scrHeight; r++) {
		for (int b = 0; b < bounceLimit; b++) {
			for (auto t = triangles.begin(); t != triangles.end(); t++) {
				rays[r].attemptFullTrace(*t);
			}
		}
	}
}

void cycleRaysVector(const int bounceLimit, const std::vector<triangle>& triangleVector) {
	for (int r = 0; r < scrWidth * scrHeight; r++) {
		for (int b = 0; b < bounceLimit; b++) {
			for (auto t = triangleVector.begin(); t != triangleVector.end(); t++) {
				rays[r].attemptFullTrace(*t);
			}
		}
	}
}

void writeResultToBuffer() {
	;
}

void addTriangle(const triangle& t) {
	triangles.push_back(t);
}

void addFacet(const vec3& corner1, const vec3& corner2, const vec3& normal, const color& c, const float brightness, const float roughness) {
	const vec3 diagonal = corner2 - corner1;
	const vec3 midpoint = corner1 + diagonal * 0.5f;
	const vec3 perependicular = (cross(diagonal , normal)).normalize();

	const vec3 halfOfWidth = perependicular * 0.5f * diagonal.magnitude();

	const vec3 corner3 = midpoint + halfOfWidth;
	const vec3 corner4 = midpoint - halfOfWidth;

	addTriangle(triangle(corner1, corner2, corner3, c.r, c.g, c.b, brightness, roughness));

	addTriangle(triangle(corner1, corner2, corner4, c.r, c.g, c.b, brightness, roughness));
}

void addRectangularPrism(const vec3& corner1, const vec3& corner2, const color& c, const float brightness, const float roughness) {
	const vec3 center = (corner2 + corner1) * 0.5f;

	const vec3 midpoint = corner2 - corner1;

	const vec3 halfDiagonal = midpoint * 0.5f;

	const vec3 edgeX = vec3(halfDiagonal.x, 0, 0);
	const vec3 edgeY = vec3(0, halfDiagonal.y, 0);
	const vec3 edgeZ = vec3(0, 0, halfDiagonal.z);

	vec3 vertex1 = center + edgeX + edgeY + edgeZ;
	vec3 vertex2 = center + edgeX + edgeY - edgeZ;
	vec3 vertex3 = center + edgeX - edgeY + edgeZ;
	vec3 vertex4 = center + edgeX - edgeY - edgeZ;
	vec3 vertex5 = center - edgeX + edgeY + edgeZ;
	vec3 vertex6 = center - edgeX + edgeY - edgeZ;
	vec3 vertex7 = center - edgeX - edgeY + edgeZ;
	vec3 vertex8 = center - edgeX - edgeY - edgeZ;
	
	addTriangle(triangle(vertex1, vertex2, vertex3, c.r, c.g, c.b, brightness, roughness));
	addTriangle(triangle(vertex1, vertex3, vertex4, c.r, c.g, c.b, brightness, roughness));

	addTriangle(triangle(vertex5, vertex6, vertex7, c.r, c.g, c.b, brightness, roughness));
	addTriangle(triangle(vertex5, vertex7, vertex8, c.r, c.g, c.b, brightness, roughness));

	addTriangle(triangle(vertex1, vertex4, vertex8, c.r, c.g, c.b, brightness, roughness));
	addTriangle(triangle(vertex1, vertex8, vertex5, c.r, c.g, c.b, brightness, roughness));

	addTriangle(triangle(vertex2, vertex3, vertex7, c.r, c.g, c.b, brightness, roughness));
	addTriangle(triangle(vertex2, vertex7, vertex6, c.r, c.g, c.b, brightness, roughness));

	addTriangle(triangle(vertex1, vertex2, vertex6, c.r, c.g, c.b, brightness, roughness));
	addTriangle(triangle(vertex1, vertex6, vertex5, c.r, c.g, c.b, brightness, roughness));

	addTriangle(triangle(vertex4, vertex3, vertex7, c.r, c.g, c.b, brightness, roughness));
	addTriangle(triangle(vertex4, vertex7, vertex8, c.r, c.g, c.b, brightness, roughness));
}