#include "shapes.h"

triangle::triangle(vec3 p1, vec3 p2, vec3 p3, float r, float g, float b, float br, float rough)
    : p1(p1), p2(p2), p3(p3), brightness(br), roughness(rough), c(color(r, g, b)) {
    normalVector = cross(p1 - p2, p1 - p3);
    normalVector.normalize();
}

bool triangle::pointInTriangle(const vec3 point) const {
    const vec3 p1p2 = p2 - p1;
    const vec3 p1p3 = p3 - p1;
    const vec3 p1Point = point - p1;

    const float dot00 = dot(p1p3, p1p3);
    const float dot01 = dot(p1p3, p1p2);
    const float dot02 = dot(p1p3, p1Point);
    const float dot11 = dot(p1p2, p1p2);
    const float dot12 = dot(p1p2, p1Point);

    const float denom = dot00 * dot11 - dot01 * dot01;
    if (denom == 0.0f) return false;
    const float invDenom = 1.0f / denom;
    const float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    const float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    return (u >= 0.0f) && (v >= 0.0f) && (u + v <= 1.0f);
}