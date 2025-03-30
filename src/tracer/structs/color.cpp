#include "color.h"

color color::operator*(const color c) const {
	return color(r * c.r, g * c.g, b * c.b);
}

color color::operator+(const color c) const {
	return color(r + c.r, g + c.g, b + c.b);
}

color color::operator/(const color c) const {
	return color(r / c.r, g / c.g, b / c.b);
}

color color::operator-(const color c) const {
	return color(r - c.r, g - c.g, b - c.b);
}

void color::operator*=(const color c) {
	r *= c.r;
	g *= c.g;
	b *= c.b;
}

void color::operator*=(const float scl) {
	r *= scl;
	g *= scl;
	b *= scl;
}

void color::operator+=(const color c) {
	r += c.r;
	g += c.g;
	b += c.b;
}

void color::operator/=(const color c) {
	r /= c.r;
	g /= c.g;
	b /= c.b;
}

void color::operator-=(const color c) {
	r -= c.r;
	g -= c.g;
	b -= c.b;
}