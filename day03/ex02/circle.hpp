#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>

#include "shape.hpp"

class Circle: public Shape {

public:

	Circle(float radius): _radius(radius) {}

	float area() const {
		return _radius * _radius * M_PI;
	}

	float perimeter() const {
		return 2 * _radius * M_PI;
	}

private:

	float _radius;

};

#endif // CIRCLE_HPP