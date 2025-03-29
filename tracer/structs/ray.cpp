#include "ray.h"
#include "utils/rng.h"
#include <random>

ray::ray(const vec3 o, const float fov, const float blurStrength) : origin(o) {
    direction = o * fov + vec3(randFloat(), randFloat(), 0.0f) * blurStrength;
}

vec3 ray::intersectingTriangle(triangle t) const{
    
    const float directionDotNormal = dot(direction, t.normalVector);

    if (fabs(directionDotNormal) < 1e-8) {
        return vec3(0, 0, 0);
    }

    const float d = dot(t.normalVector, t.p1);
    const float tDistance = (dot(t.normalVector, origin) + d) / directionDotNormal;

    if (fabs(tDistance) < 1e-8) {
        return vec3(0, 0, 0);
    }

    const vec3 intersectionPoint = origin + direction * tDistance;

    return t.pointInTriangle(intersectionPoint) ? intersectionPoint : vec3(0, 0, 0);
}

void ray::reflectOnTriangle(const triangle t) {
    direction.reflect(t.normalVector);
}

bool ray::attemptFullTrace(const triangle t) {
    const vec3 intersect = this->intersectingTriangle(t);

    if (intersect == vec3(0, 0, 0)) {
        return false;
    }

    this->origin = intersect;
    this->reflectOnTriangle(t);
    this->c *= t.c;
    return true;
}