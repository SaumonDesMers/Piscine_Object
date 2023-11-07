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
		for (size_t i = 0; i < _vertices.size(); i++) {
			vec2 const & v1 = _vertices[i];
			vec2 const & v2 = _vertices[(i + 1) % _vertices.size()];
			area += v1.x * v2.y - v1.y * v2.x;
		}
		return std::abs(area / 2);
	}

	virtual float perimeter() const {
		float perimeter = 0;
		for (size_t i = 0; i < _vertices.size(); i++) {
			vec2 const & v1 = _vertices[i];
			vec2 const & v2 = _vertices[(i + 1) % _vertices.size()];
			perimeter += std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2));
		}
		return perimeter;
	}

private:
	
	std::vector<vec2> _vertices;

};

#endif // SHAPE_HPP