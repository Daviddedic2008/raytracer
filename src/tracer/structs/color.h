#pragma once

struct color {
	float r, g, b;

	color() : r(0), g(0), b(0){}

	color(const float r, const float g, const float b) : r(r), g(g), b(b){}
	
	color operator*(const color c) const;
	color operator+(const color c) const;
	color operator/(const color c) const;
	color operator-(const color c) const;
	void operator*=(const color c);
	void operator*=(const float scl);
	void operator+=(const color c);
	void operator/=(const color c);
	void operator-=(const color c);
};