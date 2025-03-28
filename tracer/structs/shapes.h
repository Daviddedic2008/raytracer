#pragma once

#include "shapes.h"

#include "vectors.h"

#include "color.h"

struct triangle {
    vec3 p1, p2, p3;
    vec3 normalVector;
    float brightness, roughness;
    color c;

    triangle(vec3 p1, vec3 p2, vec3 p3, float r, float g, float b, float br, float rough);

    bool pointInTriangle(const vec3 point) const;
};