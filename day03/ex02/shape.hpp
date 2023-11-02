#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <vector>
#include <cmath>

struct vec2 {
	float x;
	float y;

	vec2(float x = 0, float y = 0): x(x), y(y) {}
};

class Shape {

public:
	
	void addVertex(float x, float y) {
		_vertices.push_back(vec2(x, y));
	}

	virtual float area() const {
		float area = 0;
		for (size_t i = 0; i < _vertices.size(); i++)
			area += (_vertices[i].x * _vertices[(i + 1) % _vertices.size()].y) - (_vertices[i].y * _vertices[(i + 1) % _vertices.size()].x);
		return std::abs(area / 2);
	}

	virtual float perimeter() const {
		float perimeter = 0;
		for (size_t i = 0; i < _vertices.size(); i++)
			perimeter += std::sqrt(
				  std::pow(_vertices[i].x - _vertices[(i + 1) % _vertices.size()].x, 2)
				+ std::pow(_vertices[i].y - _vertices[(i + 1) % _vertices.size()].y, 2)
			);
		return perimeter;
	}

private:
	
	std::vector<vec2> _vertices;

};

#endif // SHAPE_HPP