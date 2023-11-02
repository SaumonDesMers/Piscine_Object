#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>

#include "shape.hpp"

class Triangle: public Shape {

public:

	Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
		_vertices[0] = vec2(x1, y1);
		_vertices[1] = vec2(x2, y2);
		_vertices[2] = vec2(x3, y3);
	}

	float area() const {
		float area = _vertices[0].x * (_vertices[1].y - _vertices[2].y)
					+ _vertices[1].x * (_vertices[2].y - _vertices[0].y)
					+ _vertices[2].x * (_vertices[0].y - _vertices[1].y);
		return std::abs(area / 2);
	}

	float perimeter() const {
		float perimeter = 0;
		for (size_t i = 0; i < 3; i++)
			perimeter += std::sqrt(
				  std::pow(_vertices[i].x - _vertices[(i + 1) % 3].x, 2)
				+ std::pow(_vertices[i].y - _vertices[(i + 1) % 3].y, 2)
			);
		return perimeter;
	}

private:

	vec2 _vertices[3];

};

#endif // TRIANGLE_HPP