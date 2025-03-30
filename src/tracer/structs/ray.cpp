#include "ray.h"
#include "utils/rng.h"
#include <random>

ray::ray(const vec3 o, const float fov, const float blurStrength) : origin(o), numBounces(0), maxBrightness(0.0f) {
    direction = o * fov + vec3(randFloat(), randFloat(), 0.0f) * blurStrength + vec3(0,0,1);
}

void ray::returnToOrigin(const vec3 o, const float fov, const float blurStrength) {
    direction = o * fov + vec3(randFloat(), randFloat(), 0.0f) * blurStrength + vec3(0, 0, 1);
    origin = o;
}

vec3 ray::intersectingTriangle(triangle t) const{
    
    const float directionDotNormal = dot(direction, t.normalVector);
    if (fabs(directionDotNormal) < 1e-8) {
        return vec3(0, 0, 0);
    }

    const float d = dot(t.normalVector, t.p1);
    const float tDistance = (dot(t.normalVector, origin) + d) / directionDotNormal;

    const vec3 intersectionPoint = origin + direction * tDistance;
    if (dot(intersectionPoint, direction) <= 1e-8) {
        return vec3(0, 0, 0);
    }

    return t.pointInTriangle(intersectionPoint) ? intersectionPoint : vec3(0, 0, 0);
}

void ray::reflectOnTriangle(const triangle t, float randomContribution) {
    const float dtnv = dot(t.normalVector, direction);

    const vec3 nv = (dtnv > 0.0f) ? (t.normalVector * -1) : t.normalVector;
    direction.reflect(nv);

    direction *= (1 - randomContribution);

    const vec3 rnd = generateRandomPointSphere();
    direction += rnd * randomContribution;

    const float dt2 = dot(t.normalVector, direction);

    if (dt2 > 0.0f) {
        direction *= -1;
    }
}

bool ray::attemptFullTrace(const triangle t) {
    const vec3 intersect = this->intersectingTriangle(t);

    if (intersect == vec3(0, 0, 0)) {
        return false;
    }

    origin = intersect;
    reflectOnTriangle(t, t.roughness);
    c *= t.c;
    maxBrightness = (maxBrightness < t.brightness) ? t.brightness : maxBrightness;
    numBounces++;
    return true;
}