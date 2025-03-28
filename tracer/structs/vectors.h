#pragma once

#include <random>

struct vec3 {
	float x, y, z;

	vec3() : x(0), y(0), z(0) {}

	vec3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

	float magnitude() const;

	void normalize();

	vec3 operator+(const vec3& v2) const;
	vec3 operator-(const vec3& v2) const;
	vec3 operator*(const float f) const;
	vec3 operator/(const float f) const;
	void operator+=(const vec3& v2);
	void operator-=(const vec3& v2);
	void operator*=(const float f);
	void operator/=(const float f);
	bool operator==(const vec3& v2);

	void reflect(const vec3& normalVector);
};

float dot(const vec3& v1, const vec3& v2);

vec3 cross(const vec3& v1, const vec3& v2);

vec3 generateRandomPointSphere(const vec3 center, const float radius);