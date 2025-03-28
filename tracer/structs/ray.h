#include "vectors.h"
#include "color.h"
#include "shapes.h"
#include "math.h"

struct ray {
	vec3 origin, direction;
	color c = color(1, 1, 1);

	ray(const vec3 o, const vec3 d) : c(color(0, 0, 0)), origin(o), direction(d) {}

	ray(const vec3 o, const float fov, const float blurStrength);

	vec3 intersectingTriangle(triangle t) const;

	void reflectOnTriangle(const triangle t);

	bool attemptFullTrace(const triangle t);
};