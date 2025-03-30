#include <cmath>
#include <random>
#include <cmath>
#include "vectors.h"

float vec3::magnitude() const{
	return sqrtf(x * x + y * y + z * z);
}

vec3 vec3::normalize() {
	const float scl = this->magnitude();

	x /= scl;
	y /= scl;
	z /= scl;

	return *this;
}

vec3 vec3::operator+(const vec3& v2) const {
	return vec3(x + v2.x, y + v2.y, z + v2.z);
}

vec3 vec3::operator-(const vec3& v2) const {
	return vec3(x - v2.x, y - v2.y, z - v2.z);
}

vec3 vec3::operator*(const float f) const {
	return vec3(x * f, y * f, z * f);
}

vec3 vec3::operator/(const float f) const {
	return vec3(x / f, y / f, z / f);
}

void vec3::operator+=(const vec3& v2) {
	x += v2.x;
	y += v2.y;
	z += v2.z;
}

void vec3::operator-=(const vec3& v2) {
	x -= v2.x;
	y -= v2.y;
	z -= v2.z;
}

void vec3::operator*=(const float f) {
	x *= f;
	y *= f;
	z *= f;
}

void vec3::operator/=(const float f) {
	x /= f;
	y /= f;
	z /= f;
}

bool vec3::operator==(const vec3& v2) {
	return x == v2.x && y == v2.y && z == v2.z;
}

float dot(const vec3& v1, const vec3& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

#define matrix2D_eval(float_a , float_b, float_c, float_d) (float_a*float_d - float_b*float_c)

vec3 cross(const vec3& v1, const vec3& v2) {
	return vec3(matrix2D_eval(v1.y, v1.z, v2.y, v2.z), matrix2D_eval(v1.x, v1.z, v2.x, v2.z), matrix2D_eval(v1.x, v1.y, v2.x, v2.y));
}

void vec3::reflect(const vec3& normalVector) {

	// remove 2x dot
	 this->operator-=(normalVector * 2 * dot(*this, normalVector));

	 // invert
	 this->operator*(-1);
}

vec3 generateRandomPointSphere() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> angleDist(0.0f, 2.0f * 3.14159265f); // Azimuthal angle
	std::uniform_real_distribution<float> cosThetaDist(-1.0f, 1.0f);    // Cosine of polar angle

	// Randomly sample spherical coordinates
	float cosTheta = cosThetaDist(gen); // Cosine of polar angle
	float sinTheta = std::sqrt(1.0f - cosTheta * cosTheta); // Sine of polar angle
	float phi = angleDist(gen); // Azimuthal angle

	// Convert spherical coordinates to Cartesian coordinates
	float x = sinTheta * std::cos(phi);
	float y = sinTheta * std::sin(phi);
	float z = cosTheta;

	// Return the point shifted by the center
	return vec3(x, y, z);
}

void vec3::print() {
	printf("%f %f %f\n", x, y, z);
}